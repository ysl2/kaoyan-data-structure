#include <cstdlib>
#include <iostream>
using std::cout;

typedef char ElemType;
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

// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/c-yu-yan-12-ms-128-mb-di-gui-by-chen-xiang-yin/
BiTNode *createTree(ElemType *preOrder, int preOrderSize, ElemType *inOrder, int inOrderSize) {
    if (preOrderSize <= 0)
        return NULL;
    BiTNode *T = (BiTNode *)malloc(sizeof(BiTNode));
    T->data = preOrder[0];
    int index = 0;
    while (index < inOrderSize && inOrder[index] != preOrder[0])
        ++index;
    T->lchild = createTree(preOrder + 1, index, inOrder, index);
    T->rchild = createTree(preOrder + 1 + index, preOrderSize - (index + 1), inOrder + index + 1, inOrderSize - (index + 1));
    return T;
}

void test(ElemType *preOrder, ElemType *inOrder, int length) {
    BiTree T = createTree(preOrder, length, inOrder, length);
    PostOrder(T);
}

int main() {
    ElemType preOrder1[] = {'B', 'E', 'F', 'C', 'G', 'D', 'H'};
    ElemType inOrder1[] = {'F', 'E', 'B', 'G', 'C', 'H', 'D'};
    int length1 = sizeof(preOrder1) / sizeof(ElemType);
    test(preOrder1, inOrder1, length1);
}

// 运行结果：
// F E G H D C B
