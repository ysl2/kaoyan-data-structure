// 2020-09-06 第三次修订

-------------------------------------------
void deleteMin(LinkList &L) {
	if (L == NULL) return ;
    LinkNode *p = L->next, *pre = L;
    LinkNode *minp = L->next, *minpre = L;
    while (p != NULL) {
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
}

