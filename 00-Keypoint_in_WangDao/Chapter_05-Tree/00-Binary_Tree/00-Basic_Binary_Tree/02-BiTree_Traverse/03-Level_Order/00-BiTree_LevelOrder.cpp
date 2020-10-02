#include <iostream>
#include <queue>
using std::cout;
using std::queue;

typedef int ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void visit(BiTree T) {
    cout << T->data << " ";
}

void LevelOrder(BiTree T) {
    queue<BiTNode *> q;
    if (T == NULL)
        return;
    q.push(T);
    BiTNode *p = NULL;
    while (!q.empty()) {
        p = q.front();
        q.pop();
        visit(p);
        if (p->lchild != NULL)
            q.push(p->lchild);
        if (p->rchild != NULL)
            q.push(p->rchild);
    }
}
