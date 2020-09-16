#include <iostream>
typedef int ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 计算二叉树的深度
int depth = 0;
int GetDepth(BiTree T) {
    if (T == NULL)
        return 0;
    int left = GetDepth(T->lchild);
    int right = GetDepth(T->rchild);
    return (left > right) ? left + 1 : right + 1;
}
