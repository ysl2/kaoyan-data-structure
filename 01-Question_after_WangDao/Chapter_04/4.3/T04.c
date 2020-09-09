void reverseLevelOrder(BiTree T) {
    if (T == NULL) {
        return ;
    }
    Stack S;
    Queue Q;
    InitQueue(Q);
    InitStack(S);
    EnQueue(Q, T);
    BiTNode *p = T;
    while (!QueueEmpty(Q)) {
        DeQueue(Q, p);
        Push(S, p);
        if (p->lchild != NULL) {
            EnQueue(Q, p->lchild);
        }
        if (p->rchild != NULL) {
            EnQueue(Q, p->rchild);
        }
    }
    while (!StackEmpty(S)) {
        Pop(S, p);
        visit(p->data);
    }
}

