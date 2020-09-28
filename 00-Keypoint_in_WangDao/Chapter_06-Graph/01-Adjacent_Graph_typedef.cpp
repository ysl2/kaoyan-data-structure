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
} VexNode;

typedef struct AdjacentGraph {
    VexNode AdjacentList[maxSize];
    int arcnum, vexnum;
} AdjacentGraph;
