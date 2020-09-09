int wpl(BiTree T) {
    return wplPreOrder(T, 0);
}
int wplPreOrder(BiTree T, int depth) {
    static int wpl = 0;
    if (T->lchild == NULL && T->rchild == NULL) {
        wpl += depth * T->weight;
    }
    if (T->lchild != NULL) {
        wplPreOrder(T->lchild, depth + 1);
    }
    if (T->rchild != NULL) {
        wplPreOrder(T->rchild, depth + 1);
    }
    return wpl;
}

