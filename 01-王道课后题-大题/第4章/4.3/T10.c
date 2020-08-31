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

