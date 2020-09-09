void headInsert(LinkList &L, LinkNode *p) {
    // 将p指向的结点从其后续结点中分离出来头插到L中
    // 然后恢复p在原先的后续结点中的0号位置
    LinkNode *temp = p->next;
    p->next = L->next;
    L->next = p;
    p = temp;
}

void merge(LinkList &A, LinkList &B) {
    LinkNode *p = A->next, *q = B->next;
    A->next = NULL;
    while (p != NULL && q != NULL) {
        if (p->data <= q->data) {
            headInsert(A, p);
        } else {
            headInsert(A, q);
        }
    }
    while (p != NULL) {
        headInsert(A, p);
    }
    while (q != NULL) {
        headInsert(A, q);
    }
    free(B);
}

