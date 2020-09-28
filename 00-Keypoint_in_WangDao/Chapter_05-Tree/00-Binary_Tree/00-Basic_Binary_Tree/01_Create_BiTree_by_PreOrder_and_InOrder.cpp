// 参考：https://cloud.tencent.com/developer/article/1176915
#include <cstdlib>
#include <iostream>
using std::cout;

typedef char ElemType;
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

void test(ElemType *preOrder, ElemType *inOrder, int length) {
    BiTree T = construct(preOrder, inOrder, length);
    PostOrder(T);
}

int main() {
    ElemType preOrder1[] = {'B', 'E', 'F', 'C', 'G', 'D', 'H'};
    ElemType inOrder1[] = {'F', 'E', 'B', 'G', 'C', 'H', 'D'};
    int length1 = sizeof(preOrder1) / sizeof(ElemType);
    test(preOrder1, inOrder1, length1);
}

// 运行结果：
// F E G H D C B
