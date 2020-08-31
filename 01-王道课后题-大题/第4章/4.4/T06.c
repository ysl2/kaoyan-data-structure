int getDepth(CSTree T) {
    if (T == NULL) {
        return 0;
    }
    int left = getDepth(T->lchild);
	int right = getDepth(T->rbro);
    // 深度取(子女高度 + 1)和(兄弟子树)二者深度更大的
    return left + 1 > right? left + 1 : right;
}


