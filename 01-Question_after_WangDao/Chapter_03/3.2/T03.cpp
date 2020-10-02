#include <stack>
using namespace std;
#define maxSize 10

typedef int ElemType;
struct Queue {
    stack<ElemType> s1;
    stack<ElemType> s2;
    int size = maxSize;
};

// 这是题目给的条件。
// 由于stackoverflow没有在C的<stack>和<queue>库中定义，因此需要自己写
bool stackoverflow(std::stack<ElemType> s) {
    if (s.size() == maxSize) {
        return false;
    }
    return true;
}

// 下面是题目要求的三个函数：
bool QueueEmpty(Queue Q) {
    return (Q.s1.empty() && Q.s2.empty());
}

bool EnQueue(Queue &Q, ElemType x) {
    if (stackoverflow(Q.s1) && !Q.s2.empty())
        return false;  // 队列满
    if (stackoverflow(Q.s1)) {
        while (!Q.s1.empty()) {
            int temp = Q.s1.top();
            Q.s1.pop();
            Q.s2.push(temp);
        }
    }
    Q.s1.push(x);
    return true;
}

bool DeQueue(Queue &Q, ElemType &e) {
    if (QueueEmpty(Q))
        return false;
    if (Q.s2.empty()) {
        while (!Q.s1.empty()) {
            int temp = Q.s1.top();
            Q.s1.pop();
            Q.s2.push(temp);
        }
    }
    e = Q.s2.top();
    Q.s2.pop();
    return true;
}

//---------------------------------------------------
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

