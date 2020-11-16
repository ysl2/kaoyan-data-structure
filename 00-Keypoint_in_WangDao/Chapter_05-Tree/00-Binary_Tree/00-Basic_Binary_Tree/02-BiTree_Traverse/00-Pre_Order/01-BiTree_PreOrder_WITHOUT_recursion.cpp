#include <iostream>
#include <stack>
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
    if (leftLen > 0) //构建左子树
        T->lchild = construct(preOrder + 1, midOrder, leftLen);
    if (len - leftLen - 1 > 0) //构建右子树
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
    if (getNodeByValue(T->lchild, value, result))
        return true;
    return getNodeByValue(T->rchild, value, result);
}

// 由于调用自己写的栈太麻烦了，而且我之前写的是顺序栈，还要考虑栈的大小和树的结点数量，
// 除非用链栈可以不用考虑，直接压栈就行，但是我懒得写了，所以就直接用C库的栈
void PreOrderWithoutRecursion1(BiTree T) {
    stack<BiTNode *> s;
    BiTNode *p = T;
    while (p != NULL || !s.empty()) {
        if (p != NULL) {
            visit(p);
            s.push(p);
            p = p->lchild;
        } else {
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
}

// 这个是山大2013年真题第二题的写法。注意左右子树的遍历顺序：先右子树，再左子树
void PreOrderWithoutRecursion2(BiTree T) {
    stack<BiTNode *> s;
    s.push(T);
    while (!s.empty()) {
        BiTNode *p = s.top();
        s.pop();
        visit(p);  // 这个visit的位置在哪都可以，只要在弹栈之后就行
        if (p->rchild != NULL)
            s.push(p->rchild);
        if (p->lchild != NULL)
            s.push(p->lchild);
    }
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
    PreOrderWithoutRecursion1(T);
    cout << endl;
    PreOrderWithoutRecursion2(T);
    cout << endl;
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

// B E F C G D H
// B E F C G D H

