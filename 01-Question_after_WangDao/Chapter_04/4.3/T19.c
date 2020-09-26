int wpl(BiTree T) {
    int wpl = 0;
    wplPreOrder(T, 0, wpl);
    return wpl;
}

// 二叉树的带权路径长度：指叶节点的带权路径长度。如果不是叶节点，不计算
int wplPreOrder(BiTree T, int depth, int &wpl) {
    if (T == NULL)
        return;
    if (T->lchild == NULL && T->rchild == NULL)
        wpl += depth * T->weight;
    if (T->lchild != NULL)
        wplPreOrder(T->lchild, depth + 1, wpl);
    if (T->rchild != NULL)
        wplPreOrder(T->rchild, depth + 1, wpl);
}
