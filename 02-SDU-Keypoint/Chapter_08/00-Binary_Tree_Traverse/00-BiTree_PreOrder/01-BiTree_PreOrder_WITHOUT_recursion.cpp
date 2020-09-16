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

// 由于调用自己写的栈太麻烦了，而且我之前写的是顺序栈，还要考虑栈的大小和树的结点数量，
// 除非用链栈可以不用考虑，直接压栈就行，但是我懒得写了，所以就直接用C库的栈
void PreOrder(BiTree T) {
    stack<BiTNode *> s;
    BiTNode *p = T;
    while (p != NULL || !s.empty()) {
        if (p != NULL) {
            visit(p);
            s.push(p);
            p = p->lchild;
        } else {
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
}
