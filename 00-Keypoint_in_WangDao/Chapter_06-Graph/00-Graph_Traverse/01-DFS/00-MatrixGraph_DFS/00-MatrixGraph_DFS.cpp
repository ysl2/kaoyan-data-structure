#include <iostream>
using std::cout;
using std::endl;
#define maxSize 10
// using std::cout;

typedef struct {
    int number;
    char info;
} VertexType;

typedef struct {
    VertexType vertices[maxSize];
    int edge[maxSize][maxSize];
    int vexnum, arcnum;
} MatrixGraph;

int FirstNeighbor(MatrixGraph G, int v) {
    int i, flag = -1;
    for (i = 0; i < G.vexnum; i++) {
        if (*(*(G.edge + v) + i) == 1) {
            flag = 1;
            break;
        }
    }
    return (flag == -1) ? flag : i;
}

int NextNeighbor(MatrixGraph G, int v, int w) {
    int i, flag = -1;
    for (i = w + 1; i < G.vexnum; i++) {
        if (*(*(G.edge + v) + i) == 1) {
            flag = 1;
            break;
        }
    }
    return (flag == -1) ? flag : i;
}

bool visited[maxSize];

void visit(MatrixGraph G, int v0) {
    cout << G.vertices[v0].info << endl;
}

void DFS(MatrixGraph G, int v0) {
    visit(G, v0);
    visited[v0] = true;
    int v = v0;
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
        if (!visited[w]) {
            DFS(G, w);
        }
    }
}

void DFSTraverse(MatrixGraph G) {
    for (int i = 0; i < maxSize; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            DFS(G, i);
        }
    }
}
