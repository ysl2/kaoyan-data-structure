#define NULL 0
typedef int ElemType;
typedef struct CLinkNode {
    ElemType data;
    struct CLinkNode *next;
} CLinkNode, *CLinkList;

bool initList(CLinkList &L) {
    L = new CLinkNode;
    if (L == NULL)
        return false;
    L->next = L;
    return true;
}

bool empty(CLinkList L) {
    return L->next == L;
}

bool isTail(CLinkList L, CLinkNode *p) {
    return p->next == L;
}
