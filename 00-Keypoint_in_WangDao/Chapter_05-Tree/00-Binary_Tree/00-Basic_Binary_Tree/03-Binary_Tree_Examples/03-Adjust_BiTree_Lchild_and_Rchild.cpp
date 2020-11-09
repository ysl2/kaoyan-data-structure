#include <cmath>
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

typedef int ElemType;  // 把char强制转换成int。这样我可以直接使用上面写的测试用例，不然我还得重新写
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 根据先序遍历和中序遍历序列创建一棵二叉树
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

    if (leftLen > 0) {  //构建左子树
        T->lchild = construct(preOrder + 1, midOrder, leftLen);
    }
    if (len - leftLen - 1 > 0) {  //构建右子树
        T->rchild = construct(preOrder + leftLen + 1, rootMidOrder + 1, len - leftLen - 1);
    }
    return T;
}

void visit(BiTree T) {
    std::cout << T->data << " ";
}

void PreOrder(BiTree T) {
    if (T == NULL)
        return;
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
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

void operateNode(BiTree &T) {
    if (T == NULL)
        return;
    if (T->lchild == NULL || T->rchild == NULL)
        return;
    if (T->lchild->data > T->rchild->data) {
        BiTNode *temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
    }
}

void adjustTree(BiTree &T) {
    if (T == NULL)
        return;
    operateNode(T);  // 这个operate放在哪里都行，最终的结果不变
    adjustTree(T->lchild);
    adjustTree(T->rchild);
}

void test(ElemType *preOrder, ElemType *inOrder, int length) {
    BiTree T = construct(preOrder, inOrder, length);

    PreOrder(T);
    cout << endl;

    InOrder(T);
    cout << endl;

    PostOrder(T);
    cout << endl;

    adjustTree(T);  // 交换
    cout << endl;

    PreOrder(T);
    cout << endl;

    InOrder(T);
    cout << endl;

    PostOrder(T);
    cout << endl;
    cout << endl;
    cout << endl;
}

int main() {
    ElemType preOrder1[] = {'B', 'E', 'F', 'C', 'G', 'D', 'H'};
    ElemType inOrder1[] = {'F', 'E', 'B', 'G', 'C', 'H', 'D'};
    int length1 = sizeof(preOrder1) / sizeof(ElemType);
    ElemType preOrder2[] = {'B', 'E', 'F', 'H', 'C', 'G', 'D'};
    ElemType inOrder2[] = {'F', 'E', 'H', 'B', 'G', 'C', 'D'};
    int length2 = sizeof(preOrder2) / sizeof(ElemType);

    test(preOrder1, inOrder1, length1);

    test(preOrder2, inOrder2, length2);
    return 0;
}

// 运行结果：
// 66 69 70 67 71 68 72
// 70 69 66 71 67 72 68
// 70 69 71 72 68 67 66

// 66 67 68 72 71 69 70
// 72 68 67 71 66 70 69
// 72 68 71 67 70 69 66


// 66 69 70 72 67 71 68
// 70 69 72 66 71 67 68
// 70 72 69 71 68 67 66

// 66 67 68 71 69 70 72
// 68 67 71 66 70 69 72
// 68 71 67 70 72 69 66
