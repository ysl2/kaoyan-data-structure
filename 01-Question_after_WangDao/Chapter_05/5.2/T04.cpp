// 2020-10-12
// 将邻接表转换成邻接矩阵，可以分为两个目标依次执行：
// 1 构造邻接表
// 2 构造邻接矩阵
#include <string.h>
#include <iostream>
using namespace std;

// 目标：通过一个一维顶点数组和一个二维边数组，产生一个邻接矩阵图
// 由于C语言在函数传递过程中仅传入数组的首地址，因此我在这里用了一维数组edge来模拟二维数组，而在邻接矩阵中使用实际的二维数组G->edge
// 但是无论是否是真实的二维还是模拟的二维，遍历方式都是按照一维数组的方式来的，即首地址 + 偏移量
typedef int ElemType;
typedef struct {
    int number;  // 顶点的编号，这一项用户不能自己定义，是固定的从1开始的数字
    ElemType info;  // 顶点信息。这一项是从用户输入的vertex数组中写入的，并不要求非要int型，也可以是A，B，C这种
} VertexType;  // 上面这两项，在遍历的时候不会打印。但是真实存在，用于对结点信息进行补充描述

typedef struct {
    VertexType *vertex;
    int **edge;
    int vexnum, arcnum;
} Matrix, *MatrixGraph;

// 目标：通过一个一维顶点数组和一个二维边数组，产生一个邻接表图
// 注意：这里的二维边数组是通过一个一维数组模拟的。因为二维数组和一维数组本质上没有区别，都是一段连续的地址构成的
typedef int ElemType;
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *next;
    ElemType info;  // 对当前结点的补充信息，这一项不是必须要填写的。
} ArcNode;

typedef struct VexNode {
    ElemType data;
    ArcNode *first;
    ElemType info;  // 对当前顶点的补充信息，这一项不是必须要填写的。
} VexNode;

typedef struct {
    VexNode *vertex;
    int arcnum, vexnum;
} Adjacent, *AdjacentGraph;


void outputEdge(MatrixGraph G) {
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++)
            cout << *(*(G->edge + i) + j) << " ";  // 虽然是二维数组，但是按照一维的方式遍历，只是需要解引用两层
        cout << endl;
    }
}

// 初始化邻接矩阵
void initMatrixGraph(MatrixGraph &G, int vexnum) {
    G->vexnum = vexnum;
    G->arcnum = 0;
    G->vertex = new VertexType[G->vexnum];
    for (int i = 0; i < G->vexnum; i++) {
        G->vertex[i].number = i;
        // G->vertex[i].info = NULL;  // 可选，因为在下面的函数中，会再次赋值
    }
    G->edge = new int *[G->vexnum];
    for (int i = 0; i < G->vexnum; i++) {
        G->edge[i] = new int[G->vexnum];
        memset(G->edge[i], 0, sizeof(int) * (G->vexnum));
    }
}

// 通过一个一维顶点数组和一个二维边数组得到一个邻接矩阵图
MatrixGraph createMatrix(ElemType *vertex, int vexnum, int *edge) {
    MatrixGraph G = new Matrix;
    initMatrixGraph(G, vexnum);
    for (int i = 0; i < vexnum; i++)
        G->vertex[i].info = vertex[i];
    for (int i = 0; i < vexnum; i++) {
        for (int j = 0; j < vexnum; j++) {
            if (edge[i * vexnum + j] != 0) {
                G->edge[i][j] = edge[i * vexnum + j];  // 将一维数组edge的值按照二维数组的方式输入到G->edge
                G->arcnum++;
            }
        }
    }
    return G;
}

void outputEdge(AdjacentGraph G) {
    for (int i = 0; i < G->vexnum; i++) {
        cout << G->vertex[i].data << "|";
        for (ArcNode *temp = G->vertex[i].first; temp != NULL; temp = temp->next)
            cout << G->vertex[temp->adjvex].data << " ";
        cout << endl;
    }
}

void initAdjacentGraph(AdjacentGraph &G, int vexnum) {
    G->vexnum = vexnum;
    G->arcnum = 0;
    G->vertex = new VexNode[G->vexnum];
    for (int i = 0; i < G->vexnum; i++) {
        G->vertex[i].data = 0;
        G->vertex[i].first = NULL;
    }
}

