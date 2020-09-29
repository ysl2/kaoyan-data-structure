#include <stdlib.h>
using namespace std;

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

// 我自己第一遍写的，带头结点的单链表（注：王道书上是不带头结点的单链表）
void selectSort1(LinkList &L) {
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

// 我自己第二遍写的，对带头结点的单链表进行简单选择排序（注：王道书上是不带头结点的单链表）
void selectSort2(LinkList L) {
    LinkList B = (LinkList)malloc(sizeof(LinkNode));
    B->next = L->next->next;
    L->next->next = NULL;
    LinkNode *p, *pre, *maxp, *maxpre;
    while (B->next != NULL) {
        pre = maxpre = B;
        p = maxp = B->next;
        while (p != NULL) {
            if (p->data > maxp->data) {  // 每次都挑出一个最大的，然后插入到已经排好序的链表的前面
                maxp = p;
                maxpre = pre;
            }
        }
        maxpre->next = maxp->next;
        maxp->next = L->next;
        L->next = maxp;
    }
    free(B);
}
