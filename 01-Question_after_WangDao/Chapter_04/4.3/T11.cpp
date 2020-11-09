#include <cstdlib>
#include <iostream>
#include <queue>
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
    if (getNodeByValue(T->lchild, value, result) == true)
        return true;
    else
        return getNodeByValue(T->rchild, value, result);
}

// https://blog.csdn.net/u013595419/article/details/52297773
// 本题可以分成两个部分来完成。第一步：查找值为x的节点；第二步：删除以值为x的节点为根节点的所有子树；
// 因为删除的是x的所有子树，因此遍历方式应该选择自上而下的遍历方式，即先序遍历或层次遍历方式，这里选择层次遍历的方式实现。
// 删除值为x的节点的所有子树，可以考虑使用递归的方式；

// 即此时可以认为删除的是以值为x的节点作为根节点的树；
// 首先删除该树的叶子节点，这样该树的倒数第二层节点又会变成新的叶子节点；
// 接着依次类推，直到值为x的节点变为叶子节点，最后删除自身便可

// 2020-08-31
void deleteXTree(BiTree T) {
    if (T == NULL)
        return;
    deleteXTree(T->lchild);
    deleteXTree(T->rchild);
    delete T;
}

void search(BiTree T, ElemType x) {
    if (T == NULL)
        return;
    if (T->data == x) {
        deleteXTree(T);
        return;
    }
    queue<BiTNode *> q;
    q.push(T);
    BiTNode *p = NULL;
    while (!q.empty()) {
        p = q.front();
        q.pop();
        if (p->lchild != NULL) {
            if (p->lchild->data == x) {
                deleteXTree(p->lchild);
                p->lchild = NULL;
            } else
                q.push(p->lchild);
        }
        if (p->rchild != NULL) {
            if (p->rchild->data == x) {
                deleteXTree(p->rchild);
                p->rchild = NULL;
            } else
                q.push(p->rchild);
        }
    }
}

void test(ElemType *preOrder, ElemType *inOrder, int length, ElemType x) {
    BiTree T = construct(preOrder, inOrder, length);

    PreOrder(T);
    cout << endl;

    InOrder(T);
    cout << endl;

    PostOrder(T);
    cout << endl;

    cout << endl;
    cout << endl;

    // 在此处写要测试的函数...
    search(T, x);

    PreOrder(T);
    cout << endl;

    InOrder(T);
    cout << endl;

    PostOrder(T);
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
    // int length2 = sizeof(preOrder2) / sizeof(ElemType);

    ElemType x = 'C';
    test(preOrder1, inOrder1, length1, x);

    // test(preOrder2, inOrder2, length2);

    return 0;
}

// 运行结果：
// B E F C G D H
// F E B G C H D
// F E G H D C B


// B E F
// F E B
// F E B
