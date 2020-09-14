#include <cstdlib>  // 这个库中存放了NULL常量值。如果不引入这个，需要自己定义NULL为0.否则系统会因找不到NULL而报错
typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

//删除p所指的结点
// 这种方式不需要找到p的前驱结点，时间复杂度为O(1)
bool deleteList1(LinkList &L, LinkNode *p) {
    if (L == NULL || p == NULL)
        return false;
    LinkNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    delete q;
    return true;
}

// 这种方式需要找到要删除结点的前驱结点pre，时间复杂度为O(1)
// 如果用这种方式，如果题目没给前驱结点，需要自己遍历一遍才行。此时时间复杂度为O(n)
bool deleteList2(LinkList &L, LinkNode *pre) {
    if (L == NULL || pre == NULL || pre->next == NULL)
        return false;
    LinkNode *p = pre->next;
    pre->next = p->next;
    delete p;
    return true;
}
