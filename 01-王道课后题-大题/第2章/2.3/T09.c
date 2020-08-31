void minDelete(LinkList &L) {
    LinkNode *minp, *p;
    // minp是元素最小值结点的前驱结点的指针
    while (L->next != NULL) {
        minp = L;
        p = L->next;
        while (p->next != NULL) {
            if (p->next->data < minp->next->data) {
                minp = p;
            }
            p = p->next;
        }
        visit(minp->next->data);
        LinkNode *temp = minp->next;
        minp->next = minp->next->next;
        free(temp);
    }
    free(L);
}

