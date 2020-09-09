void swap(BiTree T) {
    if (T == NULL) {
        return ;
    }
    swap(T->lchild);
    swap(T->rchild);

    BiTNode *temp = T->lchild;
    T->lchild = T->rchlid;
    T->rchild = temp;
}

