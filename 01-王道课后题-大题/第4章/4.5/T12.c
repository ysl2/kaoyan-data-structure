BSTNode *Search_Small(BSTree T, int k) {
    //在以T为根的子树上寻找第k小的元素，返回其所在结点的指针。k从1开始计算
    //在树结点中增加一个count数据成员，存储以该结点为根的子树的结点个数
    if (k < 1 || k > T->count)
        return NULL;
    if (T->lchild == NULL) {
        if (k == 1)
            return T;
        else
            return Search_Small(T->rchild, k - 1);
    } else {  // T->lchild != NULL
        if (T->lchild->count == k - 1)
            return T;
        if (T->lchild->count > k - 1)
            return Search_Small(T->lchild, k);
        if (T->lchild->count < k - 1)
            return Search_Small(T->rchild, k - (T->lchild->count + 1));
    }
}

