void PostOrder(BiTree T) {
    InitStack(S);
    BiTNode *p = T;
    BiTNode *r = NULL;
    while (p != NULL || !StackEmpty(S)) {
        if (p != NULL) {
            Push(S, p);
            p = p->lchild;
            continue;
        }
        GetTop(S, p);
        if (p->rchild != NULL && p->rchlid != r) {
            p = p->rchild;
            continue;
        }
        Pop(S, p);
        visit(p);
        r = p;
        p = NULL;
    }
}

