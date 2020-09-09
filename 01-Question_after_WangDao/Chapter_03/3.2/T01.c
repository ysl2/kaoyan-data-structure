int EnQueue(SqQueue &Q, ElemType x) {
    if (Q.front == Q.rear && Q.tag == 1) {
        return 0;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % maxSize;
    Q.tag = 1;
    return 1;
}

int DeQueue(SqQueue &Q, ElemType &x) {
    if (Q.front == Q.rear && Q.tag == 0) {
        return 0;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % maxSize;
    Q.tag = 0;
    return 1;
}

