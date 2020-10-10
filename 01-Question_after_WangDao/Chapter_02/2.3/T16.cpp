// 2020-10-10
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct DCLinkNode {  // Double Circle
    ElemType data;
    struct DCLinkNode *pre, *next;
} DCLinkNode, *DCLinkList;

void outPut(DCLinkList L) {
    DCLinkNode *p = L->next;
    while (p != L) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void reverseOutPut(DCLinkList L) {
    DCLinkNode *p = L->pre;
    while (p != L) {
        cout << p->data << " ";
        p = p->pre;
    }
    cout << endl;
}

DCLinkList rearInsertCreateDoubleCircleList(ElemType arr[], int length) {
    DCLinkList L = new DCLinkNode;
    DCLinkNode *r = L;
    for (int i = 0; i < length; i++) {
        DCLinkNode *s = new DCLinkNode;
        s->data = arr[i];
        r->next = s;
        s->pre = r;
        r = s;
    }
    r->next = L;
    L->pre = r;
    return L;
}

bool isSym(DCLinkList L) {
    if (L->next == L || L->next->next == L)
        return false;
    DCLinkList p = L->next;
    DCLinkList q = L->pre;
    while ((p != q && p->next != q) && p->data == q->data) {
        p = p->next;
        q = q->pre;
    }
    return (p == q || ((p->next == q) && (p->data == q->data)));
}

void test(int arr[], int length) {
    DCLinkList A = rearInsertCreateDoubleCircleList(arr, length);

    if (isSym(A))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

int main() {
    ElemType arr1[] = {1, 2, 3, 4, 4, 3, 2, 1};
    int length1 = sizeof(arr1) / sizeof(int);
    ElemType arr2[] = {1, 2, 3, 4, 5, 3, 2, 1};
    int length2 = sizeof(arr2) / sizeof(int);
    ElemType arr3[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    int length3 = sizeof(arr3) / sizeof(int);
    ElemType arr4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length4 = sizeof(arr4) / sizeof(int);
    ElemType arr5[] = {1};
    int length5 = sizeof(arr5) / sizeof(int);

    test(arr1, length1);
    test(arr2, length2);
    test(arr3, length3);
    test(arr4, length4);
    test(arr5, length5);

    return 0;
}

// 输出结果：
// true
// false
// true
// false
// false


//---------------------------------------------------------------
// 注意：本题假定无头结点
bool pattern(LinkList A, LinkList B) {
	if (A == NULL || B == NULL) return false;
    LinkNode *p = A, *pre = A;
    LinkNode *q = B;
    while (p != NULL && q != NULL) {
        if (p->data == q->data) {
            p = p->next;
            q = q->next;
        } else {
            pre = pre->next;
            p = pre;
            q = B;
        }
    }
    return q == NULL;
}

