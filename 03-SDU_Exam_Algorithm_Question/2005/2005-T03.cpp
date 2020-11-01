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

LinkNode *getTail(LinkList L) {
    LinkNode *tail = L;
    while (tail->next != NULL)
        tail = tail->next;
    return tail;
}

bool enQueue(LinkList &L, LinkNode *&tail, ElemType x) {
    LinkNode *temp = new LinkNode;
    if (!temp)
        return false;
    temp->data = x;
    temp->next = NULL;
    tail->next = temp;
    tail = tail->next;
    return true;
}

bool deQueue(LinkList &L, LinkNode *&tail, ElemType &e) {
    if (L->next == NULL)
        return false;
    e = L->next->data;
    LinkNode *temp = L->next;
    L->next = temp->next;
    delete temp;
    return true;
}

int main() {
    ElemType arr[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(arr) / sizeof(int);

    LinkList L = rearInsertCreate(arr, length);
    LinkNode *tail = getTail(L);

    outPut(L);

    enQueue(L, tail, 10);

    outPut(L);

    ElemType result;
    deQueue(L, tail, result);

    cout << result << endl;
    outPut(L);

    return 0;
}

// 输出结果：
// 0 2 4 6 8 1 3 5 7 9
// 0 2 4 6 8 1 3 5 7 9 10
// 0
// 2 4 6 8 1 3 5 7 9 10
