void delete(LinkList &L) {
    if (L == NULL || L->next == NULL) {
        return ;
    }
    LinkNode *p = L->next;
    while (p->next != NULL) {
        LinkNode *temp = p->next;
        if (p->data == temp->data) {
            p->next = temp->next;
            free(temp);
        } else {
            p = p->next;
        }
    }
}



