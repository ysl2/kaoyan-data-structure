void recur(LinkList L) {
    if (L == NULL) {
        return ;
    }
    recur(L->next);
    visit(L);
}

