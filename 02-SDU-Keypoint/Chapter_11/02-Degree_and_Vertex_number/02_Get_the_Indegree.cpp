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

int getTheIndegree(AdjacentGraph G, int k) {
    int count = 0;
    for (int i = 0; i < G.vexnum; i++) {
        for (ArcNode *p = G.AdjacentList[k].first; p != NULL; p = p->next) {
            int w = p->adjvex;
            if (w == k)
                count++;
        }
    }
    return count;
}
