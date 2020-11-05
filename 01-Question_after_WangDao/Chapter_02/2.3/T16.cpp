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

// 这个是我自己写的，原理是字符串匹配的BP算法（暴力法）
bool isMatched1(LinkList A, LinkList B) {
    if (A == NULL || A->next == NULL || B == NULL || B->next == NULL)
        return false;
    LinkNode *p = A->next;
    LinkNode *q = B->next;
    while (p != NULL) {
        LinkNode *temp = p;  // 记录一下当前的位置，因为后面还要跳转回来
        while (q != NULL && p != NULL && q->data == p->data) {
            p = p->next;
            q = q->next;
        }
        if (p == NULL)
            return false;
        if (q == NULL)
            return true;
        q = B->next;
        p = temp->next;
    }
    return false;
}

// 这是王道书上的算法
bool isMatched2(LinkList A, LinkList B) {
    if (A == NULL || A->next == NULL || B == NULL || B->next == NULL)
        return false;
    LinkNode *p = A->next, *temp = A->next;
    LinkNode *q = B->next;
    while (p != NULL && q != NULL) {
        if (p->data == q->data) {
            p = p->next;
            q = q->next;
        } else {
            temp = temp->next;
            p = temp;
            q = B->next;
        }
    }
    return q == NULL;
}

void test(ElemType a1[], int length1, ElemType a2[], int length2) {
    LinkList A = rearInsertCreate(a1, length1);
    LinkList B = rearInsertCreate(a2, length2);

    if (isMatched1(A, B))
        cout << "true" << "\t";
    else
        cout << "false" << "\t";

    if (isMatched2(A, B))
        cout << "true";
    else
        cout << "false";
    cout << endl;
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
    ElemType arr5[] = {1, 3, 5, 7, 9, 10};
    int length5 = sizeof(arr5) / sizeof(int);

    test(arr1, length1, arr2, length2);
    test(arr1, length1, arr3, length3);
    test(arr1, length1, arr4, length4);
    test(arr1, length1, arr5, length5);

    return 0;
}

// 输出结果：
// true    true
// false   false
// false   false
// false   false
