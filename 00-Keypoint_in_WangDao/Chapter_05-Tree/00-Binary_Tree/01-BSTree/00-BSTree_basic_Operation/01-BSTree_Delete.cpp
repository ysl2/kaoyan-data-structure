#include <iostream>
using namespace std;

typedef int ElemType;  // 把char强制转换成int。这样我可以使用上面写的测试用例，不然我还得重新写

typedef struct BSTNode {
    ElemType key;
    struct BSTNode *lchild, *rchild;
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
    if (leftLen > 0)  //构建左子树
        T->lchild = construct(preOrder + 1, midOrder, leftLen);
    if (len - leftLen - 1 > 0)  //构建右子树
        T->rchild = construct(preOrder + leftLen + 1, rootMidOrder + 1, len - leftLen - 1);
    return T;
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

/*
    基本思想:考虑包含被删除元素的节点p的三种情况:
    （1）p是树叶:丢弃树叶节点；
    （2）p只有一个非空子树:如果p没有父节点（即p是根节点），则将p丢弃，p的唯一子树的根节点成为新的搜索树的根节点。如果p有父节点pp，则修改pp的指针，使得pp指向p的唯一孩子，然后删除节点p
    （3）p有两个非空子树:只需将该元素替换为它的左子树中的最大元素或右子树中的最小元素。可以按下述方法来查找到左（右）子树中的最大（小）元素:首先移动到子树的根，然后沿着各节点的右（左）孩子指针移动，直到右（左）孩子指针为0为止。
*/

void BSTreeDelete(BSTree &T, ElemType k, ElemType &e) {
    BSTNode *p = T;
    BSTNode *pp = NULL;
    while (p != NULL && p->key != k) {
        pp = p;
        if (k < p->key)
            p = p->lchild;
        else
            p = p->rchild;
    }
    if (p == NULL)
        return;  // 没有关键值为k的元素
    e = p->key;  // 保存欲删除的元素
    // p有两个孩子
    if (p->lchild && p->rchild) {  // 转换成有0或1个孩子的情形
        // 在p的左子树中寻找最大元素
        BSTNode *s = p->lchild;
        BSTNode *ps = p;
        while (s->rchild != NULL) {
            ps = s;
            s = s->rchild;
        }
        p->key = s->key;
        p = s;
        pp = ps;
    }
    // p最多有一个孩子
    BSTNode *c;  // 在c中保存孩子指针
    if (p->lchild)
        c = p->lchild;
    else
        c = p->rchild;
    // 删除p
    if (p == T)
        T = c;
    else {  // p是pp的左孩子还是pp的右孩子？
        if (p == pp->lchild)
            pp->lchild = c;
        else
            pp->rchild = c;
    }
    free(p);
}

void test(ElemType *preOrder, ElemType *inOrder, int length, ElemType k) {
    BSTree T = construct(preOrder, inOrder, length);

    PreOrder(T);
    cout << endl;

    InOrder(T);
    cout << endl;

    PostOrder(T);
    cout << endl;

    cout << endl;
    // 在此处写要测试的函数...
    ElemType result;
    BSTreeDelete(T, k, result);
    cout << result << endl;
    cout << endl;

    PreOrder(T);
    cout << endl;

    InOrder(T);
    cout << endl;

    PostOrder(T);
    cout << endl;
    cout << endl;
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

    ElemType k = 20;
    test(preOrder1, inOrder1, length1, k);

    // test(preOrder2, inOrder2, length2);

    return 0;
}

// 运行结果：
// 54 20 40 28 66 79
// 20 28 40 54 66 79
// 28 40 20 79 66 54

// 20

// 54 40 28 66 79
// 28 40 54 66 79
// 28 40 79 66 54
