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

