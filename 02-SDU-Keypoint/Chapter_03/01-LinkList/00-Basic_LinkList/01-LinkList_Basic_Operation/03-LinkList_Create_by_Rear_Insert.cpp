#include <cstdlib>
#include <iostream>

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

void outPut(LinkList L) {
    LinkNode *p = L->next;
    while (p != NULL) {
        std::cout << p->data << " ";
        p = p->next;
    }
}

void rearInsert(LinkList &L, ElemType x) {
    LinkNode *s = new LinkNode;
    s->data = x;
    L->next = s;
    L = s;
}

void rearInsertCreate(LinkList &L, ElemType arr[], int length) {
    L = new LinkNode;
    LinkNode *p = L;
    for (int i = 0; i < length; i++) {
        rearInsert(p, arr[i]);
    }
    p->next = NULL;
}

int main() {
    ElemType arr[] = {1, 3, 5, 7, 9};
    int length = sizeof(arr) / sizeof(int);
    LinkList L = NULL;
    rearInsertCreate(L, arr, length);
    outPut(L);
    return 0;
}

// 输出结果：
// 1 3 5 7 9
