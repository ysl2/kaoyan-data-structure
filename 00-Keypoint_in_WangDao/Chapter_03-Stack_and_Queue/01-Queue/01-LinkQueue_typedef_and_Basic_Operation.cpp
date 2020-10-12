#include <cstdlib>
typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode;
typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

// 这里默认链队有头结点
void initQueue(LinkQueue &Q) {
    Q.front = Q.rear = new LinkNode;
}

bool queueEmpty(LinkQueue Q) {
    return Q.front->next = NULL;
}

void EnQueue(LinkQueue &Q, ElemType x) {
    LinkNode *temp = new LinkNode;
    temp->data = x;
    temp->next = NULL;
    Q.rear->next = temp;
    Q.rear = temp;
}

bool DeQueue(LinkQueue &Q, ElemType &e) {
    if (Q.front == Q.rear)
        return false;
    if (Q.front->next == Q.rear) {
        e = Q.rear->data;
        delete Q.rear;
        Q.rear = Q.front;
        Q.front->next = NULL;
        return true;
    }
    LinkNode *temp = Q.front->next;
    e = temp->data;
    Q.front->next = temp->next;
    delete temp;
    return true;
}
