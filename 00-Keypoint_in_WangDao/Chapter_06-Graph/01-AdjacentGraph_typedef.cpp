#include <iostream>
using namespace std;
#define NULL 0
typedef char ElemType;
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *next;
    ElemType info;
} ArcNode;

typedef struct VexNode {
    ElemType data;
    ArcNode *first;
} VexNode;

typedef struct {
    VexNode *vertex;
    int arcnum, vexnum;
} Adjacent, *AdjacentGraph;

void outputEdge(AdjacentGraph G) {
    for (int i = 0; i < G->vexnum; i++) {
        cout << G->vertex[i].data << " ";
        for (ArcNode *temp = G->vertex[i].first; temp != NULL; temp = temp->next)
            cout << G->vertex[temp->adjvex].data << " ";
        cout << endl;
    }
}

void initAdjacentGraph(AdjacentGraph &G, int vexnum, int arcnum) {
    G->vexnum = vexnum;
    G->arcnum = arcnum;
    G->vertex = new VexNode[G->vexnum];
    for (int i = 0; i < G->vexnum; i++) {
        G->vertex[i].data = NULL;
        G->vertex[i].first = new ArcNode;
        G->vertex[i].first->next = NULL;
    }
}

AdjacentGraph createAdjacent(ElemType *vertex, int vexnum, int *edge, int arcnum) {
    AdjacentGraph G = new Adjacent;
    initAdjacentGraph(G, vexnum, arcnum);
    for (int i = 0; i < vexnum; i++)
        G->vertex[i].data = vertex[i];
    for (int i = 0; i < arcnum; i++) {
        for (int j = 0; j < arcnum; j++) {
            if (edge[i * arcnum + j] == 1) {
                ArcNode *temp = new ArcNode;
                temp->adjvex = j;
                temp->next = G->vertex[i].first->next;
                G->vertex[i].first = temp;
            }
        }
    }
    return G;
}

void test(ElemType *vertex, int vexnum, int *edge, int arcnum) {
    AdjacentGraph G = createAdjacent(vertex, vexnum, edge, arcnum);
    // outputEdge(G);
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
