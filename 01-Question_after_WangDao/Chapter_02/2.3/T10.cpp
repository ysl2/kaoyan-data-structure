// 2020-10-08
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

void outPut(LinkList L) {
    LinkNode *p = L->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void rearInsert(LinkList &L, ElemType x) {
    LinkNode *s = new LinkNode;
    s->data = x;
    L->next = s;
    L = s;
}

LinkList rearInsertCreate(ElemType arr[], int length) {
    LinkList L = new LinkNode;
    LinkNode *p = L;
    for (int i = 0; i < length; i++)
        rearInsert(p, arr[i]);
    p->next = NULL;
    return L;
}

LinkList seprateList(LinkList &A) {
    if (A == NULL || A->next == NULL)
        return NULL;
    LinkNode *pre = A, *p = A->next;
    LinkList B = new LinkNode;
    LinkNode *r = B;
    while (p != NULL && p->next != NULL) {
        p = p->next;
        pre = pre->next;
        pre->next = p->next;
        r->next = p;
        r = r->next;
        p = pre->next;
    }
    r->next = NULL;
    return B;
}

void test(int a[], int length) {
    LinkList L = rearInsertCreate(a, length);
    LinkList B = seprateList(L);

    outPut(L);
    outPut(B);
}

int main() {
    ElemType arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length1 = sizeof(arr1) / sizeof(int);

    test(arr1, length1);

    return 0;
}

// 输出结果：
// 1 3 5 7 9
// 2 4 6 8


//----------------------------------------------------------------------
// 2020-09-04 补充不设置变量i的方法
#include <stdlib.h>  // malloc的库
LinkList seprate(LinkList &L) {
// 对于A，不创建新的空间，直接使用L的空间。所以L就相当于A
    LinkNode *p = L->next;
    L->next = NULL;  // 把L摘下来，一会儿对L尾插（A尾插）
    LinkList B = (LinkList) malloc(sizeof(LinkNode));
    B->next = NULL;  // B尾插
    LinkNode *q = B;  // q是B的工作指针
    LinkNode *r = L;  // r是A的工作指针（即L的工作指针）
    while (p != NULL) {
        // L尾插
        r->next = p;
        r = r-next;
        p = p->next;
        // 下面这个if必须判断
        if (p == NULL) break;
        // B尾插
        q->next = p;
        q = q->next;
        p = p->next;
    }
    q->next = NULL;
    r->next = NULL;
    return B;
}

//----------------------------------------------------------------------
LinkList disc(LinkList &L) {
    LinkList B = (LinkList) malloc(sizeof(LinkNode));
    B->next = NULL;
    LinkNode *pre1 = L, *pre2 = B, *p = L->next;
    L->next = NULL;
    // i表示序号，从1开始计算
    for (int i = 1; p != NULL; p = p->next, i++) {
        if (i % 2 == 1) {
            pre1->next = p;
            pre1 = p;
        } else {
            pre2->next = p;
            pre2 = p;
        }
    }
    pre1->next = NULL;
    pre2->next = NULL;
    return B;
}

