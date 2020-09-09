int do(LinkList L, int n) {
    char s[n / 2];
    LinkNode *p = L->next;
	int i;
    for (i = 0, i < n / 2; i++) {
        s[i] = p->data;
        p = p->next;
    }
    i--;
    if (n % 2 == 1) {
        p = p->next;
    }
    while (p != NULL && s[i] == p->data) {
        i--;
        p = p->next;
    }
    return (i == -1)? 1 : 0;
}

