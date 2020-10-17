// 2020-10-17
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

typedef int ElemType;  // 把char强制转换成int。这样我可以使用上面写的测试用例，不然我还得重新写
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

// 判断最大树
// 其实和判断是否是大根堆有点像，但是大根堆是完全二叉树，而这里的“最大树”没有要求必须是完全二叉树，因此还是要通过传统的遍历来做
bool isMaxBiTree(BiTree T) {
    if (T == NULL)
        return false;
    if (T->lchild != NULL && isMaxBiTree(T->lchild) == false)
         return false;
    if (T->rchild != NULL && isMaxBiTree(T->rchild) == false)
         return false;

    // 找三个数中的最大值。思路是堆排序中的heapify操作
    ElemType maxValue = T->data;
    int maxIndex = 0;
    if (T->lchild != NULL && T->lchild->data >= maxValue) {
        maxIndex = 1;
        maxValue = T->lchild->data;
    }
    if (T->rchild != NULL && T->rchild->data >= maxValue) {
        maxIndex = 2;
        maxValue = T->rchild->data;
    }
    return maxIndex == 0;
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
    if (isMaxBiTree(T) == true)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    cout << endl;
}

int main() {
    ElemType preOrder1[] = {'B', 'E', 'F', 'C', 'G', 'D', 'H'};
    ElemType inOrder1[] = {'F', 'E', 'B', 'G', 'C', 'H', 'D'};
    int length1 = sizeof(preOrder1) / sizeof(ElemType);

    ElemType preOrder2[] = {10, 9, 7, 8, 6, 5, 4};
    ElemType inOrder2[] = {7, 9, 10, 6, 8, 4, 5};
    int length2 = sizeof(preOrder2) / sizeof(ElemType);

    test(preOrder1, inOrder1, length1);

    test(preOrder2, inOrder2, length2);

    return 0;
}

// 运行结果：
// 66 69 70 67 71 68 72
// 70 69 66 71 67 72 68
// 70 69 71 72 68 67 66
// false

// 10 9 7 8 6 5 4
// 7 9 10 6 8 4 5
// 7 9 6 4 5 8 10
// true

