// 2020-11-13
#include <stdlib.h>
#include <string.h>
#include <iostream>
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
    for (int i = 0; i < G->vexnum; i++)
        G->vertex[i].number = i;
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

void printArray(int *a, int length) {
    for (int i = 0; i < length; i++)
        cout << a[i] << " ";
    cout << endl;
}

int *selected;
int *minDist;
int *parent;

void Dijkstra(MatrixGraph G, int v0) {
    // G.weight[u][v]表示边e=(u, v)的权值（不存在的情况下设为INFINITY）
    // 初始化
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

    int v = v0;  // 表示新加入的结点。
    // 注意：后面导致minDist和parent更新的原因就是因为新节点v的加入
    while (true) {
        // 1. 更新连接两个区域边的信息(update)
        for (int i = 0; i < G->vexnum; i++) {
            if (!selected[i] && minDist[i] > minDist[v] + G->edge[v][i]) {
                minDist[i] = minDist[v] + G->edge[v][i];  // 更新到该顶点的最短路径长度
                parent[i] = v;                            // 更新父节点
            }
        }
        // 2. 找连接两个区域的最小权边上的没有访问的顶点(scan)
        v = -1;
        for (int i = 0; i < G->vexnum; i++) {
            if (!selected[i] && (v == -1 || minDist[i] < minDist[v]))
                v = i;
        }
        if (v == -1)
            break;  // 所有的结点被访问
        // 3. 添加节点到集合(add)
        selected[v] = 1;
    }
}

void test(ElemType *vertex, int vexnum, int *edge, int V0) {
    int v0 = V0 - 1;
    MatrixGraph G = createMatrix(vertex, vexnum, edge);
    Dijkstra(G, v0);
    printArray(minDist, G->vexnum);
    printArray(parent, G->vexnum);
}

int main() {
    ElemType vertex[] = {1, 2, 3, 4, 5};
    int vexnum = sizeof(vertex) / sizeof(ElemType);
    int edge[] = {
        INFINITY, 10, INFINITY, 30, 100,
        INFINITY, INFINITY, 50, INFINITY, INFINITY,
        INFINITY, INFINITY, INFINITY, INFINITY, 10,
        INFINITY, INFINITY, 20, INFINITY, 60,
        INFINITY, INFINITY, INFINITY, INFINITY, INFINITY};

    test(vertex, vexnum, edge, 1);

    return 0;
}

// 输出结果：（测试用例为山大2014年真题）
// 0 10 50 30 60
// -1 0 3 0 2