AdjacentGraph createAdjacent(ElemType *vertex, int vexnum, int *edge) {
    AdjacentGraph G = new Adjacent;
    initAdjacentGraph(G, vexnum);
    for (int i = 0; i < vexnum; i++)
        G->vertex[i].data = vertex[i];
    for (int i = 0; i < vexnum; i++) {
        // 由于在这里采用头插法插入结点，因此为了保证顺序和顶点顺序一致，采用从后向前遍历，这样头插结束后，链表结点顺序不会相反
        for (int j = vexnum - 1; j >= 0; j--) {
            if (edge[i * vexnum + j] == 1) {
                ArcNode *temp = new ArcNode;
                temp->adjvex = j;
                temp->next = G->vertex[i].first;
                G->vertex[i].first = temp;
                G->arcnum++;
            }
        }
    }
    return G;
}

// 转换：将邻接表转换为邻接矩阵
MatrixGraph converseAdjacentToMatrix(AdjacentGraph G1) {
    MatrixGraph G2 = new Matrix;
    initMatrixGraph(G2, G1->vexnum);
    for (int i = 0; i < G1->vexnum; i++) {  // 初始化顶点表
        G2->vertex[i].number = i;
        G2->vertex[i].info = G1->vertex->data;
    }
    for (int i = 0; i < G1->vexnum; i++) {  // 初始化边表
        for (ArcNode *temp = G1->vertex[i].first; temp != NULL; temp = temp->next)
            G2->edge[i][temp->adjvex] = 1;
    }
    return G2;
}

void test(ElemType *vertex, int vexnum, int *edge) {
    AdjacentGraph G1 = createAdjacent(vertex, vexnum, edge);
    MatrixGraph G2 = converseAdjacentToMatrix(G1);
    outputEdge(G2);
}

int main() {
    ElemType vertex[] = {1, 3, 5, 7, 9};
    int vexnum = sizeof(vertex) / sizeof(ElemType);
    int edge[] = {
        0, 1, 1, 0, 0,
        0, 0, 1, 0, 1,
        1, 0, 0, 1, 0,
        0, 0, 0, 0, 1,
        0, 1, 1, 0, 0};

    test(vertex, vexnum, edge);
    return 0;
}

// 输出结果：
// 0 1 1 0 0
// 0 0 1 0 1
// 1 0 0 1 0
// 0 0 0 0 1
// 0 1 1 0 0


//--------------------------------------------------------------------------------------------------------------------------
typedef int VexType;
typedef int EdgeType;

typedef struct {
    VexType *vertex;
    EdgeType **edge;
    int vexnum, arcnum;
} MatrixGraph;

//邻接表的结构体定义：
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
} * AdjacentGraph;
// 如果这里没有加*号，那么下面的应该是G.vexnum
// 如果这里加了*号，那么下面的应该是G->vexnum

// 2020-09-26 将图的邻接表表示成转换成邻接矩阵表示的算法
void convert(AdjacentGraph G1, MatrixGraph &G2) {
    for (int i = 0; i < G1->vexnum; i++)
        for (ArcNode *temp = (G1->vertex[i]).first; temp != 0; temp = temp->next)
            G2.edge[i][temp->index] = 1;
}

// 下面注释中，数组动态分配存在问题，不要看了

// //转换
// int **converse(AdjacentGraph &G) {
// 	// 采用动态方式申请数组a。静态申请也可以。
// 	// 2020-09-04：动态申请有问题。只会开辟空间，但是memset函数未执行
// 	// 因此改用静态申请。下面这句是动态申请，划掉。
//     //int a[][] = createMatrix(G->vexnum, G->vexnum);
// 	int a[G->vexnum][G->vexnum];
//     memset(a, 0, sizeof(int) * G->vexnum * G->vexnum);  // 把整个二维数组置0
//     for (int i = 0; i < G.vexnum; i++) {
//         for (ArcNode *w = (G->vertex[i]).first; w != NULL; w = w->next) {
//             a[i][w->index] = 1;
//         }
//     }
//     return a;
// }

// int **createMatrix(int m, int n) {
// // 动态申请数组并置初值为0
//     int **a = (int **) malloc(sizeof(int *) * m);  // 申请列空间
//     for (int i = 0; i < m; i++) {
//         *(a + i) = (int *) malloc(sizeof(int) * n);  // 申请行空间
//         memset(a + i, 0, sizeof(int) * n);  // 把整行置0
// 		// 经过测试发现，在converse函数中仅申请了空间，但未执行memset
// 		// 因此此方法存在问题，可能是由于指针问题导致的。
//     }
//     return a;
// }
