typedef int ElemType;
typedef struct DLinkNode {
    ElemType data;
    struct DLinkNode *pre, *next;
} DLinkNode, *DLinkList;
