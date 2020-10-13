// https://blog.csdn.net/u013595419/article/details/52297773
// 本题可以分成两个部分来完成。第一步：查找值为x的节点；第二步：删除以值为x的节点为根节点的所有子树；
// 因为删除的是x的所有子树，因此遍历方式应该选择自上而下的遍历方式，即先序遍历或层次遍历方式，这里选择层次遍历的方式实现。
// 删除值为x的节点的所有子树，可以考虑使用递归的方式；

// 即此时可以认为删除的是以值为x的节点作为根节点的树；
// 首先删除该树的叶子节点，这样该树的倒数第二层节点又会变成新的叶子节点；
// 接着依次类推，直到值为x的节点变为叶子节点，最后删除自身便可；

// 2020-08-31
void deleteXTree(BiTree T) {
    if (T == NULL)
        return ;
    deleteXTree(T->lchild);
    deleteXTree(T->rchlid);
    free(T);
}

void search(BiTree T, ElemType x) {
    if (T == NULL)
        return ;
    if (T->data == x) {
        deleteXTree(T);
        return ;
    }
    TreeQueue Q;  // 里面存的是BiTNode指针类型的指针数组
    InitQueue(Q);
    EnQueue(Q, T);
	BiTNode *p = NULL;
    while (!QueueEmpty(Q)) {
        DeQueue(Q, p);
        if (p->lchild != NULL) {
            if (p->lchild->data == x) {
                deleteXTree(p->lchild);
                p->lchild = NULL;
            } else {
                EnQueue(Q, p->lchild);
            }
        }
        if (p->rchild != NULL) {
            if (p->rchild->data == x) {
                deleteXTree(p->rchild);
                p->rchild = NULL;
            } else {
                EnQueue(Q, p->rchild);
            }
        }
    }
}

