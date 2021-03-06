// 2020-11-13
#include <string.h>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

const int INFINITY = 9999;

typedef int ElemType;
typedef struct {
    int number;  // 顶点的编号，这一项用户不能自己定义，是固定的从1开始的数字
    ElemType data;  // 顶点信息。这一项是从用户输入的vertex数组中写入的，并不要求非要int型，也可以是A，B，C这种
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

// 返回的是二维数组的下标值。如果需要返回顶点，需要 + 1
int FirstNeighbor(MatrixGraph G, int v) {
    int i, flag = -1;
    for (i = 0; i < G->vexnum; i++) {
        if (*(*(G->edge + v) + i) != 0) {
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
        if (*(*(G->edge + v) + i) != 0) {
            flag = 1;
            break;
        }
    }
    return (flag == -1) ? flag : i;
}

void printArray(int *a, int length) {
    for (int i = 0; i < length; i++)
        cout << a[i] << " ";
    cout << endl;
}

int *selected;
int *minDist;
int *parent;

void BFS(MatrixGraph G, int v0) {
    queue<int> q;
    selected = new int[G->vexnum];
    minDist = new int[G->vexnum];
    parent = new int[G->vexnum];
    for (int i = 0; i < G->vexnum; i++) {
        selected[i] = 0;
        minDist[i] = INFINITY;
    }
    selected[v0] = 1;
    minDist[v0] = 0;
    parent[v0] = -1;
    q.push(v0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
            if (!selected[w]) {
                minDist[w] = minDist[v] + 1;
                parent[w] = v;
                selected[w] = 1;
                q.push(w);
            }
        }
    }
}


void test(ElemType *vertex, int vexnum, int *edge, int V0) {
    int v0 = V0 - 1;
    MatrixGraph G = createMatrix(vertex, vexnum, edge);
    BFS(G, v0);
    printArray(minDist, G->vexnum);
    printArray(parent, G->vexnum);
}

int main() {
    ElemType vertex[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int vexnum = sizeof(vertex) / sizeof(vertex[0]);
    int edge[] = {
        0, 1, 0, 0, 1, 0, 0, 0,
        1, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 1, 0, 1, 1, 0,
        0, 0, 1, 0, 0, 0, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 0, 0, 0, 1, 0,
        0, 0, 1, 1, 0, 1, 0, 0,
        0, 0, 0, 1, 0, 0, 1, 0};

    test(vertex, vexnum, edge, 1);

    return 0;
}

// 输出结果：
// 0 1 3 4 1 2 3 5
// -1 0 5 2 0 1 5 3

