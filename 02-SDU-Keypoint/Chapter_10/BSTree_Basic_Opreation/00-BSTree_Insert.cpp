#include <cstdlib>
typedef int ELemType;
typedef struct BSTNode {
    ELemType key;
    struct BSTNode *lchind, *rchild;
} BSTNode, *BSTree;

int BSTreeInsert1(BSTree T, ELemType key) {
    if (T == NULL) {
        T = new BSTNode;
        T->lchind = T->rchild = NULL;
        T->key = key;
        return 1;
    }
    if (T->key == key)
        return 0;
    if (T->key < key)
        return BSTreeInsert1(T->rchild, key);
    return BSTreeInsert1(T->lchind, key);
}
