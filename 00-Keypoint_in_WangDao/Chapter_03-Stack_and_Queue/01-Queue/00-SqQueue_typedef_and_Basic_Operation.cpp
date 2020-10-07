typedef int ElemType;
typedef struct {
    ElemType *data;  // 数组长度的声明必须比length多一个。原因见下方
    int front = 0, rear = 0;
    int length;  // 注意：Q。length和普通的length是不一样的。Q.length = length + 1 原因见下方
} SqQueue;

bool queueEmpty(SqQueue Q) {
    return Q.front == Q.rear;
}

bool queueFull(SqQueue Q) {
    return (Q.rear + 1) % Q.length == Q.front;
}

bool EnQueue(SqQueue &Q, ElemType x) {
    if (queueFull(Q))
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % Q.length;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &e) {
    if (queueEmpty(Q))
        return false;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % Q.length;
    return true;
}

// 创建一个有效长度为length的循环队列
// 由于最后的判满条件需要占用一个位置，因此虽然定义的队列的数组是(length + 1)的长度，但是实际可用长度只有length
void initQueue(SqQueue &Q, ElemType *arr, int length) {
    Q.data = new ElemType[length + 1];
    Q.length = length + 1;  // Q.length与length不一样
    for (int i = 0; i < length; i++)
        EnQueue(Q, arr[i]);
}
