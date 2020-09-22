TreeLinkList L, pre = NULL;
TreeLinkList InOrder(BiTree T) {
    if (T == NULL)
        return NULL;
    InOrder(T->lchild);
    if (T->lchild == NULL && T->rchild == NULL) {
        if (pre == NULL) {
            L = T;  // 保存找到的第一个叶子结点（k指针）
            pre = T;
        } else {
            pre->rchild = T;  // 链接时用叶子结点的rchild域存放指针
            pre = T;
        }
    }
    InOrder(T->rchild);
    return L;
}

