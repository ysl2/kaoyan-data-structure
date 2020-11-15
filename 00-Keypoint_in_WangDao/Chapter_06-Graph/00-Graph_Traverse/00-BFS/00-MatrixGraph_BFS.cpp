// 2020-10-28
#include <string.h>
#include <iostream>
#include <queue>
#include <stack>
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

void visit(MatrixGraph G, int v) {
    cout << G->vertex[v].data << " ";
}

void BFS(MatrixGraph G, int v0) {
    queue<int> q;
    visit(G, v0);
    visited[v0] = 1;
    q.push(v0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
            if (!visited[w]) {
                visit(G, w);
                visited[w] = 1;
                q.push(w);
            }
        }
    }
}

void BFSTraverse(MatrixGraph G) {
    visited = new int[G->vexnum];
    memset(visited, 0, sizeof(int) * G->vexnum);
    for (int i = 0; i < G->vexnum; i++) {
        if (!visited[i])
            BFS(G, i);
    }
}

void test(ElemType *vertex, int vexnum, int *edge) {
    MatrixGraph G = createMatrix(vertex, vexnum, edge);
    BFSTraverse(G);
    cout << endl;
}

int main() {
    ElemType vertex[] = {1, 2, 3, 4, 5, 6, 7};
    int vexnum = sizeof(vertex) / sizeof(vertex[0]);
    int edge[] = {
        0, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 1, 1, 0, 0,
        0, 0, 1, 0, 0, 1, 1,
        0, 0, 0, 1, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0};

    test(vertex, vexnum, edge);

    return 0;
}

// 输出结果：
// 1 2 3 4 5 6 7



// ------------------------------------------------------------------------
// #include <iostream>
// #include <queue>
// using std::cout;
// using std::endl;
// using std::queue;
// #define maxSize 10

// typedef struct {
//     int number;
//     char info;
// } VertexType;

// typedef struct {
//     VertexType vertices[maxSize];
//     int edge[maxSize][maxSize];
//     int vexnum, arcnum;
// } MatrixGraph;

// int FirstNeighbor(MatrixGraph G, int v) {
//     int i, flag = -1;
//     for (i = 0; i < G.vexnum; i++) {
//         if (*(*(G.edge + v) + i) == 1) {
//             flag = 1;
//             break;
//         }
//     }
//     return (flag == -1) ? flag : i;
// }

// int NextNeighbor(MatrixGraph G, int v, int w) {
//     int i, flag = -1;
//     for (i = w + 1; i < G.vexnum; i++) {
//         if (*(*(G.edge + v) + i) == 1) {
//             flag = 1;
//             break;
//         }
//     }
//     return (flag == -1) ? flag : i;
// }

// bool visited[maxSize];
// queue<int> q;

// void visit(MatrixGraph G, int v0) {
//     cout << G.vertices[v0].info << endl;
// }

// void BFS(MatrixGraph G, int v0) {
//     visit(G, v0);
//     visited[v0] = true;
//     q.push(v0);
//     while (!q.empty()) {
//         int v = q.front();
//         q.pop();
//         for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
//             if (!visited[w]) {
//                 visit(G, w);
//                 visited[w] = true;
//                 q.push(w);
//             }
//         }
//     }
// }

// void BFSTraverse(MatrixGraph G) {
//     for (int i = 0; i < maxSize; i++)
//         visited[i] = false;
//     for (int i = 0; i < G.vexnum; i++)
//         if (!visited[i])
//             BFS(G, i);
// }
