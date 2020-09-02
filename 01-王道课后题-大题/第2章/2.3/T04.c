// 2020-09-02 第二次修订
void deleteMin(LinkList &L) {
// 本题中，p和minp并不是必须要定义的。但是pre和minpre是必须要有的。
// 原因是对链表操作必须获取前驱节点，否则在删除结点后无法连接
    if (L == NULL || L->next == NULL) return ;
    LinkNode *pre = L, *p = L->next;
    LinkNode *minpre = L, *minp = L->next;
    while (p != NULL) {
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    delete(L, pre);
}

void delete(LinkList &L, LinkNode *&pre) {
    LinkNode *temp = pre->next;
    pre->next = pre->next->next;
    free(temp);
}

-------------------------------------------
void deleteMin(LinkList &L) {
    LinkNode *pre = L, *p = L->next;
    LinkNode *minpre = pre, *minp = p;
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

