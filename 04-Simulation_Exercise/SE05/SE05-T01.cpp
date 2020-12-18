#include <string.h>
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

// 集合补集运算算法：A = A - B
// 本题是求补集运算，参考山大算法真题2008-T01
//! 但是山大那个题没有说是有序的，本题已经告诉了元素是递增有序
void complementarySet(LinkList &A, LinkList B) {
    LinkNode *p = A->next;
    LinkNode *q = B->next;
    LinkNode *pre = A;
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            pre = p;
            p = p->next;
        } else if (p->data > q->data) {
            q = q->next;
        } else {
            pre->next = p->next;
            LinkNode *temp = p;
            p = p->next;
            free(temp);
        }
    }
}

void test(ElemType arr1[], int length1, ElemType arr2[], int length2) {
    LinkList A = rearInsertCreate(arr1, length1);
    LinkList B = rearInsertCreate(arr2, length2);
    complementarySet(A, B);
    outPut(A);
}

int main() {
    ElemType arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length1 = sizeof(arr1) / sizeof(arr1[0]);
    ElemType arr2[] = {2, 3, 4};
    int length2 = sizeof(arr2) / sizeof(arr2[0]);

    test(arr1, length1, arr2, length2);

    return 0;
}

// 输出结果：
// 0 1 5 6 7 8 9
