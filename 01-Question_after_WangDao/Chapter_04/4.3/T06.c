// 2020-09-20 第二次修订
// A是先序遍历序列，B是中序遍历序列
// preFirst preLast为先序的第一个结点和最后一个结点的下标，inFirst inLast是中序的第一个结点和最后一个结点的下标
BiTree createTree(ElemType A[], ElemType B[], int preFirst, int preLast, int inFirst, int inLast) {
    BiTree T = new BiTNode;
    T->data = A[preFirst];
    int i;
    for (i = inFirst; B[i] != T->data; i++)
        ;
    int lchildlen = i - inFirst;
    int rchildlen = inLast - i;
    if (lchildlen >= 0)
        T->lchild = createTree(A, B, preFirst + 1, preFirst + lchildlen, inFirst, inFirst + lchildlen - 1);
    else
        T->lchild == NULL;
    if (rchildlen >= 0)
        T->rchild = createTree(A, B, preLast - rchildlen + 1, preLast, inLast - rchildlen + 1, inLast);
    else
        T->rchild = NULL;
    return T;
}

