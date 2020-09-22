// 2020-09-22
int getDepth(BiTree T) {
    if (T == NULL)
        return 0;
    Queue Q;  // 初始时front和rear都是-1
    EnQueue(Q, T);
    int count = 0;  // 用来记录每层的最后一个结点
    int level = 0;
    while (!QueueEmpty(Q)) {
        int p;
        Pop(Q, p);
        if (p->lchild != NULL)
            EnQueue(p->lchild);
        if (p->rchild != NULL)
            EnQueue(p->rchild);
        if (count == Q.front) {  // 这是当前层的最后一个结点
            level++;
            count = Q.rear;  // 重置count
        }
    }
    return level;
}

//----------------------------------
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
            last = rear;
        }
    }
    return level;
}
