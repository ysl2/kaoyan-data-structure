int get(BiTree T) {
    if (T == NULL)
        return 0;
    else if (T->lchid != NULL && T->rchild != NULL)
        return get(T->lchild) + get(T->rchild) + 1;
    else  // T是单分支或叶子
        return get(T->lchild) + get(T->rchild);
}
