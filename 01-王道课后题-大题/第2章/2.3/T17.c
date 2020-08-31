int symmetry(DLinkList L) {
    DLinkNode *p = L->next, *q = L->prior;
    while (p != q && p->next != q) {
        if (p->data == q->data) {
            p = p->next;
            q = q->prior;
        } else {
            return 0;
        }
    }
    return 1;
}

