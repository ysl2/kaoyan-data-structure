#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct DLinkNode {
    ElemType data;
    struct DLinkNode *pre, *next;
} DLinkNode, *DLinkList;

void outPut(DLinkList L) {
    DLinkNode *p = L->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void reverseOutPut(DLinkList L) {
    if (L == NULL)
        return;
    DLinkNode *p = L;
    while (p->next != NULL)
        p = p->next;
    while (p != L) {
        cout << p->data << " ";
        p = p->pre;
    }
}

void rearInsert(DLinkList &L, ElemType x) {
    DLinkNode *s = new DLinkNode;
    s->data = x;
    L->next = s;
    s->pre = L;
    L = s;
}

DLinkList rearInsertCreate(ElemType arr[], int length) {
    DLinkList L = new DLinkNode;
    DLinkNode *pre = L;
    for (int i = 0; i < length; i++)
        rearInsert(pre, arr[i]);
    pre->next = NULL;
    return L;
}

void test(ElemType a[], int length) {
    DLinkList L = rearInsertCreate(a, length);
    outPut(L);
    reverseOutPut(L);
}

int main() {
    ElemType arr[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(arr) / sizeof(int);

    test(arr, length);

    return 0;
}

// 输出结果：
// 0 2 4 6 8 1 3 5 7 9
// 9 7 5 3 1 8 6 4 2 0
