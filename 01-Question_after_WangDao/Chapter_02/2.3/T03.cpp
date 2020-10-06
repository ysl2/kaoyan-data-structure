// 2020-10-06
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

void printList(LinkList L) {
    if (L == NULL)
        return;
    printList(L->next);
    cout << L->data << " ";
}

// ------------------------------------------------------
void recur(LinkList L) {
    if (L == NULL)
        return ;
    recur(L->next);
    visit(L);
}

