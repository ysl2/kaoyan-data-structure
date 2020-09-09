typedef int ElemType;
typedef struct BSTNode {
    ElemType key;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

BSTree T;

// 非递归
BSTNode *search(BSTree T, int key) {
    while (T != NULL) {
        if (T->key == key) break;
        if (T->key < key) T = T->rchild;
        else T = T->lchild;
    }
    return T;
}

// 递归
BSTNode *search_recur(BSTree T, int key) {
    if (T == NULL) return NULL;
    if (T->key == key) return T;
    return (T->key < key)? search_recur(T->rchild, key) : search_recur(T->lchild, key);
}