void deleteMin(LinkList &L) {
    LinkNode *pre = L, *p = L->next;
    LinkNode *minpre = pre, *minp = p;
    while (p != NULL) {
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
}

