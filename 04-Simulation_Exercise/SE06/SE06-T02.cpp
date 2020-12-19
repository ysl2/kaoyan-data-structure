#include <cstdlib>
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

void InOrder1(BiTree T, int depth) {
    if (T == NULL)
        return;
    if (T->lchild == NULL && T->rchild == NULL) {
        cout << T->data << " ";
        return;  // 一定不要漏这个return，不然程序直接出错
    }
    if (depth > 1)
        cout << '(' << " ";
    // 中序遍历模板
    InOrder1(T->lchild, depth + 1);
    cout << T->data << " ";
    InOrder1(T->rchild, depth + 1);
    //
    if (depth > 1)
        cout << ')' << " ";
}

void BiTreeToExpression(BiTree T) {
    InOrder1(T, 1);
}

// 王道知识点中，树的例子部分，有直接将表达式输出的例子
// 下面这个算法有问题
float postEval(BiTree T) {
    if (T == NULL)
        return 0;
    if (T->lchild == NULL && T->rchild == NULL)
        return (float)T->data;
    float leftValue = postEval(T->lchild);
    float rightValue = postEval(T->rchild);
    float value;
    switch (T->data) {
        case '+':
            value = (float)leftValue + (float)rightValue;
            break;
        case '-':
            value = (float)leftValue - (float)rightValue;
            break;
        case '*':
            value = (float)leftValue * (float)rightValue;
            break;
        case '/':
            value = (float)leftValue / (float)rightValue;
    }
    return value;
}

void test(ElemType *preOrder, ElemType *inOrder, int length, int index = 0) {
    BiTree T = construct(preOrder, inOrder, length);

    PreOrder(T);
    cout << endl;

    InOrder(T);
    cout << endl;

    PostOrder(T);
    cout << endl;

    cout << endl;
    // 在此处写要测试的函数...
    if (index == 0) {
        BiTreeToExpression(T);
        cout << endl;
        cout << "--------------------------" << endl;
    } else if (index == 1)
        cout << postEval(T) << endl;
}

int main() {
    // 非满二叉树、非完全二叉树
    ElemType preOrder1[] = {'*', '+', 'a', 'b', '*', 'c', '-', 'd'};
    ElemType inOrder1[] = {'a', '+', 'b', '*', 'c', '*', '-', 'd'};
    int length1 = sizeof(preOrder1) / sizeof(preOrder1[0]);

    // 满二叉树、完全二叉树
    ElemType preOrder2[] = {'+', '*', 'a', 'b', '-', '-', 'c', 'd'};
    ElemType inOrder2[] = {'a', '*', 'b', '+', '-', 'c', '-', 'd'};
    int length2 = sizeof(preOrder2) / sizeof(preOrder2[0]);

    ElemType preOrder3[] = {'+', '*', '1', '2', '-', '-', '3', '4'};
    ElemType inOrder3[] = {'1', '*', '2', '+', '-', '3', '-', '4'};
    int length3 = sizeof(preOrder3) / sizeof(preOrder3[0]);

    test(preOrder1, inOrder1, length1);

    test(preOrder2, inOrder2, length2);

    test(preOrder3, inOrder3, length3, 1);

    return 0;
}

// 运行结果：
// * + a b * c - d
// a + b * c * - d
// a b + c d - * *

// ( a + b ) * ( c * ( - d ) )
// --------------------------
// + * a b - - c d
// a * b + - c - d
// a b * c d - - +

// ( a * b ) + ( - ( c - d ) )
// --------------------------
