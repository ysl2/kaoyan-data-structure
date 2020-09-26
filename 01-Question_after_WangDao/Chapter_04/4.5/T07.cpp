
// 2020-09-24
int getLayer(BSTree T, BSTNode *s) {
    if (T == NULL)
        return 0;
    int layer = 1;
    BSTNode *p = T;
    while (p != NULL && s->data != p->data) {
        if (p->data < s->data)
            p = p->rchild;
        else
            p = p->lchild;
        layer++;
    }
    return (p == NULL) ? -1 : layer;
}

//------------------------------------------
int getLevel(BiTree T, BSTNode *s) {
    if (T == NULL) {
        return 0;
    }
    int n;
    BiTree p = T;
    for (n = 1; p->data != s->data; n++) {
        if (p->data < s->data) {
            p = p->rchild;
        } else {
            p = p->lchild;
        }
    }
    return n;
}
