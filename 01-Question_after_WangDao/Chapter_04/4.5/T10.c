void outPut(BSTree T, ElemType x) {
    if (T == NULL) {
        return ;
    }
    // 从大到小输出，所以顺序是:右 根 左
    if (T->rchild != NULL) {
        outPut(T->rchild, x);
    }
    if (T->data >= k) {
        visit(T->data);
    }
    if (T->lchild != NULL) {
        outPut(T->lchild, x);
    }
}

