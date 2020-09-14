#include <cstdlib>  // 这个库中存放了NULL常量值。如果不引入这个，需要自己定义NULL为0.否则系统会因找不到NULL而报错
typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

bool insertList(LinkList &L, LinkNode *pre, LinkNode *s) {  // pre是待插入位置结点的前驱
    if (L == NULL || pre == NULL)  //如果L是带头结点的，这应该还要加一句L->next == NULL。先简单在这里这么写，等考试的时候灵活处理
        return false;
    s->next = pre->next;
    pre->next = s;
    return true;
}
