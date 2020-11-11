#include <iostream>
using namespace std;

typedef int ElemType;  // 把char强制转换成int。这样我可以使用上面写的测试用例，不然我还得重新写

typedef struct BSTNode {
    ElemType key;
    struct BSTNode *lchild, *rchild;
    int count = 0;
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

int setCount(BSTree &T) {
    if (T == NULL)
        return 0;
    int left = setCount(T->lchild);
    int right = setCount(T->rchild);
    return left + right + 1;
}

void setCountEntry(BSTree &T) {
    if (T == NULL)
        return;
    T->count = setCount(T) - 1;
    setCountEntry(T->lchild);
    setCountEntry(T->rchild);
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

void preOrderCount(BSTree T) {
    if (T == NULL)
        return;
    cout << T->count << "  ";
    preOrderCount(T->lchild);
    preOrderCount(T->rchild);
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

BSTNode *searchTheKthSmallestElement(BSTree T, int k) {
    //在以T为根的子树上寻找第k小的元素，返回其所在结点的指针。k从1开始计算
    //在树结点中增加一个count数据成员，存储以该结点为根的子树的结点个数
    if (k < 1 || k > T->count)
        return NULL;
    if (T->lchild == NULL) {
        if (k == 1)
            return T;
        return searchTheKthSmallestElement(T, k - 1);
    }
    // 下面的都是T->lchild != NULL的情况
    if (T->lchild->count > k - 1)
        return searchTheKthSmallestElement(T->lchild, k);
    else if (T->lchild->count < k - 1)
        return searchTheKthSmallestElement(T->rchild, k - (T->lchild->count + 1));
    else  // if (T->lchild->count == k - 1)
        return T;
}

void test(ElemType *preOrder, ElemType *inOrder, int length, ElemType value, int k) {
    BSTree T = construct(preOrder, inOrder, length);
    setCountEntry(T);
    preOrderCount(T);
    cout << endl;

    PreOrder(T);
    cout << endl;

    InOrder(T);
    cout << endl;

    PostOrder(T);
    cout << endl;

    cout << endl;
    // 在此处写要测试的函数...
    cout << searchTheKthSmallestElement(T, k)->key << endl;
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

    ElemType value = 40;
    test(preOrder1, inOrder1, length1, value, 2);

    // test(preOrder2, inOrder2, length2);

    return 0;
}

// 运行结果：
// 5  2  1  0  1  0
// 54 20 40 28 66 79
// 20 28 40 54 66 79
// 28 40 20 79 66 54

// 40

