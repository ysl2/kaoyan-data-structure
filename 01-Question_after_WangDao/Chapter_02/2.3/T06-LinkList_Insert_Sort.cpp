// 2020-10-07
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

void rearInsertCreate(LinkList &L, ElemType arr[], int length) {
    L = new LinkNode;
    LinkNode *p = L;
    for (int i = 0; i < length; i++)
        rearInsert(p, arr[i]);
    p->next = NULL;
}

void insertSortList(LinkList &L) {
    if (L == NULL || L->next == NULL)
        return;
    LinkNode *p = L->next->next;
    L->next->next = NULL;
    while (p != NULL) {
        LinkNode *r = L;
        while (r->next != NULL && r->next->data < p->data)
            r = r->next;
        LinkNode *temp = p->next;
        p->next = r->next;
        r->next = p;
        r = r->next;
        p = temp;
    }
}

void test(ElemType *arr, int length) {
    LinkList L = NULL;
    rearInsertCreate(L, arr, length);
    outPut(L);

    insertSortList(L);
    outPut(L);
    cout << "--------------------------" << endl;
}

int main() {
    ElemType arr1[] = {5, 4, 3, 2, 1};
    int length1 = sizeof(arr1) / sizeof(ElemType);
    ElemType arr2[] = {1, 3, 5, 7, 9, 8, 6, 4, 2};
    int length2 = sizeof(arr2) / sizeof(ElemType);
    ElemType arr3[] = {};
    int length3 = sizeof(arr3) / sizeof(ElemType);
    ElemType arr4[] = {0};
    int length4 = sizeof(arr4) / sizeof(ElemType);

    test(arr1, length1);

    test(arr2, length2);

    test(arr3, length3);

    test(arr4, length4);

    return 0;
}

// 输出结果：
// 5 4 3 2 1
// 1 2 3 4 5
// --------------------------
// 1 3 5 7 9 8 6 4 2
// 1 2 3 4 5 6 7 8 9
// --------------------------
//
//
// --------------------------
// 0
// 0
// --------------------------

// ------------------------------------------------------------
// 2020-09-04 第二次修订
void sort(LinkList &L) {
// 采用直接插入排序的思想
    LinkNode *p = L->next->next;
    L->next->next = NULL;
    while (p != NULL) {
        // 寻找插入位置
        LinkNode *pre = L;
        for ( ; pre->next != NULL && pre->next->data < p->data; pre = pre->next);
        // 记录p的下一个位置
        LinkNode *temp = p->next;
        // 头插法
        p->next = pre->next;
        pre->next = p;
        // 把p恢复到下一个位置
        p = temp;
    }
}

// ------------------------------------------------------------
void sort(LinkList &L) {
    LinkNode *p = L->next->next;
    L->next->next = NULL;
    while (p != NULL) {
        LinkNode *pre = L;
        LinkNode *temp = p->next;
        while (pre->next != NULL && pre->next->data < p->data) {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = temp;
    }
}

