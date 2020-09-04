LinkList crack(LinkList L) {
// L表相当于C表和A表
    LinkList B = (LinkList) malloc(sizeof(LinkNode));
    B->next = NULL;
    LinkNode *p = L->next;
    L->next = NULL;  // 把L摘下来
    LinkNode *r = L;  // L的工作指针。B因为是头插，所以不需要工作指针
    while (p != NULL) {
        // L表尾插
        r->next = p;
        r = r->next;
        // 过渡语句1
        p = p->next;
        LinkNode *temp = p->next;
        // B表头插
		// 这里不用判断p是NULL的情况。
		// 因为a和b最终下标都是n，说明C有2n个结点，一定是偶数。
        p->next = B->next;  
        B->next = p;
        // 过渡语句2
        p = temp;
    }
    r->next = NULL;
    return B;
}

