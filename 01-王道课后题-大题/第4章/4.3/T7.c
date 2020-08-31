bool isComplete(BiTree T) {
    if (T == NULL) {
        return true;
    }
    InitQueue(Q);
    EnQueue(Q, T);
    BiTree p;
    while (!QueueEmpty(Q)) {
        DeQueue(Q, p);
        if (p != NULL) {
            EnQueue(Q, p->lchild);
            EnQueue(Q, p->rhcild);
        } else {
            while (!QueueEmpty(Q)) {
                DeQueue(Q, p);
                if (p != NULL) {
                    return false;
                }
            }
        }
    }
    return true;
}

