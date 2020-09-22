int similar(BiTree A, BiTree B) {
    if (A == NULL && B == NULL)
        return 1;
    if (A == NULL || B == NULL)
        return 0;
    int left = similar(A->lchild, B->lchild);
    int right = similar(A->rchlid, B->rchild);
    return left && right;
}
