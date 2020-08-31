void delete(LinkList &L) {
    if (p == NULL) {
        return ;
    }
    LinkNode *p = L->next;
    while (p->next != NULL) {
        LinkNode *q = p->next;
        if (p->data == q->data) {
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
}

