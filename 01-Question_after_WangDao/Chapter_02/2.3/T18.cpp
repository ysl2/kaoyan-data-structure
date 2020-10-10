// 2020-10-10
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct CLinkNode {  // Circle
    ElemType data;
    struct CLinkNode *next;
} CLinkNode, *CLinkList;

void outPut(CLinkList L) {
    CLinkNode *p = L->next;
    while (p != L) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

CLinkList rearInsertCreateCircleList(ElemType arr[], int length) {
    CLinkList L = new CLinkNode;
    CLinkNode *r = L;
    for (int i = 0; i < length; i++) {
        CLinkNode *s = new CLinkNode;
        s->data = arr[i];
        r->next = s;
        r = s;
    }
    r->next = L;
    return L;
}

void appendList(CLinkList &A, CLinkList &B) {
    if (A == NULL || B == NULL || B->next == B)
        return;
    CLinkNode *p = A;
    while (p->next != A)
        p = p->next;
    CLinkNode *q = B;
    while (q->next != B)
        q = q->next;
    p->next = B->next;
    q->next = A;
    delete B;
}

void test(int arr1[], int length1, int arr2[], int length2) {
    CLinkList A = rearInsertCreateCircleList(arr1, length1);
    CLinkList B = rearInsertCreateCircleList(arr2, length2);

    appendList(A, B);

    outPut(A);
}

int main() {
    ElemType arr1[] = {1, 2, 3, 4};
    int length1 = sizeof(arr1) / sizeof(int);
    ElemType arr2[] = {5, 6, 7, 8};
    int length2 = sizeof(arr2) / sizeof(int);
    ElemType arr3[] = {};
    int length3 = sizeof(arr3) / sizeof(int);

    test(arr1, length1, arr2, length2);
    test(arr1, length1, arr3, length3);
    test(arr3, length3, arr1, length1);

    return 0;
}

// 输出结果：
// 1 2 3 4 5 6 7 8
// 1 2 3 4
// 1 2 3 4


// ---------------------------------------------------------------------------
// 2020.08.30 第二次修订
void getLink(CLinkList &h1, CLinkList &h2) {
    // C表示Circle，指循环单链表
    CLinkNode *p = h1->next;
    while (p->next != h1) {
        p = p->next;
    }
    CLinkNode *q = h2->next;
    while (q->next != h2) {
        q = q->next;
    }
    p->next = h2;
    q->next = h1;
}


// ---------------------------------------------------------------------------
LinkList Link(LinkList &A, LinkList &B) {
    LinkNode *p, *q;
    p = A;
    while (p->next != A) {
        p = p->next;
    }
    q = B;
    while (q->next != B) {
        q = q->next;
    }
    p->next = B;
    q->next = A;
    return A;
}

