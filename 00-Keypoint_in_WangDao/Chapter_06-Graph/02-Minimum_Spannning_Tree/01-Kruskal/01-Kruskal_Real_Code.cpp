// 2020-10-19
#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

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

int *disJointSet;  // 并查集

int getRoot(int a) {
    while (disJointSet[a] != a)
        a = disJointSet[a];
    return a;
}

void edgeSort(vector<pair<int, int>> &v, MatrixGraph G) {
    // 对边进行插入排序
    int vsize = v.size();
    for (int i = 1; i < vsize; i++) {
        pair<int, int> temp = v[i];
        int j;
        for (j = i - 1; j >= 0 && G->edge[v[j].first][v[j].second] > G->edge[temp.first][temp.second]; j--)
            v[j + 1] = v[j];
        v[j + 1] = temp;
    }
}

// 最小生成树 -> kruskal
int kruskal(MatrixGraph G) {
    disJointSet = new int[G->vexnum];
    // 初始化并查集
    for (int i = 0; i < G->vexnum; i++)
        disJointSet[i] = i;
    vector<pair<int, int>> v;
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++) {
            if (G->edge[i][j] != 0)
                v.push_back({i, j});
        }
    }
    edgeSort(v, G);  // 对所有的边进行从小到大排序
    int sum = 0;
    int vsize = v.size();
    int getEdge = 0;
    for (int i = 0; i < vsize; i++) {
        if (getEdge == G->vexnum - 1)  // 当已经获取到了n - 1条边（n为顶点的个数）的时候，就退出循环。否则继续寻找会导致有环。
            break;
        int a = getRoot(v[i].first);
        int b = getRoot(v[i].second);
        if (a != b) {
            sum += G->edge[v[i].first][v[i].second];
            disJointSet[a] = b;
            getEdge++;
        }
    }
    return sum;
}

void test(ElemType *vertex, int vexnum, int *edge) {
    MatrixGraph G = createMatrix(vertex, vexnum, edge);
    outputEdge(G);
    cout << endl;
    cout << kruskal(G) << endl;
}

int main() {
    ElemType vertex[] = {1, 2, 3, 4, 5, 6, 7};
    int vexnum = sizeof(vertex) / sizeof(vertex[0]);
    int edge[] = {
        0, 3, 3, 6, 0, 0, 0,
        3, 0, 4, 0, 5, 0, 0,
        3, 4, 0, 0, 4, 3, 0,
        6, 0, 0, 0, 0, 5, 0,
        0, 5, 4, 0, 0, 0, 3,
        0, 0, 3, 5, 0, 0, 7,
        0, 0, 0, 0, 3, 7, 0};

    test(vertex, vexnum, edge);
    return 0;
}

// 输出结果：
// 0 3 3 6 0 0 0
// 3 0 4 0 5 0 0
// 3 4 0 0 4 3 0
// 6 0 0 0 0 5 0
// 0 5 4 0 0 0 3
// 0 0 3 5 0 0 7
// 0 0 0 0 3 7 0

// 21


