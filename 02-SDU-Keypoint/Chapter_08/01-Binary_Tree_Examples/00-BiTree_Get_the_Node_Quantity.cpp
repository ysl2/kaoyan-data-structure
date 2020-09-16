#include <iostream>
typedef int ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int count = 0;

void visit(BiTree T) {
    // 如果计算叶子结点数、单分支结点数、双分支结点数，就在这相应的加上if判断条件即可
    // 例如：
    // if (T.lchild == NULL && T.rchild == NULL) count++;
    // if ((T.lchild == NULL && T.rchild != NULL) || (T.lchild != NULL && T.rchild == NULL)) count++;
    // if (T.lchild != NULL && T.rchild != NULL) count++;
    count++;
    // std::cout << T->data << " ";
}

// 计算二叉树的结点个数
void PreOrder(BiTree T) {
    if (T == NULL)
        return;
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}

int test(BiTree T) {
    PreOrder(T);
    return count;
}
