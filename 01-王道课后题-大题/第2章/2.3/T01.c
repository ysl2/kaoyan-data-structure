void delete(LinkList &L, ElemType x) {
    if (L == NULL) {
        return ;
    }
    if (L->data == x) {
        LinkNode *temp = L;
        L = L->next;
        free(temp);
        delete(L, x);
    } else {
        delete(L->next, x);
    }
}

