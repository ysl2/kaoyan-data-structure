// 逆拓扑排序：DFS
#include <iostream>
using namespace std;
#define MAX_VEX_NUM 10
#define MAX_EDGE_NUM 10
#define INFINITY 9999

typedef int VexType;
typedef int EdgeType;

typedef struct {
    VexType *vertex;
    EdgeType **edge;
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

void visit(int v0) {
    cout << v0;
}

bool visited[MAX_VEX_NUM];

void DFS(MatrixGraph G, int v0) {
    visited[v0] = true;
    int v = v0;
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
        if (!visited[w]) {
            DFS(G, w);
        }
    }
    visit(v0);
}

void DFSTraverse(MatrixGraph G) {
    for (int i = 0; i < MAX_VEX_NUM; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            DFS(G, i);
        }
    }
}
