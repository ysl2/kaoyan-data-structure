void sort(LinkList &L) {
    LinkNode *p = L->next->next;
    L->next->next = NULL;
    while (p != NULL) {
        LinkNode *pre = L;
        LinkNode *temp = p->next;
        while (pre->next != NULL && pre->next->data < p->data) {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = temp;
    }
}

