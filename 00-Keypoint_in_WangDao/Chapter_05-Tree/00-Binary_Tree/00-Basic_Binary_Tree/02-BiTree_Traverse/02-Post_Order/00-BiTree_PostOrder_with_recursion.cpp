#include <iostream>
typedef int ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void visit(BiTree T) {
    std::cout << T->data << " ";
}

void PostOrder(BiTree T) {
    if (T == NULL)
        return;
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    visit(T);
}

