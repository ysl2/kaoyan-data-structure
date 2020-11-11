// 2020-10-01 第三次修订
#define NULL 0

typedef int ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTNode *ancestor(BiTree T, BiTNode *p, BiTNode *q) {
    if (T == NULL)
        return NULL;
    if (T == p || T == q)
        return T;
    BiTNode *left = ancestor(T->lchild, p, q);
    BiTNode *right = ancestor(T->rchild, p, q);
    if (left != NULL && right != NULL)
        return T;
    return (left != NULL) ? left : right;
}

//--------------------------------------------

// 2020-09-21
BiTNode *lowestCommonAncestor(BiTNode *T, BiTNode *p, BiTNode *q) {
    if (!T || T == p || T == q)
        return T;
    BiTNode *left = lowestCommonAncestor(T->lchild, p, q);
    BiTNode *right = lowestCommonAncestor(T->rchild, p, q);
    if (left && right)
        return T;
    return left ? left : right;
}

//--------------------------------------------
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!root || root == p || root == q) return root;
	TreeNode *left = lowestCommonAncestor(root->left, p, q);
	TreeNode *right = lowestCommonAncestor(root->right, p, q);
	if (left && right) return root;
	return left ? left : right;
}

