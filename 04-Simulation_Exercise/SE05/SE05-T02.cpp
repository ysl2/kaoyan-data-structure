#include <iostream>
using namespace std;

typedef char ElemType;  // 把char强制转换成int。这样我可以使用上面写的测试用例，不然我还得重新写
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
    int leftLen = 0;  //左子树节点数
    while (*rootMidOrder != rootKey && rootMidOrder <= (midOrder + len - 1)) {
        ++rootMidOrder;
        ++leftLen;
    }
    if (*rootMidOrder != rootKey)  //在中根序列未找到根节点,输入错误
        return NULL;
    if (leftLen > 0)  //构建左子树
        T->lchild = construct(preOrder + 1, midOrder, leftLen);
    if (len - leftLen - 1 > 0)  //构建右子树
        T->rchild = construct(preOrder + leftLen + 1, rootMidOrder + 1, len - leftLen - 1);
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

// 对于结点t，以它为根的树的最长路径path一定是下列三个数中的最大值：
// ① t的左子树的最长路径lpath
// ② t的右子树的最长路径rpath
// ③ t的左子树高度 + t的右子树高度
int getDepth(BiTree T) {
    if (T == NULL)
        return 0;
    int left = getDepth(T->lchild);
    int right = getDepth(T->rchild);
    return left > right ? left + 1 : right + 1;
}

int getMaxInThreeNumbers(int a, int b, int c) {
    return max(a, max(b, c));
}

int findMaxPath(BiTree T) {
    if (T == NULL)
        return 0;
    int lpath = findMaxPath(T->lchild);
    int rpath = findMaxPath(T->rchild);
    int hpath = getDepth(T->lchild) + getDepth(T->rchild);
    return getMaxInThreeNumbers(lpath, rpath, hpath);
}

void test(ElemType *preOrder, ElemType *inOrder, int length) {
    BiTree T = construct(preOrder, inOrder, length);

    PreOrder(T);
    cout << endl;

    InOrder(T);
    cout << endl;

    PostOrder(T);
    cout << endl;

    // 在此处写要测试的函数...
    cout << endl;
    cout << findMaxPath(T) << endl;
}

int main() {
    // 非满二叉树、非完全二叉树
    ElemType preOrder1[] = {'B', 'E', 'F', 'C', 'G', 'D', 'H'};
    ElemType inOrder1[] = {'F', 'E', 'B', 'G', 'C', 'H', 'D'};
    int length1 = sizeof(preOrder1) / sizeof(preOrder1[0]);

    // 满二叉树、完全二叉树
    // ElemType preOrder2[] = {'B', 'E', 'F', 'H', 'C', 'G', 'D'};
    // ElemType inOrder2[] = {'F', 'E', 'H', 'B', 'G', 'C', 'D'};
    // int length2 = sizeof(preOrder2) / sizeof(preOrder2[0]);

    test(preOrder1, inOrder1, length1);

    // test(preOrder2, inOrder2, length2);

    return 0;
}

// 运行结果：
// B E F C G D H
// F E B G C H D
// F E G H D C B

// 5
