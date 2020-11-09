// 2020-10-12
#define maxSize 100
#define NULL 0

typedef char ElemType;
typedef struct {
    ElemType data;  // 存放结点信息
    bool isEmpty;  // 当前结点是否是空的
    int lchild, rchild;  // 分别指向左孩子与右孩子的下标
} SqBiTNode;
typedef struct {
    SqBiTNode node[maxSize];
    int nodenum, root;
    // nodenum相当于链表的length，root是树的根节点下标
} *SqBiTree;

ElemType getAncestor(SqBiTree T, int i, int j) {
    if (T->node[i].isEmpty || T->node[j].isEmpty)
        return NULL;
    while (i != j) {
        if (i > j)
            i /= 2;
        else
            j /= 2;
    }
    return T->node[i].data;
}


//------------------------------------------------------
ElemType getCommonAncestor(SqBiTree T, int i, int j) {
    if (T.data[i] == "#" || T.data[j] == "#")
        return NULL;
    while (i != j) {
        if (i > j)
            i /= 2;
        else
            j /= 2;
    }
    return T.data[i];
}
