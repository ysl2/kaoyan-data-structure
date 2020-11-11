
#include <iostream>
#include <stdlib.h>
using namespace std;
// abs函数在<stdlib.h>库
// max没有，要自己写

typedef int ElemType;  // 把char强制转换成int。这样我可以使用上面写的测试用例，不然我还得重新写
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTNode *construct(ElemType *preOrder, ElemType *midOrder, int len) {
    if (preOrder == NULL || midOrder == NULL || len <= 0)
        return NULL;
    //先根遍历（前序遍历）的第一个值就是根节点的键值
    ElemType rootKey = preOrder[0];
    BiTree T = new BiTNode;
    T->data = rootKey;
    T->lchild = T->rchild = NULL;
    if (len == 1 && *preOrder == *midOrder)  //只有一个节点
        return T;
    //在中根遍历（中序遍历）中找到根节点的值
    ElemType *rootMidOrder = midOrder;
    int leftMaxDepthLen = 0;  //左子树节点数
    while (*rootMidOrder != rootKey && rootMidOrder <= (midOrder + len - 1)) {
        ++rootMidOrder;
        ++leftMaxDepthLen;
    }
    if (*rootMidOrder != rootKey)  //在中根序列未找到根节点,输入错误
        return NULL;
    if (leftMaxDepthLen > 0) //构建左子树
        T->lchild = construct(preOrder + 1, midOrder, leftMaxDepthLen);
    if (len - leftMaxDepthLen - 1 > 0) //构建右子树
        T->rchild = construct(preOrder + leftMaxDepthLen + 1, rootMidOrder + 1, len - leftMaxDepthLen - 1);
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
    return getNodeByValue(T->rchild, value, result);
}

// https://leetcode-cn.com/problems/balanced-binary-tree/solution/balanced-binary-tree-di-gui-fang-fa-by-jin40789108/
int isAVL(BiTree T) {
    if (T == NULL)
        return 0;
    int leftMaxDepth = isAVL(T->lchild);
    if (leftMaxDepth == -1)
        return -1;
    int rightMaxDepth = isAVL(T->rchild);
    if (rightMaxDepth == -1)
        return -1;
    return abs(leftMaxDepth - rightMaxDepth) < 2 ? max(leftMaxDepth, rightMaxDepth) + 1 : -1;
}

bool isAVLEntry(BiTree T) {
    return isAVL(T) != -1;
}

void test(ElemType *preOrder, ElemType *inOrder, int length) {
    BiTree T = construct(preOrder, inOrder, length);

    PreOrder(T);
    cout << endl;

    InOrder(T);
    cout << endl;

    PostOrder(T);
    cout << endl;

    cout << endl;
    // 在此处写要测试的函数...
    if (isAVLEntry(T))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    cout <<"--------------------------" << endl;
}

int main() {
    // 是AVL
    ElemType preOrder1[] = {9, 7, 3, 8, 10, 15};
    ElemType inOrder1[] = {3, 7, 8, 9, 10, 15};
    int length1 = sizeof(preOrder1) / sizeof(preOrder1[0]);

    // 是BST，但不是AVL
    ElemType preOrder2[] = {54, 20, 40, 28, 66, 79};
    ElemType inOrder2[] = {20, 28, 40, 54, 66, 79};
    int length2 = sizeof(preOrder2) / sizeof(preOrder2[0]);

    test(preOrder1, inOrder1, length1);
    test(preOrder2, inOrder2, length2);

    return 0;
}

// 运行结果：
// 9 7 3 8 10 15
// 3 7 8 9 10 15
// 3 8 7 15 10 9

// true
// --------------------------
// 54 20 40 28 66 79
// 20 28 40 54 66 79
// 28 40 20 79 66 54

// false
// --------------------------

