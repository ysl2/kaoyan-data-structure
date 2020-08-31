void delete(LinkList &L, ElemType s, ElemType t) {
    if (L == NULL || L->next == NULL|| s >= t) {
        return false;
    }
    LinkNode *p = L->next;
    LinkNode *pre = L;
    whlie (p != NULL) {
        if (p->data > s && p->data < t) {
            deleteNode(L, pre, p);
        } else {
            pre = pre->next;
            p = p->next;
        }
    }
}

void deleteNode(LinkList &L, LinkNode *pre, LinkNode *p) {
    LinkNode *temp = p->next;
    pre->next = temp;
    free(p);
    p = temp;
}

