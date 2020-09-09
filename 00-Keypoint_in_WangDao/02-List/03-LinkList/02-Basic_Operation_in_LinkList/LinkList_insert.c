bool ListInsert(Linklist &L, int i, ElemType e) {
    if (L == NULL || i < 1) return false;
    int j = 0;
    LinkNode *p = L;  // 必须定在前驱位置，
	// 否则如果L是空表，此时在1号位置插入，
	// 会由于下面的if (p == NULL)直接返回false
    for ( ; p != NULL && j < i - 1; p = p->next, j++);
    if (p == NULL) return false;
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    if (s == NULL) return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

