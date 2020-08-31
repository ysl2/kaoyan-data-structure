LinkList crack(LinkList L) {
    LinkList B = (LinkList) malloc(sizeof(LinkNode));
    B->next = NULL;
    LinkNode *p = L->next;
    L->next = NULL;  // 把L摘下来
    LinkNode *r = L;  // L的工作指针。B因为是尾插，所以不需要工作指针
    while (p != NULL) {
        // L表尾插
        r->next = p;
        r = r->next;
        // 过渡语句1
        p = p->next;
        LinkNode *temp = p->next;
        // B表头插
        p->next = B->next;
        B->next = p;
        // 过渡语句2
        p = temp;
    }
    r->next = NULL;
    return B;
}

