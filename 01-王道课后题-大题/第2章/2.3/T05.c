void reverse(LinkList &L) {
    LinkNode *p = L->next;
    L->next = NULL;
    while (p != NULL) {
        headInsert(L, p);
    }
}

void headInsert(LinkList &L, LinkNode *&p) {
    LinkNode *temp = p->next;
    p->next = L->next;
    L->next = p;
    p = temp;
}

