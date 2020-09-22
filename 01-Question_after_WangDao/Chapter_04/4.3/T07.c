// 2020-09-20 在前哥资料里的，这个是我自己写的，代码有问题，不要看这个

// bool isComplete(BiTree T) {
//     if (T == NULL)
//         return true;
//     if (T->lchild == NULL && T->rchild == NULL)
//         return true;
//     return !(T->rchild != NULL);  // 走到这里只能是二选一：要么左边是空，要么右边是空。如果左边是空，说明右边不是空。只要右边不是空，就返回false
// }

// bool LevelOrder(BiTree T) {
//     queue<BiTNode *> q;
//     if (T == NULL)
//         return true;
//     q.push(T);
//     BiTNode *p = NULL;
//     while (!q.empty()) {
//         p = q.front();
//         q.pop();
//         if (!isComplete(p))
//             return false;
//         if (p->lchild != NULL)
//             q.push(p->lchild);
//         if (p->rchild != NULL)
//             q.push(p->rchild);
//     }
//     return true;
// }

//---------------------------------------------------

// 这个是王道书里写的
bool judgeIsCompleteTree(BiTree T) {
    if (T == NULL)
        return true;
    Queue Q;
    InitQueue(Q);
    EnQueue(Q, T);
    BiTree p;
    while (!QueueEmpty(Q)) {
        DeQueue(Q, p);
        if (p != NULL) {
            EnQueue(Q, p->lchild);
            EnQueue(Q, p->rchild);
        } else {
            while (!QueueEmpty(Q)) {
                DeQueue(Q, p);
                if (p != NULL)
                    return false;
            }
        }
    }
    return true;
}

