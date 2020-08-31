LinkList disc(LinkList &L) {
    LinkList B = (LinkList) malloc(sizeof(LinkNode));
    B->next = NULL;
    LinkNode *pre1 = L, *pre2 = B, *p = L->next;
    L->next = NULL;
    // i表示序号，从1开始计算
    for (int i = 1; p != NULL; p = p->next, i++) {
        if (i % 2 == 1) {
            pre1->next = p;
            pre1 = p;
        } else {
            pre2->next = p;
            pre2 = p;
        }
    }
    pre1->next = NULL;
    pre2->next = NULL;
    return B;
}

