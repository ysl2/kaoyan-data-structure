void reverse(Stack S, Queue Q) {
	ElemType temp;
    while (!QueueEmpty(Q)) {
        DeQueue(Q, temp);
        Push(S, temp);
    }
    while (!StackEmpty(S)) {
        Pop(S, temp);
        EnQueue(Q, temp);
    }
}

