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

