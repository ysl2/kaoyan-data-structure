#define maxSize 20
typedef char ElemType;
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *next;
    int info;
} ArcNode;

typedef struct VexNode {
    ElemType data;
    ArcNode *first;
    int arcnum, vexnum;
} VexNode;

typedef struct AdjacentGraph {
    VexNode AdjacentList[maxSize];
    int vexnum, edgenum;
} AdjacentGraph;

int getOutDegree(AdjacentGraph G, int k) {
    int i = 0;
    for (int w = FirstNeighbor(G, k); w >= 0; w = NextNeighbor(G, k, w), i++)
        ;
    return i;
}
