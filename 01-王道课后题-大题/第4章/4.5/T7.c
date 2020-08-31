int getLevel(BiTree T, BSTNode *s) {
    if (T == NULL) {
        return 0;
    }
    int n;
    BiTree p = T;
    for (n = 1 ; p->data != s->data; n++) {
        if (p->data < s->data) {
            p = p->rchild;
        } else {
            p = p->lchild;
        }
    }
    return n;
}

