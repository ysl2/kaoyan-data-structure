// 2020-09-11
#include <iostream>
#include <queue>
using namespace std;

typedef int ElemType;
typedef struct BiTNode {
    ElemType data;
    BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void levelOrder(BiTree T) {
    queue<BiTNode *> q;
    q.push(T);
    while (!q.empty()) {
        BiTNode *p = q.front();
        q.pop();
        visit(p);
        if (p->lchild != NULL) q.push(p->lchild);
        if (p->rchild != NULL) q.push(p->rchild);
    }
}

void visit(BiTNode *p) {
    cout << p->data;
}
