// 2020-09-03 第二次修订
#include <stdlib.h>  // abs函数的库声明
#include <string.h>  // memset函数的库声明

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

LinkList L;

void func(LinkList &L, int n) {
    int *B = (int *) malloc(sizeof(int) * (n + 1));
    memset(B, 0, malloc(sizeof(int) * (n + 1)));
    LinkNode *p = L;
    while (p->next != NULL) {
        int index = abs(p->next->data);
        if (B[index] == 0) {
            B[index] = 1;
			p = p->next;
        } else {
            LinkNode *temp = p->next;
            p->next = temp->next;
            free(temp);
        }
    }
    free(B);
}


---------------------------------------------------------------
typedef struct Node {
    int data;
    struct Node *link;
} LinkNode, *LinkList;

void func(LinkNode *L, int n) {
    LinkNode *p = L, *r;
    int *B, m;
    B = (int *) malloc(sizeof(int) * (n + 1));
    memset(B, 0, sizeof(int) * (n + 1));
    while (p->link != NULL) {
        m = (p->link->data > 0)? (p->link->data) : (-1) * (p->link->data);
        if (*(B + m) == 0) {
            *(B + m) = 1;
            p = p->link;
        } else {
            r = p->link;
            p->link = r->link;
            free(r);
        }
    }
    free(B);
}
