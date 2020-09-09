void delete(LinkList &L) {
    if (L == NULL || L->next == NULL) {
        return ;
    }
    LinkNode *p = L->next;
    while (p->next != NULL) {
		if (p->data == p->next->data) {
			LinkNode *temp = p->next;
			p->next = temp->next;
            free(temp);
        } else {
            p = p->next;
        }
    }
}



