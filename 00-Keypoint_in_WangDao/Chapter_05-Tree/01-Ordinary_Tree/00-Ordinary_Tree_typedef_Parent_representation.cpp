#define MAX_TREE_SIZE 100

typedef int ElemType;

typedef struct {
    ElemType data;
    int parent;
} ParentTreeNode;

typedef struct {
    ParentTreeNode nodes[MAX_TREE_SIZE];
    int n;
} *ParentTree;
