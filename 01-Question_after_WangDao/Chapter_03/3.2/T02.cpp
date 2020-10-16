// 2020-09-12 第二次修订
#include <queue>
#include <stack>

void reverse(std::queue<int> q, std::stack<int> s) {
    while (!q.empty()) {
        int value = q.front();
        q.pop();
        s.push(value);
    }
    while (!s.empty()) {
        int value = s.top();
        s.pop();
        q.push(value);
    }
}

//--------------------------------------
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

