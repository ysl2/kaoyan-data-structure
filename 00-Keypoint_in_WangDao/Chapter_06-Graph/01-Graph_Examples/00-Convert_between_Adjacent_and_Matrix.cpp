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
    int number;     // 顶点的编号，这一项用户不能自己定义，是固定的从1开始的数字
    ElemType data;  // 顶点名称。这一项是从用户输入的vertex数组中写入的，并不要求非要int型，也可以是A，B，C这种
} VertexType;       // 上面这两项，在遍历的时候不会打印。但是真实存在，用于对结点信息进行补充描述

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
        G->vertex[i].data = vertex[i];
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
MatrixGraph convertAdjacentToMatrix(AdjacentGraph G1) {
    MatrixGraph G2 = new Matrix;
    initMatrixGraph(G2, G1->vexnum);
    for (int i = 0; i < G1->vexnum; i++) {  // 初始化顶点表
        G2->vertex[i].number = i;
        G2->vertex[i].data = G1->vertex[i].data;
    }
    for (int i = 0; i < G1->vexnum; i++) {  // 初始化边表
        for (ArcNode *temp = G1->vertex[i].first; temp != NULL; temp = temp->next)
            G2->edge[i][temp->adjvex] = 1;
    }
    return G2;
}

// 转换：将邻接矩阵转换为邻接表
AdjacentGraph convertMatrixToAdjacent(MatrixGraph G1) {
    AdjacentGraph G2 = new Adjacent;
    initAdjacentGraph(G2, G1->vexnum);
    for (int i = 0; i < G1->vexnum; i++)
        G2->vertex[i].data = G1->vertex[i].data;
    for (int i = 0; i < G1->vexnum; i++) {
        for (int j = G1->vexnum - 1; j >= 0; j--) {
            if (G1->edge[i][j] != 0) {
                ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->info = G1->edge[i][j];
                p->next = G2->vertex[i].first;
                G2->vertex[i].first = p;
            }
        }
    }
    return G2;
}

void test(ElemType *vertex, int vexnum, int *edge) {
    AdjacentGraph G1 = createAdjacent(vertex, vexnum, edge);
    MatrixGraph G2 = convertAdjacentToMatrix(G1);
    outputEdge(G2);

    cout << endl;

    MatrixGraph G3 = createMatrix(vertex, vexnum, edge);
    AdjacentGraph G4 = convertMatrixToAdjacent(G3);
    outputEdge(G4);
}

int main() {
    ElemType vertex[] = {1, 2, 3, 4, 5};
    int vexnum = sizeof(vertex) / sizeof(vertex[0]);
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

// 1|2 3
// 2|3 5
// 3|1 4
// 4|5
// 5|2 3
