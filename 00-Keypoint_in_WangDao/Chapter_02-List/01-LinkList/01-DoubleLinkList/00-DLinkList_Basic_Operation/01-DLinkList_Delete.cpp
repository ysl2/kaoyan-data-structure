#include <cstdlib>

typedef int ElemType;
typedef struct DLinkNode {
    ElemType data;
    struct DLinkNode *pre, *next;
} DLinkNode, *DLinkList;

bool deleteList(DLinkList &L, DLinkNode *&q) {
    if (L == NULL || q == NULL)
        return false;
    L->next = q->next;
    q->next->pre = L;
    delete q;
    return true;
}
