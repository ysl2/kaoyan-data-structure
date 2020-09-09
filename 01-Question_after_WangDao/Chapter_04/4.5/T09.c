ElemType getMax(BSTree T) {
    if (T == NULL) {
        return NULL;
    }
    BSTNode *p = T;
    while (p->rchild != NULL) {
        p = p->rchild;
    }
    return p->data;
}

ElemType getMin(BSTree T) {
    if (T == NULL) {
        return NULL;
    }
    BSTNode *p = T;
    while (p->lchild != NULL) {
        p = p->lchild;
    }
    return p->data;
}

