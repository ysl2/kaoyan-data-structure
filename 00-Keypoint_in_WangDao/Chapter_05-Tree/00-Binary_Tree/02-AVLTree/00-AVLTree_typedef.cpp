typedef int ElemType;
typedef struct AVLNode {
    ElemType key;
    int balance;
    struct AVLNode *lchild, *rchild;
} AVLNode, *AVLTree;

