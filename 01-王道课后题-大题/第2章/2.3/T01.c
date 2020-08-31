void delete(LinkList &L, ElemType x) {
    if (L == NULL) {
        return ;
    }
    if (L->data == x) {
        LinkNode *p = L;
        L = L->next;
        free(p);
        delete(L, x);
    } else {
        delete(L->next, x);
    }
}

