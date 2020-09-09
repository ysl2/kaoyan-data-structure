// 2020-09-07 第三次修订
#include <stdlib.h>  // abs函数的库声明
#include <string.h>  // memset函数的库声明

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

LinkList L;

void delete(LinkList &L, int n) {
// abs(data) <= n，所以abs(data) ∈ [0, n]，一共n + 1个值
    int *B = (int *) malloc(sizeof(int) * (n + 1));
    memset(B, 0, malloc(sizeof(int) * (n + 1)));  // 给数组赋初值0
    LinkNode *pre = L;  // 取前驱指针
    while (pre->next != NULL) {
        int index = abs(pre->next->data);
        if (B[index] == 0) {  // 第一次出现
            B[index] = 1;
			pre = pre->next;
        } else {  // 之前已经出现过，但是现在又出现了
            LinkNode *temp = pre->next;
            pre->next = temp->next;
            free(temp);
        }
    }
    free(B);  // 释放辅助空间
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
