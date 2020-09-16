#include <iostream>
#include <stack>
using std::stack;
using std::cout;

typedef int ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void visit(BiTree T) {
    cout << T->data << " ";
}

void InOrder(BiTree T) {
    stack<BiTNode *> s;
    BiTNode *p = T;
    while (p != NULL || !s.empty()) {
        if (p != NULL) {
            s.push(p);
            p = p->lchild;
        } else {
            p = s.top();
            s.pop();
            visit(p);
            p = p->rchild;
        }
    }
}
