void recursive(LinkList L) {
    if (L->next != NULL) {
        recursive(L->next);
    }
    visit(L->data);
}

