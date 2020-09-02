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
} *AdjacentList;  
// 如果这里没有加*号，那么下面的应该是L.vexnum
// 如果这里加了*号，那么下面的应该是L->vexnum

AdjacentList L;  // 定义全局变量。如果不写这一句，下面的形参&会报错

//转换
int **converse(AdjacentList &L) {
	// 采用动态方式申请数组a。静态申请也可以。
    int a[][] = createMatrix(L->vexnum, L->vexnum);
    for (int i = 0; i < L.vexnum; i++) {
        ArcNode *temp = (L->vertex[i]).first;
        while (temp != NULL) {
            a[i][temp->index] = 1;
            temp = temp->next;
        }
    }
    return a;
}

int **createMatrix(int m, int n) {
// 动态申请数组并置初值为0
    int **a = (int **) malloc(sizeof(int *) * m);  // 申请行空间
    for (int i = 0; i < m; i++) {
        *(a + i) = (int *) malloc(sizeof(int) * n);  // 申请列空间
        memset(*(a + i), 0, sizeof(int) * n);  // 把该列置0
    }
    return a;
}

