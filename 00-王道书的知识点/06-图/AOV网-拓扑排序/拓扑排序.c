#define maxSize 100  // 图中顶点数目的最大值
#define DEFAULT 9999  // 存储结果的数组的元素默认值
typedef int VexType;
typedef struct ArcNode {  // 边表结点
    int index;  // 该弧所指向的顶点的位置
    struct ArcNode *next;  // 指向下一条弧的指针
    /*InfoType info*/ // 网的边权值
} ArcNode;
typedef struct VexNode {  // 顶点表结点
    VexType data;  // 顶点信息
    ArcNode *first;  // 指向第一条依附该顶点的弧的指针
} VexNode;  
typedef struct {
    VexNode vertex[maxSize];  // 邻接表
    int vexnum, arcnum;  // 图的顶点数和弧数
    int indegree[maxSize];
} Graph;  // Graph是以邻接表存储的图的类型

int print[maxSize];  // 存放拓扑排序结果的数组（全局变量）

bool topologicalSort(Graph G) {
    Stack S;
    InitStack(S);  // 初始化栈，存储入度为0的顶点
    for (int i = 0; i < G.vexnum; i++) {
        print[i] = DEFAULT;
        if (G.indegree[i] == 0) {
            Push(S, i);  // 将所有入度为0的顶点进栈
        }
    }
    int count = 0;  // 计数，记录当前已经输出的顶点数
    while (!StackEmpty(S)) {  // 栈不空，则存在入度为0的顶点
        int i;
        Pop(S, i);  // 栈顶元素出栈
        print[count++] = i;  // 输出顶点i
        for (ArcNode *p = G.vertex[i].first; p != NULL; p = p->next) {
            // 将所有i指向的顶点的入度减1，并且将入度减为0的顶点压入栈S
            int v = p->index;
            G.indegree[v]--;
            if (G.indegree[v] == 0) {
                Push(S, v);  // 入度为0，则入栈
            }
        }
    }  // while
    return count >= G.vexnum;  
	// 如果count>=顶点数，表示排序成功，返回true。否则返回false
    //实际上这里count不可能严格大于顶点数，只可能存在相等或者小于的情况
}

