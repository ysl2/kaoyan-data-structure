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
        s.push(p);
        if (p->lchild != NULL)
            q.push(p->lchild);
        if (p->rchild != NULL)
            q.push(p->rchild);
    }
    while (!s.empty()) {
        p = s.top();
        s.pop();
        visit(p);
    }
}

