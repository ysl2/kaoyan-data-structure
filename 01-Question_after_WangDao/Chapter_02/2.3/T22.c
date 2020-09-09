// 2020-09-07 第二次修订
typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

LinkList A;
LinkList B;

int getLen(LinkList L) {
// 这里的p是形参，因此此函数对p的改变不会影响实参p的值
    int i = 0;
    for ( ; L->next != NULL; L = L->next, i++);
    return i;
}

LinkNode *get(LinkList A, LinkList B) {  // 注意，是返回指针的函数
    if ((A == NULL || A->next == NULL) || (B == NULL || B->next == NULL)) return NULL;
    int len1 = getLen(A), len2 = getLen(B);
    // p和q都是前驱指针：
    LinkNode *p = A;
    LinkNode *q = B;
    // 下面这两个for只会执行一个：
    for ( ; len1 > len2; p = p->next, len1--);
    for ( ; len1 < len2; q = q->next, len2--);
    // 现在两个指针对齐了，就一直往后跑直到碰头为止
    // 由于当p->next是NULL的时候，q->next也一定是NULL，因此判空只需要判其中一个即可
    for ( ; p->next != NULL && p->next->data != q->next->data; p = p->next, q = q->next);
    return p->next;
}


----------------------------------------------------------------------------------------
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

