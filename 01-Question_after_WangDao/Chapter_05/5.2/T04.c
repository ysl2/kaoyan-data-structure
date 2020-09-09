//邻接表的结构体定义：
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
// 如果这里没有加*号，那么下面的应该是G.vexnum
// 如果这里加了*号，那么下面的应该是G->vexnum

AdjacentGraph G;  // 定义全局变量。如果不写这一句，下面的形参&会报错

//转换
int **converse(AdjacentGraph &G) {
	// 采用动态方式申请数组a。静态申请也可以。
	// 2020-09-04：动态申请有问题。只会开辟空间，但是memset函数未执行
	// 因此改用静态申请。下面这句是动态申请，划掉。
    //int a[][] = createMatrix(G->vexnum, G->vexnum);
	int a[G->vexnum][G->vexnum];
    memset(a, 0, sizeof(int) * G->vexnum * G->vexnum);  // 把整个二维数组置0
    for (int i = 0; i < G.vexnum; i++) {
        for (ArcNode *w = (G->vertex[i]).first; w != NULL; w = w->next) {
            a[i][w->index] = 1;
        }
    }
    return a;
}

int **createMatrix(int m, int n) {
// 动态申请数组并置初值为0
    int **a = (int **) malloc(sizeof(int *) * m);  // 申请列空间
    for (int i = 0; i < m; i++) {
        *(a + i) = (int *) malloc(sizeof(int) * n);  // 申请行空间
        memset(a + i, 0, sizeof(int) * n);  // 把整行置0
		// 经过测试发现，在converse函数中仅申请了空间，但未执行memset
		// 因此此方法存在问题，可能是由于指针问题导致的。
    }
    return a;
}

