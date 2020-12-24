#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
#define maxSize 30

typedef char ElemType;  // 把char强制转换成int。这样我可以使用上面写的测试用例，不然我还得重新写
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct {
    BiTNode *data[maxSize];
    int front = -1, rear = -1;
} Queue;

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

int getDepth1(BiTree T) {
    if (T == NULL)
        return 0;
    // 由于C++提供的队列无法随机访问，因此需要自己定义一个以数组为基础的队列，以保证随机访问的特性
    Queue Q;  // 初始时front和rear都是-1
    Q.data[Q.rear++] = T;
    int count = 0;  // 用来记录每层的最后一个结点
    int level = 0;
    while (!(Q.front == Q.rear)) {
        BiTNode *p = Q.data[Q.front++];
        if (p->lchild != NULL)
            Q.data[Q.rear++] = p->lchild;
        if (p->rchild != NULL)
            Q.data[Q.rear++] = p->rchild;
        if (count == Q.front) {  // 这是当前层的最后一个结点
            level++;
            count = Q.rear;  // 重置count
        }
    }
    return level;
}

// 下面这个是我自己写的，用vector来模拟队列
int getDepth2(BiTree T) {
    if (T == NULL)
        return 0;
    vector<pair<BiTNode *, int>> v;
    v.push_back({T, 1});
    int depth = 0;
    while (!v.empty()) {
        BiTNode *p = v.front().first;
        int layer = v.front().second;
        depth = (depth > layer) ? depth : layer;
        // 下面这两行是删除vector中的第一个元素，相当于队列出栈
        vector<pair<BiTNode *, int>>::iterator it = v.begin();
        v.erase(it);
        if (p->lchild != NULL)
            v.push_back({p->lchild, layer + 1});
        if (p->rchild != NULL)
            v.push_back({p->rchild, layer + 1});
    }
    return depth;
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
    cout << endl;

    cout << getDepth1(T) << endl;
    cout << getDepth2(T) << endl;
}

int main() {
    ElemType preOrder1[] = {'B', 'E', 'F', 'C', 'G', 'D', 'H'};
    ElemType inOrder1[] = {'F', 'E', 'B', 'G', 'C', 'H', 'D'};
    int length1 = sizeof(preOrder1) / sizeof(ElemType);
    // ElemType preOrder2[] = {'B', 'E', 'F', 'H', 'C', 'G', 'D'};
    // ElemType inOrder2[] = {'F', 'E', 'H', 'B', 'G', 'C', 'D'};
    // int length2 = sizeof(preOrder2) / sizeof(ElemType);

    test(preOrder1, inOrder1, length1);

    // test(preOrder2, inOrder2, length2);

    return 0;
}

// 运行结果：
// B E F C G D H
// F E B G C H D
// F E G H D C B

// 4
// 4
