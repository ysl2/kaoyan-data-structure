#include <cstdlib>
#include <iostream>

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

void outPut(LinkList L) {
    LinkNode *p = L->next;
    while (p != NULL) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

void rearInsert(LinkList &L, ElemType x) {
    LinkNode *s = new LinkNode;
    s->data = x;
    L->next = s;
    L = s;
}

void rearInsertCreate(LinkList &L, ElemType arr[], int length) {
    L = new LinkNode;
    LinkNode *p = L;
    for (int i = 0; i < length; i++) {
        rearInsert(p, arr[i]);
    }
    p->next = NULL;
}

// 依然采用快慢指针的思想，p是慢指针，q是快指针
// 每次都是p走一个，q走两个
LinkNode *getTheMiddleElement(LinkList L) {
    LinkNode *p = L;
    LinkNode *q = L->next;
    while (q != NULL) {
        p = p->next;
        if (q != NULL)
            q = q->next;
        if (q != NULL)
            q = q->next;
    }
    return p;
}

void test(ElemType *arr, int length) {
    LinkList L = NULL;
    rearInsertCreate(L, arr, length);
    outPut(L);
    LinkNode *p = getTheMiddleElement(L);
    std::cout << p->data << std::endl
              << std::endl;
}

int main() {
    ElemType arr1[] = {1, 2, 3, 4, 5};
    int length1 = sizeof(arr1) / sizeof(int);
    ElemType arr2[] = {1, 2, 3, 4, 5, 6};
    int length2 = sizeof(arr2) / sizeof(int);

    // 测试奇数个结点组成的链表
    test(arr1, length1);
    // 测试偶数个结点组成的链表
    test(arr2, length2);

    return 0;
}

// 输出结果：
// 1 2 3 4 5
// 3

// 1 2 3 4 5 6
// 3
