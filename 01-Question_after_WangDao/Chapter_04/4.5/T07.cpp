#include <iostream>
using namespace std;

typedef int ElemType;  // 把char强制转换成int。这样我可以使用上面写的测试用例，不然我还得重新写

typedef struct BSTNode {
    ElemType key;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

BSTNode *construct(ElemType *preOrder, ElemType *midOrder, int len) {
    if (preOrder == NULL || midOrder == NULL || len <= 0)
        return NULL;
    //先根遍历（前序遍历）的第一个值就是根节点的键值
    ElemType rootKey = preOrder[0];
    BSTree T = new BSTNode;
    T->key = rootKey;
    T->lchild = T->rchild = NULL;
    if (len == 1 && *preOrder == *midOrder)  //只有一个节点
        return T;
    //在中根遍历（中序遍历）中找到根节点的值
    ElemType *rootMidOrder = midOrder;
    int leftLen = 0;  //左子树节点数
    while (*rootMidOrder != rootKey && rootMidOrder <= (midOrder + len - 1)) {
        ++rootMidOrder;
        ++leftLen;
    }
    if (*rootMidOrder != rootKey)  //在中根序列未找到根节点,输入错误
        return NULL;
    if (leftLen > 0) //构建左子树
        T->lchild = construct(preOrder + 1, midOrder, leftLen);
    if (len - leftLen - 1 > 0) //构建右子树
        T->rchild = construct(preOrder + leftLen + 1, rootMidOrder + 1, len - leftLen - 1);
    return T;
}

void visit(BSTree T) {
    std::cout << T->key << " ";
}

void PostOrder(BSTree T) {
    if (T == NULL)
        return;
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    visit(T);
}

void InOrder(BSTree T) {
    if (T == NULL)
        return;
    InOrder(T->lchild);
    visit(T);
    InOrder(T->rchild);
}

void PreOrder(BSTree T) {
    if (T == NULL)
        return;
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}

bool getNodeByValue(BSTree T, ElemType value, BSTNode *&result) {
    if (T == NULL)
        return false;
    if (T->key == value) {
        result = T;
        return true;
    }
    if (getNodeByValue(T->lchild, value, result) == true)
        return true;
    return getNodeByValue(T->rchild, value, result);
}

// 2020-09-24
int getLayer(BSTree T, BSTNode *s) {
    if (T == NULL)
        return 0;
    int layer = 1;
    while (T != NULL && s->key != T->key) {
        if (T->key < s->key)
            T = T->rchild;
        else
            T = T->lchild;
        layer++;
    }
    return (T == NULL) ? -1 : layer;
}

void test(ElemType *preOrder, ElemType *inOrder, int length, ElemType value) {
    BSTree T = construct(preOrder, inOrder, length);

    PreOrder(T);
    cout << endl;

    InOrder(T);
    cout << endl;

    PostOrder(T);
    cout << endl;

    cout << endl;
    // 在此处写要测试的函数...
    BSTNode *p;
    if (getNodeByValue(T, value, p) == false) {
        p = new BSTNode;
        p->key = value;
        p->lchild = p->rchild = NULL;
    }
    cout << getLayer(T, p) << endl;
    cout <<"--------------------------" << endl;
}

int main() {
    // BST树
    ElemType preOrder1[] = {54, 20, 40, 28, 66, 79};
    ElemType inOrder1[] = {20, 28, 40, 54, 66, 79};
    int length1 = sizeof(preOrder1) / sizeof(preOrder1[0]);

    // 非BST树
    // ElemType preOrder2[] = {'B', 'E', 'F', 'C', 'G', 'D', 'H'};
    // ElemType inOrder2[] = {'F', 'E', 'B', 'G', 'C', 'H', 'D'};
    // int length2 = sizeof(preOrder2) / sizeof(preOrder2[0]);

    int value1 = 40;
    test(preOrder1, inOrder1, length1, value1);

    int value2 = 58;
    test(preOrder1, inOrder1, length1, value2);

    // test(preOrder2, inOrder2, length2);

    return 0;
}

// 运行结果：
// 54 20 40 28 66 79
// 20 28 40 54 66 79
// 28 40 20 79 66 54

// 3
// --------------------------
// 54 20 40 28 66 79
// 20 28 40 54 66 79
// 28 40 20 79 66 54

// -1
// --------------------------
