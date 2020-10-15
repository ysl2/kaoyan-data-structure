// 2020-10-12
// 目标：通过一个一维顶点数组和一个二维边数组，产生一个邻接矩阵图
// 由于C语言在函数传递过程中仅传入数组的首地址，因此我在这里用了一维数组edge来模拟二维数组，而在邻接矩阵中使用实际的二维数组G->edge
// 但是无论是否是真实的二维还是模拟的二维，遍历方式都是按照一维数组的方式来的，即首地址 + 偏移量
#include <string.h>
#include <iostream>
using namespace std;

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

// 返回的是二维数组的下标值。如果需要返回顶点，需要 + 1
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

// 返回的是二维数组的下标值。如果需要返回顶点，需要 + 1
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

int *visited;

bool DFS(MatrixGraph G, int a, int b) {
    // cout << "hello" << endl;
    if (a == b)
        return true;
    else {
        visited[a] = 1;
        for (int w = FirstNeighbor(G, a); w >= 0; w = NextNeighbor(G, a, w)) {  // 一旦w < 0，就会退出循环
            if (visited[w] == 0 && DFS(G, w, b) == true) {
                return true;
            }
        }
    }
    return false;
}

bool DFSTraverse(MatrixGraph G, int A, int B) {
    visited = new int[30];
    memset(visited, 0, sizeof(int) * 30);
    int a = A - 1, b = B - 1;  // 把顶点统一转化成下标

    return DFS(G, a, b);
}

void test(ElemType *vertex, int vexnum, int *edge, int A, int B) {
    MatrixGraph G = createMatrix(vertex, vexnum, edge);

    if (DFSTraverse(G, A, B) == true)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    visited = new int[30];
}

int main() {
    ElemType vertex[] = {1, 2, 3, 4, 5};
    int vexnum = sizeof(vertex) / sizeof(ElemType);
    int edge[] = {
        0, 1, 1, 0, 0,
        0, 0, 1, 0, 0,
        1, 0, 0, 1, 0,
        0, 0, 0, 0, 0,
        0, 1, 1, 0, 0};

    test(vertex, vexnum, edge, 1, 2);
    test(vertex, vexnum, edge, 1, 3);
    test(vertex, vexnum, edge, 1, 4);
    test(vertex, vexnum, edge, 1, 5);

    test(vertex, vexnum, edge, 2, 1);
    test(vertex, vexnum, edge, 2, 3);
    test(vertex, vexnum, edge, 2, 4);
    test(vertex, vexnum, edge, 2, 5);

    return 0;
}

// 输出结果：
// true
// true
// true
// false
// true
// true
// true
// false

