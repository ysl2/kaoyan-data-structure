LinkNode getCommon(LinkList &A, LinkList &B) {
    int len1 = getLen(A), len2 = getLen(B);
    int n = (len2 > len1)? len2 - len1 : len1 - len2;
    LinkNode *p = A->next, *q = B->next;
    for ( ; len2 > len1 && n > 0; q = q->next, n--);
    for ( ; len1 > len2 && n > 0; p = p->next, n--);
    while (p != NULL && p->data != q->data) {
        p = p->next;
        q = q->next;
    }
    return p;
}

