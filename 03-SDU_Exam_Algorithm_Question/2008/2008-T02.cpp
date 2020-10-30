#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

typedef int ElemType;  // 把char强制转换成int。这样我可以使用上面写的测试用例，不然我还得重新写
typedef struct BSTNode {
    ElemType data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

BSTNode *construct(ElemType *preOrder, ElemType *midOrder, int len) {
    if (preOrder == NULL || midOrder == NULL || len <= 0)
        return NULL;

    //先根遍历（前序遍历）的第一个值就是根节点的键值
    ElemType rootKey = preOrder[0];
    BSTree T = new BSTNode;
    T->data = rootKey;
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

    if (leftLen > 0) {  //构建左子树
        T->lchild = construct(preOrder + 1, midOrder, leftLen);
    }
    if (len - leftLen - 1 > 0) {  //构建右子树
        T->rchild = construct(preOrder + leftLen + 1, rootMidOrder + 1, len - leftLen - 1);
    }
    return T;
}

void visit(BSTree T) {
    std::cout << T->data << " ";
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
    if (T->data == value) {
        result = T;
        return true;
    }
    if (getNodeByValue(T->lchild, value, result) == true)
        return true;
    else
        return getNodeByValue(T->rchild, value, result);
}

void inOrderSave(BSTree T, vector<ElemType> &v) {
    if (T == NULL)
        return;
    inOrderSave(T->lchild, v);
    v.push_back(T->data);
    inOrderSave(T->rchild, v);
}

bool BSTInsert(BSTree &T, ElemType key) {
    if (T == NULL) {
        T = new BSTNode;
        T->lchild = NULL;
        T->rchild = NULL;
        T->data = key;
        return true;
    }
    if (T->data == key)
        return false;
    if (T->data < key)
        return BSTInsert(T->rchild, key);
    return BSTInsert(T->lchild, key);
}

void mergeTwoBST(BSTree &A, BSTree B) {
    vector<ElemType> v;
    inOrderSave(B, v);
    for (int i = 0; i < v.size(); i++)
        BSTInsert(A, v[i]);
}

void test(ElemType *preOrder1, ElemType *inOrder1, int length1,ElemType *preOrder2, ElemType *inOrder2, int length2) {
    BSTree A = construct(preOrder1, inOrder1, length1);
    BSTree B = construct(preOrder2, inOrder2, length2);

    PreOrder(A);
    cout << endl;

    InOrder(A);
    cout << endl;

    PostOrder(A);
    cout << endl;

    cout << endl;

    // 在此处写要测试的函数...
    mergeTwoBST(A, B);

    PreOrder(A);
    cout << endl;

    InOrder(A);
    cout << endl;

    PostOrder(A);
    cout << endl;
}

int main() {
    ElemType preOrder1[] = {12, 5, 2, 9, 18, 15, 17, 16, 19};
    ElemType inOrder1[] = {2, 5, 9, 12, 15, 16, 17, 18, 19};
    int length1 = sizeof(preOrder1) / sizeof(ElemType);

    ElemType preOrder2[] = {6, 3, 1, 0, 2, 5, 8, 7, 9};
    ElemType inOrder2[] = {0, 1, 2, 3, 5, 6, 7, 8, 9};
    int length2 = sizeof(preOrder2) / sizeof(ElemType);

    test(preOrder1, inOrder1, length1, preOrder2, inOrder2, length2);

    return 0;
}

// 运行结果：
// 12 5 2 9 18 15 17 16 19
// 2 5 9 12 15 16 17 18 19
// 2 9 5 16 17 15 19 18 12

// 12 5 2 0 1 3 9 6 7 8 18 15 17 16 19
// 0 1 2 3 5 6 7 8 9 12 15 16 17 18 19
// 1 0 3 2 8 7 6 9 5 16 17 15 19 18 12
