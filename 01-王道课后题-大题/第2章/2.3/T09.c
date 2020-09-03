// 方法1：双指针
bool minDelete1(LinkList &L) {
	if (L == NULL || L->next == NULL) return false;
    LinkNode *minp, *p;
    // minp是元素最小值结点的前驱结点的指针
    while (L->next != NULL) {
        minp = L;
        p = L->next;
        while (p->next != NULL) {
            if (p->next->data < minp->next->data) {
                minp = p;
            }
            p = p->next;
        }
        visit(minp->next);
        LinkNode *temp = minp->next;
        minp->next = minp->next->next;
        free(temp);
    }
    free(L);
	return true;
}
// 方法2：四指针。思想相同，但是增加了代码可读性
bool minDelete(LinkList &L) {
    if (L == NULL || L->next == NULL) return false;
    LinkNode *p, *pre, *minp, *minpre;
    while (L->next != NULL) {
        p = L->next;
        pre = L;
        minp = L->next;
        minpre = L;
        while (p != NULL) {
            if (p->data < minp->data) {
                minp = p;
                minpre = pre;
            }
            pre = p;
            p = p->next;
        }
        visit(minp);
        minpre->next = minp->next;
        free(minp);
    }
    free(L);
    return true;
}

