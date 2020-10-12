// 目标：通过一个一维顶点数组和一个二维顶点数组，产生一个邻接矩阵图
// 由于C语言在函数传递过程中仅传入数组的首地址，因此我在这里用了一维数组edge来模拟二维数组，而在邻接矩阵中使用实际的二维数组G->edge
// 但是无论是否是真实的二维还是模拟的二维，遍历方式都是按照一维数组的方式来的，即首地址 + 偏移量
#include <string.h>
#include <iostream>
using namespace std;

typedef char ElemType;
typedef struct {
    int number;
    ElemType info;
} VertexType;

typedef struct {
    VertexType *vertex;
    int **edge;
    int vexnum, arcnum;
} Matrix, *MatrixGraph;

void outputEdge(MatrixGraph G) {
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->arcnum; j++)
            cout << *(*(G->edge + i) + j) << " ";  // 虽然是二维数组，但是按照一维的方式遍历，只是需要解引用两层
        cout << endl;
    }
}

// 初始化邻接矩阵
void initMatrixGraph(MatrixGraph &G, int vexnum, int arcnum) {
    G->vexnum = vexnum;
    G->arcnum = arcnum;
    G->vertex = new VertexType[G->vexnum];
    for (int i = 0; i < G->vexnum; i++) {
        G->vertex[i].number = i;
        G->vertex[i].info = NULL;
    }
    G->edge = new int *[G->arcnum];
    for (int i = 0; i < G->arcnum; i++) {
        G->edge[i] = new int[G->arcnum];
        memset(G->edge[i], 0, sizeof(int) * (G->arcnum));
    }
}

// 通过一个一维顶点数组和一个二维边数组得到一个邻接矩阵图
MatrixGraph createMatrix(ElemType *vertex, int vexnum, int *edge, int arcnum) {
    MatrixGraph G = new Matrix;
    initMatrixGraph(G, vexnum, arcnum);
    for (int i = 0; i < vexnum; i++)
        G->vertex[i].info = vertex[i];
    for (int i = 0; i < arcnum; i++)
        for (int j = 0; j < arcnum; j++)
            G->edge[i][j] = edge[i * arcnum + j];  // 将一维数组edge的值按照二维数组的方式输入到G->edge
    return G;
}

// 此函数未启用
int FirstNeighbor(MatrixGraph G, int v) {
    int i, flag = -1;
    for (i = 0; i < G->vexnum; i++) {
        if (*(*(G->edge + v) + i) == 1) {
            flag = 1;
            break;
        }
    }
    return (flag == -1) ? flag : i;
}

// 此函数未启用
int NextNeighbor(MatrixGraph G, int v, int w) {
    int i, flag = -1;
    for (i = w + 1; i < G->vexnum; i++) {
        if (*(*(G->edge + v) + i) == 1) {
            flag = 1;
            break;
        }
    }
    return (flag == -1) ? flag : i;
}

void test(ElemType *vertex, int vexnum, int *edge, int arcnum) {
    MatrixGraph G = createMatrix(vertex, vexnum, edge, arcnum);
    outputEdge(G);
}

int main() {
    ElemType vertex[] = {1, 3, 5, 7, 9};
    int vexnum = sizeof(vertex) / sizeof(ElemType);
    const int arcnum = 5;
    int edge[] = {
        0, 1, 1, 0, 0,
        0, 0, 1, 0, 1,
        1, 0, 0, 1, 0,
        0, 0, 0, 0, 1,
        0, 1, 1, 0, 0};

    test(vertex, vexnum, edge, arcnum);
    return 0;
}

// 输出结果：
// 0 1 1 0 0
// 0 0 1 0 1
// 1 0 0 1 0
// 0 0 0 0 1
// 0 1 1 0 0
