#include <stdlib.h>
using namespace std;

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

void selectSort(LinkList &L) {
    LinkList B = (LinkList) malloc(sizeof(LinkNode));
    B->next = L->next->next;
    L->next->next = NULL;
    while (B->next != NULL) {
        LinkNode *pre_p = L;
        LinkNode *pre_q = B;
        for (; pre_q->next->data < pre_p->next->data; pre_q = pre_q->next) {
            LinkNode *q = pre_q->next;
            pre_q->next = q->next;
            q->next = pre_p->next;
            pre_p->next = q;
        }
    }
    free(B);
}
