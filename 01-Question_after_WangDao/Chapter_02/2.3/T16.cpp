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

bool isMatched(LinkList A, LinkList B) {
    if (A == NULL || B == NULL || B->next == NULL)
        return false;
    LinkNode *p = A->next;
    LinkNode *q = B->next;
    while (p != NULL) {
        LinkNode *temp = p;  // 记录一下当前的位置，因为后面还要跳转回来
        while (q != NULL && q->data == p->data) {
            p = p->next;
            q = q->next;
        }
        if (q == NULL)
            return true;
        else {
            q = B->next;
            p = temp->next;
        }
    }
    return false;
}

void test(ElemType a1[], int length1, ElemType a2[], int length2) {
    LinkList A = rearInsertCreate(a1, length1);
    LinkList B = rearInsertCreate(a2, length2);

    if (isMatched(A, B))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

int main() {
    ElemType arr1[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length1 = sizeof(arr1) / sizeof(int);
    ElemType arr2[] = {2, 4, 6, 8};
    int length2 = sizeof(arr2) / sizeof(int);
    ElemType arr3[] = {};
    int length3 = sizeof(arr3) / sizeof(int);
    ElemType arr4[] = {1, 2, 3, 4};
    int length4 = sizeof(arr4) / sizeof(int);

    test(arr1, length1, arr2, length2);
    test(arr1, length1, arr3, length3);
    test(arr1, length1, arr4, length4);

    return 0;
}

// 输出结果：
// true
// false
// false
