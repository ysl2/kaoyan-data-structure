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

// 找到第i个位置（注意， 是第i个位置）的结点p，然后在p的前面插入新结点，这样就是在第i个结点之前插入结点了
bool insertList(LinkList &L, int i, ElemType x) {
    if (L == NULL || L->next == NULL || i <= 0)
        return false;
    LinkNode *pre = L, *p = L->next;
    int j = 1;
    for (; j < i && p != NULL; j++, p = p->next, pre = pre->next)  // 找到第i个位置上的结点p
        ;
    if (p == NULL)
        return false;
    LinkNode *s = new LinkNode;
    s->data = x;
    s->next = p;
    pre->next = s;
    return true;
}

void test(ElemType a[], int length, int i, ElemType x) {
    LinkList L = rearInsertCreate(a, length);
    insertList(L, i, x);
    outPut(L);
}

int main() {
    ElemType arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(arr) / sizeof(arr[0]);

    int i1 = 1;
    int x1 = 99;
    test(arr, length, i1, x1);

    int i2 = 3;
    int x2 = 99;
    test(arr, length, i2, x2);

    int i3 = 9;
    int x3 = 99;
    test(arr, length, i3, x3);

    int i4 = 10;
    int x4 = 99;
    test(arr, length, i4, x4);

    return 0;
}

// 输出结果：
// 99 1 2 3 4 5 6 7 8 9
// 1 2 99 3 4 5 6 7 8 9
// 1 2 3 4 5 6 7 8 99 9
// 1 2 3 4 5 6 7 8 9
