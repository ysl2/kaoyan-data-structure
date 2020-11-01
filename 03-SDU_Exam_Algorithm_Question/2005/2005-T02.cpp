#include <cstdlib>
#include <iostream>
using namespace std;

typedef char ElemType;  // 把char强制转换成int。这样我可以使用上面写的测试用例，不然我还得重新写
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTNode *createBiTree(ElemType *inOrder, int inOrderSize, ElemType *postOrder, int postOrderSize) {
    if (postOrderSize <= 0)
        return NULL;
    BiTNode *T = new BiTNode;
    T->data = postOrder[postOrderSize - 1];
    int index = 0;
    while (index < inOrderSize && inOrder[index] != postOrder[postOrderSize - 1])
        ++index;
    T->lchild = createBiTree(inOrder, index, postOrder, index);
    T->rchild = createBiTree(inOrder + index + 1, inOrderSize - (index + 1), postOrder + index, postOrderSize - (index + 1));
    return T;
}

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

void InOrder(BiTree T) {
    if (T == NULL)
        return;
    InOrder(T->lchild);
    visit(T);
    InOrder(T->rchild);
}

void PreOrder(BiTree T) {
    if (T == NULL)
        return;
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}

bool getNodeByValue(BiTree T, ElemType value, BiTNode *&result) {
    if (T == NULL)
        return false;
    if (T->data == value) {
        result = T;
        return true;
    }
    if (getNodeByValue(T->lchild, value, result) == true)
        return true;
    else
        return getNodeByValue(T->rchild, value, result);
}

void test(ElemType *inOrder, ElemType *postOrder, int length) {
    BiTree T = createBiTree(inOrder, length, postOrder, length);

    PreOrder(T);
    cout << endl;

    InOrder(T);
    cout << endl;

    PostOrder(T);
    cout << endl;
}

int main() {
    // 非满二叉树、非完全二叉树
    ElemType preOrder1[] = {'B', 'E', 'F', 'C', 'G', 'D', 'H'};
    ElemType inOrder1[] = {'F', 'E', 'B', 'G', 'C', 'H', 'D'};
    ElemType postOrder1[] = {'F', 'E', 'G', 'H', 'D', 'C', 'B'};
    int length1 = sizeof(preOrder1) / sizeof(preOrder1[0]);

    test(inOrder1, postOrder1, length1);

    return 0;
}

// 运行结果：
// B E F C G D H
// F E B G C H D
// F E G H D C B
