// 2020-09-21 第二次修订
int count = 0;
Elemtype getData(BiTree T, int k) {
    if (T == NULL)
        return NULL;
    if (count == k)
        return T->data;
    k++;
    int result;
    if (T->lchild != NULL)
        result = getData(T->lchild, k);
    if (result != NULL && T->rchild != NULL)
        return getData(T->rchild, k);
    return result;
}

//---------------------------------------
int i = 1;
ElemType PreNode(BiTree T, int k) {
    if (T == NULL) {
        return '#';  // 表示空结点
    }
    if (i == k) {
        return T->data;
    }
    i++;
    ElemType ch = PreNode(T->lchild, k);
    if (ch == '#') {
        ch = PreNode(T->rchild , k);
    }
    return ch;
}

