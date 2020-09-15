#include <cstdlib>

#include <cstdlib>
#include <iostream>
#define maxSize 20

typedef int ElemType;

typedef struct {
    ElemType *data;  // 这里将来会是一个数组
    int top = -1;
    int length;
} SqStack;

void outPut(SqStack S) {
    while (S.top != -1) {
        std::cout << S.data[S.top--] << " ";
    }
}

void initStack(SqStack &S, int length) {
    S.data = new ElemType[length];
    S.length = length;
}

bool Push(SqStack &S, ElemType x) {
    if (S.top >= S.length)
        return false;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, ElemType &x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}

bool stackEmpty(SqStack S) {
    return S.top == -1;
}

typedef struct {
    ElemType *data;
    int front = 0, rear = 0;
    int length;
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

void initQueue(SqQueue &Q, ElemType *arr, int length) {
    Q.data = new ElemType[length + 1];
    Q.length = length + 1;
    for (int i = 0; i < length; i++)
        EnQueue(Q, arr[i]);
}

void outPut(SqQueue Q) {
    while (!queueEmpty(Q)) {
        int temp;
        DeQueue(Q, temp);
        std::cout << temp << " ";
    }
    std::cout << std::endl;
}

void reverse(SqQueue &Q) {
    SqStack S;
    initStack(S, Q.length - 1);
    while (!queueEmpty(Q)) {
        ElemType temp;
        DeQueue(Q, temp);
        Push(S, temp);
    }
    while (!stackEmpty(S)) {
        int temp;
        Pop(S, temp);
        EnQueue(Q, temp);
    }
}

void test(ElemType *arr, int length) {
    SqQueue Q;
    initQueue(Q, arr, length);
    outPut(Q);
    reverse(Q);
    outPut(Q);
}

int main() {
    ElemType arr1[] = {1, 4, 6, 4, 2};
    int length1 = sizeof(arr1) / sizeof(ElemType);
    ElemType arr2[] = {};
    int length2 = sizeof(arr2) / sizeof(ElemType);
    ElemType arr3[] = {1};
    int length3 = sizeof(arr3) / sizeof(ElemType);

    test(arr1, length1);

    test(arr2, length2);

    test(arr3, length3);

    return 0;
}

// 运行结果：
// 1 4 6 4 2
// 2 4 6 4 1

// 1
// 1
