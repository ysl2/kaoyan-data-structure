// 2020.08.31 第二次修订
LinkList getLink(LinkList &A, LinkList &B) {
    LinkNode *p = A->next;
    LinkNode *q = B->next;
    LinkList C = (LinkList) malloc(sizeof(LinkNode));
    C->next = NULL;
    LinkNode *r = C;
    while (p != NULL && q != NULL) {
        if (p->data == q->data) {
            // 创建
            LinkNode *temp = (LinkNode *) malloc(sizeof(LinkNode));
            temp->data = p->data;
            // 尾插
            r->next = temp;
            r = r->next;
            // 后移
            p = p->next;
            q = q->next;
            continue;
        }
        // 后移
        if (p->data < q->data) {
            p = p->next;
        } else {
            q = q->next;
        }
    }
    // 如果A或B某一个是空的，会直接跳到这里向下执行
    r->next = NULL;
    return C;  
}
----------------------------------------------------------
LinkList getCommon(LinkList A, LinkList B) {
    LinkNode *p = A->next, *q = B->next, *r, *s;
    LinkList C = (LinkList) malloc(sizeof(LinkNode));
    r = C;
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            p = p->next;
        } else if (p->data > q->data) {
            q = q->next;
        } else {
            s = (LinkNode *) malloc(sizeof(LinkNode));
            s->data = p->data;
            r->next = s;
            r = s;
            p = p->next;
            q = q->next;
        }
    }
    r->next = NULL;
    return C;
}

