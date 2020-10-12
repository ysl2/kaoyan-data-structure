#define maxSize 100
// 二叉树的顺序存储
typedef char ElemType;
typedef struct {
    ElemType data;  // 存放结点信息
    bool isEmpty;  // 当前结点是否是空的
    int lchild, rchild;  // 分别指向左孩子与右孩子的下标
} BiTNode;
typedef struct {
    BiTNode node[maxSize];
    int nodenum, root;
    // nodenum相当于链表的length，root是树的根节点下标
} *BiTree;

void InitTree(BiTree &T) {
    for (int i = 0; i < maxSize; i++) {
        T->node[i].isEmpty = true;
        T->node->lchild = T->node->rchild = -1;  // 可以不用这句
    }
    // 下面这两个必须写
    T->nodenum = 0;
    T->root = -1;
}

