bool pattern(LinkList A, LinkList B) {
    LinkNode *p = A, *pre = A;
    LinkNode *q = B;
    while (p != NULL || q != NULL) {
        if (p->data == q->data) {
            p = p->next;
            q = q->next;
        } else {
            pre = pre->next;
            p = pre;
            q = B;
        }
    }
    return q == NULL;
}

