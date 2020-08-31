int treeDepth(BiTree T) {
    if (T == NULL) {
        return 0;
    }
    int front = -1, rear = -1;
    int last = 0, level = 0;
    BiTNode *Q[maxSize];
    Q[++rear] = T;
    BiTNode *p;
    while (front < rear) {
        p = Q[++front];
        if (p->lchild != NULL) {
            Q[++rear] = p->lchild;
        }
        if (p->rchild != NULL) {
            Q[++rear] = p->rchild;
        }
        if (front == last) {
            level++;
        }
        last = rear;
    }
    return level;
}

