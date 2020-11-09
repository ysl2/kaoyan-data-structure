#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
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
// https://leetcode-cn.com/problems/maximum-width-of-binary-tree/solution/ceng-xu-bian-li-dui-lie-cun-chu-mei-ge-jie-dian-de/
// 计算整个树的最大宽度
int getWidth(BiTree T) {
    if (T == NULL)
        return 0;
    queue<pair<BiTNode *, int>> q;
    int ans = 1;
    q.push({T, 1});
    while (!q.empty()) {
        int qsize = q.size();
        ans = max((q.back().second - q.front().second + 1), ans);
        for (int i = 0; i < qsize; i++) {
            BiTNode *temp = q.front().first;
            int pos = q.front().second;
            q.pop();
            if (temp->lchild != NULL)
                q.push({temp->lchild, 2 * pos});
            if (temp->rchild != NULL)
                q.push({temp->rchild, 2 * pos + 1});
        }
    }
    return ans;
}

void test(ElemType *preOrder, ElemType *inOrder, int length) {
    BiTree T = construct(preOrder, inOrder, length);

    cout << getWidth(T) << endl;
}

int main() {
    ElemType preOrder1[] = {'B', 'E', 'F', 'C', 'G', 'D', 'H'};
    ElemType inOrder1[] = {'F', 'E', 'B', 'G', 'C', 'H', 'D'};
    int length1 = sizeof(preOrder1) / sizeof(ElemType);

    test(preOrder1, inOrder1, length1);

    return 0;
}

// 运行结果：
// 4

