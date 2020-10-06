#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

void deleteList(LinkList &L, ElemType x) {
    if (L == NULL)
        return;
    if (L->data == x) {
        LinkNode *temp = L;
        L = L->next;
        free(temp);
        deleteList(L, x);
    } else
        deleteList(L->next, x);
}

