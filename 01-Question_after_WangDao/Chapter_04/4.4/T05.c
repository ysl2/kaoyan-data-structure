typedef struct CSTNode {
    ElemType data;
    struct Node *lchild, *rbro;
} *CSTree;

int getLeaves(CSTree T) {
    if (T == NULL)
        return 0;
    if (T->lchild == NULL)
        return getLeaves(T->rbro) + 1;
    return getLeaves(T->lchild) + getLeaves(T->rbro);
}

