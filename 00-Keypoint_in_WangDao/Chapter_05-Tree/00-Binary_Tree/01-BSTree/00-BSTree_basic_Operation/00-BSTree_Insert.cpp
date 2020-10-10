#define NULL 0

typedef int ELemType;
typedef struct BSTNode {
    ELemType key;
    struct BSTNode *lchind, *rchild;
} BSTNode, *BSTree;

bool BSTreeInsert(BSTree T, ELemType key) {
    if (T == NULL) {
        T = new BSTNode;
        T->lchind = T->rchild = NULL;
        T->key = key;
        return true;
    }
    if (T->key == key)
        return false;
    if (T->key < key)
        return BSTreeInsert(T->rchild, key);
    return BSTreeInsert(T->lchind, key);
}
