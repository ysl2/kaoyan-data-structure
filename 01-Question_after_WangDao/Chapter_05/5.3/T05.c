#define maxSize 100
typedef char VexType;
typedef struct ArcNode {
    int index;  // 这里指向的是竖向的下标，所以是int类型
    struct ArcNode *next;
} ArcNode;
typedef struct VexNode {
    VexType data;  // 这里存的是竖向的结点信息，而不是下标值（与上面区分开）
    ArcNode *first;
} VexNode;
typedef struct {
    VexNode *vertex;  // 这里加了*号，因为将来会是一个数组（动态分配）
    int arcnum, vexnum;
} *AdjacentGraph;

AdjacentGraph G;
bool visited[maxSize];
int path[maxSize];

void outPut(int *path, int distance) {
    for (int i = 0; i <= distance; i++) {
        printf("%d ", path[i]);
    }
}

// 这个是我改过之后的
// 基于递归的深度优先遍历，输出从a到b的简单路径
void findPath(AdjacentGraph &G, int a, int b, int distance) {
    path[++distance] = a;  // distance初值为-1
	// 由于distance以形参方式做值传递，
	// 因此在每个递归层中，distance的值互不影响
	// 当执行结束一层递归时，在弹栈过程中就相当于distance自减了
    visited[a] = true;
    if (a == b) {  // 如果成功找到一条路径，则输出，然后接着找另一条
        outPut(path, distance);
    }
    for (ArcNode *w = (G->vertex[a]).first; w != NULL; w = w->next) {
        if (!visited[w->index]) {  // 若顶点w未访问，递归访问它
            findPath(G, w->index, b, distance);
        }
    }
    visited[a] = false;  // 恢复环境，使该顶点重新可用
}


// ----------------------------------------------------------------------
//基于递归的深度优先遍历
void findPath(AdjacentGraph &G, int u, int v, int path[], int d) {
    int w, i;
    ArcNode *p;
    d++;
    path[d] = u;
    visited[u] = 1;
    if (u == v) {
        outPut(path[]);
    }
    p = G->adjList[u].firstarc;
    while (p != NULL) {
        w = p->adjvex;
        if (visited[w] == 0) {
            findPath(G, w, v, path, d);
            p = p->nextarc;
        }
    }
    visited[u] = 0;
}
