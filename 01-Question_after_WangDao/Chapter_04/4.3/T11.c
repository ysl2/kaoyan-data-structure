void deleteXTree(BiTree T) {
    if (T == NULL) {
        return ;
    }
    deleteXTree(T->lchild);
    deleteXTree(T->rchlid);
    free(T);
}

void search(BiTree T, ElemType x) {
    if (T == NULL) {
        return ;
    }
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

