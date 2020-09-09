int EnQueue(Stack &S1, Stack &S2, ElemType x) {
    if (StackOverflow(S1) && !StackEmpty(S2)) {
        return 0;  // 队列满
    }
    if (StackOverflow(S1) && StackEmpty(s2)) {
        ElemType temp;
        while (!StackEmpty(S1)) {
            Pop(S1, temp);
            Push(S2, temp);
        }
    }
    //剩下的情况是S1没满：（此时S2可能是空或满）
    Push(S1, x);
    return 1;
}

int DeQueue(Stack &S1, Stack &S2, ElemType &e) {
    if (StackEmpty(S1) && StackEmpty(S2)) {
        return 0;  // 队列空
    }
    if (StackEmpty(S2)) {
        while(!StackEmpty(S1)) {
            Pop(S1, e);
            Push(S2, e);
        }
    }
    // 剩下的情况是S2不空：（此时S1可能是空或满）
    Pop(S2, e);
    return 1;
}

int QueueEmpty(Stack S1, Stack S2) {
    return (StackEmpty(S1) && StackEmpty(S2))? 1 : 0;
}

