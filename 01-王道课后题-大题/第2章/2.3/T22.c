typedef char ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

LinkList A;
LinkList B;

int getLength(LinkNode *p) {  
// 这里的p是形参，因此此函数对p的改变不会影响实参p的值
// 长度不包括头结点。所以传入时应该传第一个有效的结点A->next或B->next
    int i = 0;
    while (p != NULL) {
        p = p->next;
        i++;
    }
    return i;
}

void getCommon(LinkList &A, LinkList &B) {
    int len1 = getLength(A->next);
    int len2 = getLength(B->next);
    LinkNode *p = A, *q = B;
    // 下面这两个for只会执行一个
    for ( ; len1 > len2; len1--) {
        p = p->next;
    }
    for ( ; len2 > len1; len2--) {
        q = q->next;
    }
    while ((p->next != NULL) && p->next->data != q->next->data) {
        p = p->next;
        q = q->next;
    }
    return p->next;
}

