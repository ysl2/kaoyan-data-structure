#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef int ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void visit(BiTNode *p) {
    cout << p->data << " ";
}

// 自上至下，自左至右的层次遍历算法
void reverseLevelOrder(BiTree T) {
    if (T == NULL)
        return ;
    stack<BiTNode *> s;
    queue <BiTNode *> q;
    q.push(T);
    BiTNode *p = T;
    while (!q.empty()) {
        p = q.front();
        q.pop();
        s.push(p);  // 与正序层次遍历的区别在这里。正序在这一步会直接输出，而反序的会压栈
        if (p->lchild != NULL)
            q.push(p->lchild);
        if (p->rchild != NULL)
            q.push(p->rchild);
    }
    while (!s.empty()) {
        p = s.top();
        s.pop();
        visit(p);  // 反序真正输出是在这一步
    }
}

