void PostOrder(BiTree T) {
    Stack S;
    InitStack(S);
    BiTNode *p = T, *r = NULL;
    while (p != NULL || !IsEmpty(S)) {
        if (p != NULL) {
            Push(S, p);
            p = p->lchild;
        } else {
            GetTop(S, p);
            if (p->rchild != NULL && p->rchild != r) {
                p = p->rchild;
                Push(S, p);
                p = p->lchild;
            } else {
                Pop(S, p);
                visit(p->data);
                r = p;
                p = NULL;
            }
        }
    }
}

