#include <stdbool.h>
#define maxSize 100
// 二叉树的顺序存储
typedef char ElemType;
typedef struct {
    ElemType data;  // 存放结点信息
    bool isEmpty;  // 当前结点是否是空的
    int lchild, rchild;  // 分别指向左孩子与右孩子的下标
} TreeNode;
typedef struct {
    TreeNode node[maxSize];
    int nodenum, root;
    // nodenum相当于链表的length，root是树的根节点下标
} Tree;

Tree T;  // 定义全局变量。如果没有这个，下面形参中的&会报错

void InitTree(Tree &T) {
    for (int i = 0; i < maxSize; i++) {
        T.node[i].isEmpty = true;
        T.node->lchild = T.node->rchild = -1;  // 可以不用这句
    }
    // 下面这两个必须写
    T.nodenum = 0;
    T.root = -1;
}

