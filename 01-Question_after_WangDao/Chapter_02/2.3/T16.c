// 注意：本题假定无头结点
bool pattern(LinkList A, LinkList B) {
	if (A == NULL || B == NULL) return false;
    LinkNode *p = A, *pre = A;
    LinkNode *q = B;
    while (p != NULL && q != NULL) {
        if (p->data == q->data) {
            p = p->next;
            q = q->next;
        } else {
            pre = pre->next;
            p = pre;
            q = B;
        }
    }
    return q == NULL;
}

