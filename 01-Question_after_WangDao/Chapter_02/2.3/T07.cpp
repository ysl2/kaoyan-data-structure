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

bool deleteList(LinkList &L, ElemType s, ElemType t) {
    if (L == NULL || L->next == NULL || s >= t)
        return false;
    LinkNode *pre = L;
    LinkNode *p = L->next;
    while (p != NULL) {
        if (p->data >= s && p->data <= t) {
            pre->next = p->next;
            delete p;
            p = pre->next;
        } else {
            pre = pre->next;
            p = p->next;
        }
    }
    return true;
}

void test(ElemType a[], int length) {
    LinkList L = rearInsertCreate(a, length);
    outPut(L);
    deleteList(L, 3, 5);
    outPut(L);
}

int main() {
    ElemType arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(arr) / sizeof(int);

    test(arr, length);

    return 0;
}

// 输出结果：
// 1 2 3 4 5 6 7 8 9
// 1 2 6 7 8 9

//----------------------------------------------------------------------
void delete(LinkList &L, ElemType s, ElemType t) {
    if (L == NULL || L->next == NULL|| s >= t) {
        return false;
    }
    LinkNode *p = L->next;
    LinkNode *pre = L;
    whlie (p != NULL) {
        if (p->data > s && p->data < t) {
            deleteNode(L, pre, p);
        } else {
            pre = pre->next;
            p = p->next;
        }
    }
}

void deleteNode(LinkList &L, LinkNode *pre, LinkNode *p) {
    LinkNode *temp = p->next;
    pre->next = temp;
    free(p);
    p = temp;
}

