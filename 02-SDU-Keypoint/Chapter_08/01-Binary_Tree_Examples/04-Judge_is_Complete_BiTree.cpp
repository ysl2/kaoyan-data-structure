#include <cstdlib>
#include <iostream>
#include <queue>
using std::cout;
using std::endl;
using std::queue;

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

bool judgeIsCompleteTree(BiTree T) {
    if (T == NULL)
        return true;
    if (T->lchild == NULL && T->rchild == NULL)
        return true;
    return T->rchild != NULL;
}

bool LevelOrder(BiTree T) {
    queue<BiTNode *> q;
    if (T == NULL)
        return true;
    q.push(T);
    BiTNode *p = NULL;
    while (!q.empty()) {
        p = q.front();
        q.pop();
        if (!judgeIsCompleteTree(p))
            return false;
        if (p->lchild != NULL)
            q.push(p->lchild);
        if (p->rchild != NULL)
            q.push(p->rchild);
    }
    return true;
}

void test(ElemType *preOrder, ElemType *inOrder, int length) {
    BiTree T = construct(preOrder, inOrder, length);

    PreOrder(T);
    cout << endl;

    InOrder(T);
    cout << endl;

    PostOrder(T);
    cout << endl;

    if (LevelOrder(T))
        cout << "true" << endl;
    else
        cout << "false" << endl;

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
// false


// 66 69 70 72 67 71 68
// 70 69 72 66 71 67 68
// 70 72 69 71 68 67 66
// true


