// 2020-10-12
#define NULL 0
#define NULLCHAR '#'

typedef char ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int count = 1;
ElemType getData(BiTree T, int k) {
    if (T == NULL)
        return NULLCHAR;
    if (count == k)
        return T->data;
    k++;
    ElemType result = getData(T->lchild, k);
    if (result != NULLCHAR)
        return result;
    result = getData(T->rchild, k);
    return result;
}

//---------------------------------------
int i = 1;
ElemType PreNode(BiTree T, int k) {
    if (T == NULL) {
        return '#';  // 表示空结点
    }
    if (i == k) {
        return T->data;
    }
    i++;
    ElemType ch = PreNode(T->lchild, k);
    if (ch == '#') {
        ch = PreNode(T->rchild , k);
    }
    return ch;
}

