#include <iostream>
using namespace std;

typedef char ElemType;  // 把char强制转换成int。这样我可以使用上面写的测试用例，不然我还得重新写

typedef struct CSTNode {
    ElemType data;
    struct CSTNode *lchild, *rbro;
} CSTNode, *CSTree;

CSTNode *construct(ElemType *preOrder, ElemType *midOrder, int len) {
    if (preOrder == NULL || midOrder == NULL || len <= 0)
        return NULL;
    //先根遍历（前序遍历）的第一个值就是根节点的键值
    ElemType rootKey = preOrder[0];
    CSTree T = new CSTNode;
    T->data = rootKey;
    T->lchild = T->rbro = NULL;
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
        T->rbro = construct(preOrder + leftLen + 1, rootMidOrder + 1, len - leftLen - 1);
    return T;
}

void visit(CSTree T) {
    std::cout << T->data << " ";
}

void PostOrder(CSTree T) {
    if (T == NULL)
        return;
    PostOrder(T->lchild);
    PostOrder(T->rbro);
    visit(T);
}

void InOrder(CSTree T) {
    if (T == NULL)
        return;
    InOrder(T->lchild);
    visit(T);
    InOrder(T->rbro);
}

void PreOrder(CSTree T) {
    if (T == NULL)
        return;
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rbro);
}

bool getNodeByValue(CSTree T, ElemType value, CSTNode *&result) {
    if (T == NULL)
        return false;
    if (T->data == value) {
        result = T;
        return true;
    }
    if (getNodeByValue(T->lchild, value, result) == true)
        return true;
    return getNodeByValue(T->rbro, value, result);
}

int getDepth(CSTree T) {
    if (T == NULL)
        return 0;
    int left = getDepth(T->lchild);
	int right = getDepth(T->rbro);
    // 深度取(子女高度 + 1)和(兄弟子树)二者深度更大的
    return left + 1 > right? left + 1 : right;
}

void test(ElemType *preOrder, ElemType *inOrder, int length) {
    CSTree T = construct(preOrder, inOrder, length);

    PreOrder(T);
    cout << endl;

    InOrder(T);
    cout << endl;

    PostOrder(T);
    cout << endl;

    cout << endl;
    // 在此处写要测试的函数...
    cout << getDepth(T) << endl;
}

int main() {
    // 非满二叉树、非完全二叉树
    ElemType preOrder1[] = {'A', 'B', 'E', 'F', 'C', 'D', 'G'};
    ElemType inOrder1[] = {'E', 'F', 'B', 'C', 'G', 'D', 'A'};
    int length1 = sizeof(preOrder1) / sizeof(preOrder1[0]);

    // 满二叉树、完全二叉树
    // ElemType preOrder2[] = {'+', '*', 'a', 'b', '-', '-', 'c', 'd'};
    // ElemType inOrder2[] = {'a', '*', 'b', '+', '-', 'c', '-', 'd'};
    // int length2 = sizeof(preOrder2) / sizeof(ElemType);

    test(preOrder1, inOrder1, length1);

    // test(preOrder2, inOrder2, length2);

    return 0;
}

// 运行结果：
// A B E F C D G
// E F B C G D A
// F E G D C B A

// 3
