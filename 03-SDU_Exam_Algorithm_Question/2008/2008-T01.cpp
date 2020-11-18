#include <iostream>
#include <string.h>
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

// 采用计数排序的思路
void complementarySet(LinkList &A, LinkList B) {
    ElemType max = B->next->data;
    ElemType min = B->next->data;
    LinkNode *p = B->next;
    while (p != NULL) {
        if (p->data > max)
            max = p->data;
        if (p->data < min)
            min = p->data;
        p = p->next;
    }
    int length = max - min + 1;
    ElemType *set = new ElemType[length];
    memset(set, 0, sizeof(set[0]) * length);
    p = B->next;
    while (p != NULL) {
        set[p->data - min] = 1;
        p = p->next;
    }
    p = A->next;
    LinkNode *pre = A;
    while (p != NULL) {
        if (set[p->data - min] == 1) {
            pre->next = p->next;
            delete p;
            p = pre->next;
        } else {
            pre = pre->next;
            p = p->next;
        }
    }
    delete[] set;
}

void test(ElemType arr1[], int length1, ElemType arr2[], int length2) {
    LinkList A = rearInsertCreate(arr1, length1);
    LinkList B = rearInsertCreate(arr2, length2);
    complementarySet(A, B);
    outPut(A);
}

int main() {
    ElemType arr1[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length1 = sizeof(arr1) / sizeof(arr1[0]);
    ElemType arr2[] = {2, 3, 4};
    int length2 = sizeof(arr2) / sizeof(arr2[0]);

    test(arr1, length1, arr2, length2);

    return 0;
}

// 输出结果：
// 0 6 8 1 5 7 9
