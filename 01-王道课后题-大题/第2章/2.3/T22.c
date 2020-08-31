typedef struct Node{
    char data;
    struct Node *next;
} LinkNode, *LinkList;

int getlen(LinkNode *work) {
    int len = 0;
    while (work != NULL) {
        len++;
        work = work->next;
    }
    return len;
}

LinkNode find_addr(LinkNode *str1, LinkNode *str2) {
    int len1, len2;
    LinkNode *p = str1, *q = str2;
    len1 = getlen(str1);
    len2 = getlen(str2);
    for ( ; len1 > len2; len1--) {
        p = p->next;
    }
    for ( ; len2 > len1; len2--) {
        q = q->next;
    }
    while ((p->next != NULL) && (p->next->data != q->next->data)) {
        p = p->next;
        q = q->next;
    }
    return p->next;
}


