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

void PostOrder(BiTree T) {
    stack<BiTNode *> s;
    BiTNode *p = T;
    BiTNode *r = NULL;
    while (p != NULL || !s.empty()) {
        if (p != NULL) {
            s.push(p);
            p = p->lchild;
        } else {
            p = s.top();
            if (p->rchild != NULL && p->rchild != r) {
                p = p->rchild;
            } else {
                s.pop();
                visit(p);
                r = p;
                p = NULL;
            }
        }
    }
}
