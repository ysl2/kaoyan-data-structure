#include <cstdlib>
#include <iostream>
#include <stack>
using std::cout;
using std::endl;
using std::stack;

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

// 以下是模板代码。把这段代码和2018 T02放在一起看，它们思路完全一致
int top = -1;
ElemType pathStack[20];
void printTheWayToAllLeafNodes(BiTree T) {
    if (T == NULL)
        return;
    pathStack[++top] = T->data;
    if (T->lchild == NULL && T->rchild == NULL) {
        for (int i = 0; i <= top; i++)
            cout << pathStack[i] << " ";
        cout << endl;
        // 这里不加return，就可以打印出所有的路径
        // 如果题目要求只打印一条，就在这里加一个return即可
    }
    printTheWayToAllLeafNodes(T->lchild);
    printTheWayToAllLeafNodes(T->rchild);
    top--;
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

    printTheWayToAllLeafNodes(T);

    cout << "------------------------------" << endl;
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
// B E F C G D H
// F E B G C H D
// F E G H D C B

// B E F
// B C G
// B C D H
// ------------------------------
// B E F H C G D
// F E H B G C D
// F H E G D C B

// B E F
// B E H
// B C G
// B C D
// ------------------------------
