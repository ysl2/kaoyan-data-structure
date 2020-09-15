#include <cstdlib>

typedef int ElemType;
typedef struct DLinkNode {
    ElemType data;
    struct DLinkNode *pre, *next;
} DLinkNode, *DLinkList;

bool insertList(DLinkList &L, DLinkNode *&p) {// 注意p这里的&，由于p进行了改变，因此要加&
    if (L == NULL || p == NULL)  
        return false;
    p->next = L->next;
    L->next = p;
    p->pre = L;
    p->next->pre = p;
    return true;
}
