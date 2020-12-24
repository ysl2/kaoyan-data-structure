// 2020-10-28
#include <string.h>
#include <iostream>
#include <queue>
#include <stack>
#define maxSize 20
using namespace std;

typedef int ElemType;
typedef struct {
    int number;     // 顶点的编号，这一项用户不能自己定义，是固定的从1开始的数字
    ElemType data;  // 顶点信息。这一项是从用户输入的vertex数组中写入的，并不要求非要int型，也可以是A，B，C这种
} VertexType;       // 上面这两项，在遍历的时候不会打印。但是真实存在，用于对结点信息进行补充描述

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

int *visited;

void visit(MatrixGraph G, int v, int layer) {
    cout << G->vertex[v].data << " ";
    cout << layer << endl;
}

// 输出与顶点v0距离为k的结点。
/*
        4
      /
    2
  /
1
  \
    3
     \
      5

本次测试用例中，v0是顶点1
注：这个测试用例中，距离指的是每个顶点和v0（也就是顶点1）之间的距离
顶点1距离为0
顶点2和3距离为1
顶点4和顶点5距离为2
*/

void BFS(MatrixGraph G, int v0, int k) {
    queue<pair<int, int>> q;
    visited[v0] = 1;
    q.push({v0, 0});
    while (!q.empty()) {
        int v = q.front().first;
        int layer = q.front().second;
        q.pop();
        if (layer == k)
            cout << G->vertex[v].data << endl;
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
            if (!visited[w]) {
                int temp = layer + 1;
                visited[w] = 1;
                q.push({w, temp});
            }
        }
    }
}

void BFSTraverse(MatrixGraph G, int v0, int k) {
    visited = new int[G->vexnum];
    memset(visited, 0, sizeof(visited[0]) * G->vexnum);
    BFS(G, v0, k);
}

// 这是预测题给的答案，不推荐，写的太乱了
// void bfs_K(MatrixGraph G, int v0, int k) {
//     int Q[maxSize];  // Q为顶点队列，容量足够大
//     int f = 0, r = 0, t = 0;
//     // f和r分别为队头和队尾指针，t指向当前层最后顶点
//     int level = 0, flag = 0;  // 层数和访问成功标记
//     visited = new int[G->vexnum];
//     visited[v0] = 1;  // 设v0为根
//     // 下面三句是v0入队
//     Q[++r] = v0;
//     t = r;
//     level = 1;
//     while (f < r && level <= k + 1) {
//         int v = Q[++f];
//         int w = FirstNeighbor(G, v);
//         while (w != 0) {  // w != 0表示邻接点存在
//             if (visited[w] == 0) {
//                 // 邻接点入队列
//                 Q[++r] = w;
//                 visited[w] = 1;
//                 if (level == k + 1) {
//                     cout << "距顶点v0最短路径为k的顶点" << w << " ";
//                     flag = 1;
//                 }
//             }
//             w = NextNeighbor(G, v, w);
//             if (f == t) {
//                 level++;
//                 t = r;
//             }  // 当前层处理完，修改层数，t指向下一层最后一个顶点
//         }
//         if (flag == 0)
//             cout << "图中无距v0顶点最短路径为" << k << "的顶点" << endl;
//     }
// }

void test(ElemType *vertex, int vexnum, int *edge, int V0, int k) {
    int v0 = V0 - 1;
    MatrixGraph G = createMatrix(vertex, vexnum, edge);
    outputEdge(G);

    cout << endl;

    BFSTraverse(G, v0, k);
}

int main() {
    ElemType vertex[] = {1, 2, 3, 4, 5};
    int vexnum = sizeof(vertex) / sizeof(vertex[0]);
    int edge[] = {
        0, 1, 1, 0, 0,
        1, 0, 0, 1, 0,
        1, 0, 0, 0, 1,
        0, 1, 0, 0, 0,
        0, 0, 1, 0, 0};

    int v0 = 1;
    int k = 2;
    test(vertex, vexnum, edge, v0, k);
    return 0;
}

// 输出结果：
// 0 1 1 0 0
// 1 0 0 1 0
// 1 0 0 0 1
// 0 1 0 0 0
// 0 0 1 0 0

// 4
// 5
