#include <string>
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

int count = 0;
void getTheZeroDegreeVertex(AdjacentGraph G) {
    memset(result, 0, sizeof(int) * maxSize);
    for (int i = 0; i < G.vexnum; i++) {
        if (FirstNeighbor(G, i) < 0) {
            count++;
        }
    }
}
