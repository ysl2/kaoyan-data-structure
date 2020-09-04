// 2020-09-04 第二次修订
void sort(LinkList &L) {
// 采用直接插入排序的思想
    LinkNode *p = L->next->next;
    L->next->next = NULL;
    while (p != NULL) {
        // 寻找插入位置
        LinkNode *pre = L;
        for ( ; pre->next != NULL && pre->next->data < p->data; pre = pre->next);
        // 记录p的下一个位置
        LinkNode *temp = p->next;
        // 头插法
        p->next = pre->next;
        pre->next = p;
        // 把p恢复到下一个位置
        p = temp;
    }
}


------------------------------------------------------------
void sort(LinkList &L) {
    LinkNode *p = L->next->next;
    L->next->next = NULL;
    while (p != NULL) {
        LinkNode *pre = L;
        LinkNode *temp = p->next;
        while (pre->next != NULL && pre->next->data < p->data) {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = temp;
    }
}

