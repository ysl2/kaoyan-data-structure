void InOrder(BiTree T) {
    Stack S;
    InitStack(S);
    BiTNode *p = T;
    while (p != NULL || !StackEmpty(S)) {
        if (p != NULL) {
            Push(S, p);
            p = p->lchild;
            continue;
        }
        Pop(S, p);
        visit(p);
        p = p->rchild;
    }
}

