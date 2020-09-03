void PreOrder(BiTree T) {
    Stack S;
    InitStack(S);
    BiTree *p = T;
    while (p != NULL || !StackEmpty(S)) {
        if (p != NULL) {
            visit(p);
            Push(S, p);
            p = p->lchild;
            continue;
        }
        Pop(S, p);
        p = p->rchild;
    }
}

