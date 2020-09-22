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

