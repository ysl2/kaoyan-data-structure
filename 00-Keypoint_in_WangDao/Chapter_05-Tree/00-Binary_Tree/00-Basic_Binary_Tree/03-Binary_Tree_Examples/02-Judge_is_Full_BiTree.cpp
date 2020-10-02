#include <cmath>
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

typedef char ElemType;
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

void PostOrder(BiTree T) {
    if (T == NULL)
        return;
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    visit(T);
}

// 计算二叉树的结点个数
int count = 0;
void countNodeNumber(BiTree T) {
    if (T == NULL)
        return;
    count++;
    countNodeNumber(T->lchild);
    countNodeNumber(T->rchild);
}

// 计算二叉树的深度
int countNodeDepth(BiTree T) {
    if (T == NULL)
        return 0;
    int left = countNodeDepth(T->lchild);
    int right = countNodeDepth(T->rchild);
    return (left > right) ? left + 1 : right + 1;
}

// 判断是否是满二叉树
bool isFull(BiTree T) {
    countNodeNumber(T);
    int depth = countNodeDepth(T);
    if (pow(2, depth) - 1 == count)
        return true;
    return false;
}

void test(ElemType *preOrder, ElemType *inOrder, int length) {
    BiTree T = construct(preOrder, inOrder, length);
    PostOrder(T);
    if (isFull(T))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    count = 0;  // 因为count是全局变量，也就是test1和test2都能访问到。如果不在这里清零的话，下一次会继续累加，而导致错误的结果
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
// F E G H D C B false
// F H E G D C B true
