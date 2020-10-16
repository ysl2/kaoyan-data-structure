void BiTreeToExpression(BiTree T) {
    InOrder(T, 1);
}

void InOrder(BiTree T, int depth) {
    if (T == NULL)
        return;
    if (T->lchlid == NULL && T->rchild == NULL) {
        printf("%s", T->data);
        return;  // 一定不要漏这个return，不然程序直接出错
    }

    if (depth > 1)
        printf("(");

    // 中序遍历模板
    InOrder(T->lchild, depth + 1);
    printf("%s", T->data);
    InOrder(T->rchild, depth + 1);
    //

    if (depth > 1)
        printf(")");
}
