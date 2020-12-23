#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

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

// 本题是判断一个链式存储的树是否是最小堆
// 需要同时满足：
// ①是完全二叉树
// ②是最小树（每个结点的值都小于或等于其子结点的值）

// ①判断是否是完全二叉树
bool isCompleteTree(BiTree T) {
    if (T == NULL)
        return true;
    queue<BiTNode *> q;
    q.push(T);
    BiTNode *p = NULL;
    while (!q.empty()) {
        p = q.front();
        q.pop();
        if (p == NULL) {
            while (!q.empty()) {
                p = q.front();
                q.pop();
                if (p != NULL)
                    return false;
            }
        } else {
            q.push(p->lchild);
            q.push(p->rchild);
        }
    }
    return true;
}

// ②判断是否是最小树
bool isMinTree (BiTree T) {
    stack<BiTNode *> s;
    BiTNode *p = T;
    while (p != NULL || !s.empty()) {
        if (p != NULL) {
            s.push(p);
            p = p->lchild;
        } else {
            p = s.top();
            s.pop();
            if (p->lchild != NULL && p->rchild != NULL) {
                if (p->lchild->data < p->data || p->rchild->data < p->data)
                    return false;
            } else if (p->lchild != NULL) {
                if (p->lchild->data < p->data)
                    return false;
            } else if (p->rchild != NULL) {
                if (p->rchild->data < p->data)
                    return false;
            }
            p = p->rchild;
        }
    }
    return true;
}

bool isMinHeap(BiTree T) {
    return isCompleteTree(T) && isMinTree(T);
}

void test(ElemType *preOrder, ElemType *inOrder, int length) {
    BiTree T = construct(preOrder, inOrder, length);

    PreOrder(T);
    cout << endl;

    InOrder(T);
    cout << endl;

    PostOrder(T);
    cout << endl;

    if (isMinHeap(T))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << endl;
    cout << endl;
}

int main() {
    ElemType preOrder1[] = {'B', 'E', 'F', 'C', 'G', 'D', 'H'};
    ElemType inOrder1[] = {'F', 'E', 'B', 'G', 'C', 'H', 'D'};
    int length1 = sizeof(preOrder1) / sizeof(preOrder1[0]);
    ElemType preOrder2[] = {'B', 'E', 'F', 'H', 'C', 'G', 'D'};
    ElemType inOrder2[] = {'F', 'E', 'H', 'B', 'G', 'C', 'D'};
    int length2 = sizeof(preOrder2) / sizeof(preOrder2[0]);

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

