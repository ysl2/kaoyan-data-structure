void deletex(LinkList &L, ElemType x) {
    LinkNode *pre, *p, *q;
    pre = L, p = L->next;
    while (p != NULL) {
        if (p->data == x) {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        } else {
            pre = p;
            p = p->next;
        }
    }
}

