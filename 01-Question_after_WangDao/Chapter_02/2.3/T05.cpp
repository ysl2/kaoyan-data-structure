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

LinkList rearInsertCreate(ElemType arr[], int length) {
    LinkList L = new LinkNode;
    LinkNode *p = L;
    for (int i = 0; i < length; i++)
        rearInsert(p, arr[i]);
    p->next = NULL;
    return L;
}

// 创建新结点
bool reverseList1(LinkList &L) {
    if (L == NULL || L->next == NULL)
        return false;
    LinkList B = new LinkNode;
    B->next = L->next;
    L->next = NULL;
    while (B->next != NULL) {
        LinkNode *p = B->next;
        B->next = p->next;
        p->next = L->next;
        L->next = p;
    }
    delete B;
    return true;
}

// 不创建新结点
void reverseList2(LinkList &L) {
    LinkNode *p = L->next;
    L->next = NULL;
    while (p != NULL) {
        LinkNode *temp = p->next;
        p->next = L->next;
        L->next = p;
        p = temp;
    }
}

void test(ElemType a[], int length, int index) {
    LinkList L = rearInsertCreate(a, length);
    if (index == 1)
        reverseList1(L);
    else
        reverseList2(L);
    outPut(L);
    cout << endl;
}

int main() {
    ElemType arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(arr) / sizeof(int);

    test(arr, length, 1);
    test(arr, length, 2);

    return 0;
}

// 输出结果：
// 9 8 7 6 5 4 3 2 1

// 9 8 7 6 5 4 3 2 1


// //-----------------------------------------------
// void headInsert(LinkList &L, LinkNode *&p) {
//     LinkNode *temp = p->next;
//     p->next = L->next;
//     L->next = p;
//     p = temp;
// }

// void reverse(LinkList &L) {
//     LinkNode *p = L->next;
//     L->next = NULL;
//     while (p != NULL)
//         headInsert(L, p);
// }
