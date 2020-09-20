// 2020-09-20 第二次修订
// A是先序遍历序列，B是中序遍历序列
// preFirst preLast为先序的第一个结点和最后一个结点的下标，inFirst inLast是中序的第一个结点和最后一个结点的下标
BiTree preInCreate(ElemType A[], ElemType B[], int preFirst, int preLast, int inFirst, int inLast) {
    // 初始调用时，preFirst = inFirst = 1， preLast = inLast = n
    BiTNode root = new BiTNode;
    root->data = A[preFirst];
    int i;
    for (i = inFirst; B[i] != root->data; i++)
        ;
    int lchildlen = i - inFirst;
    int rchildlen = inLast - i;
    if (lchildlen >= 0)
        root->lchild = preInCreate(A, B, preFirst + 1, preFirst + lchildlen, inFirst, inFirst + lchildlen - 1);
    else
        root->lchild = NULL;
    if (rchildlen>= 0)
        root->rchild = preInCreate(A, B, preLast - rchildlen + 1, preLast, inLast - rchildlen + 1, inLast);
    else
        root->rchild = NULL;
    return root;
}

//---------------------------------------------------------------------------------------

BiTree preInCreate(ElemType A[], ElemType B[], int preFirst, int preLast, int inFirst, int inLast) {
// preFirst和preLast是先序的第一和最后一个结点下标，inFirst和inLast是中序的第一和最后一个结点下标
// 初始调用时，preFirst = inFirst = 1, preLast = inLast = n
    BiTNode *root = (BiTNode *) malloc(sizeof(BiTNode));
    root->data = A[preFirst];
    int i;
    for (i = inFirst; B[i] != root->data; i++);
    int lchildLen = i - inFirst;
    int rchildLen = inLast - i;
    if (lchildLen != 0) {
        root->lchild = preInCreate(A, B, preFirst + 1, preFirst + lchildLen, inFirst, inFirst + lchildLen - 1);
    } else {
        root->lchild = NULL;
    }
    if (rchildLen != 0) {
        root->rchild = preInCreate(A, B, preLast - rchildLen + 1, preLast, inLast - rchildLen + 1, inLast);
    } else {
        root->rchild = NULL;
    }
    return root;
}

