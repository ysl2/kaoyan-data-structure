#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

// 无头结点单链表的插入
bool insert(LinkList L, int i, ElemType e) {
    if (i < 1)
        return false;
    if (i == 1) {
        LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }
    int j = 1;
    LinkNode *p = L;  // 这里获取的是待插入位置的前驱节点
    for (; p != NULL && j < i - 1; p = p->next, j++)
        ;
    if (p == NULL)
        return false;
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    if (s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
