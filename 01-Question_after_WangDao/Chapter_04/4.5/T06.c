int prior = -99999;  // 负无穷大
int isBST(BiTree T) {  //基于中序遍历
    if (T == NULL)
        return 1;
    //left
    int left = isBST(T->lchild);
    //root
    if (left == 0 || prior >= T->data)
        return 0;
    prior = T->data;
	//right
    return isBST(T->rchild);
}

