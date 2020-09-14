#include <cstdlib>  // 这个库中存放了NULL常量值。如果不引入这个，需要自己定义NULL为0.否则系统会因找不到NULL而报错
typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

bool insertList(LinkList &L, LinkNode *pre, LinkNode *s) {  // pre是待插入位置结点的前驱
    if (L == NULL || pre == NULL)
        return false;
    s->next = pre->next;
    pre->next = s;
    return true;
}
