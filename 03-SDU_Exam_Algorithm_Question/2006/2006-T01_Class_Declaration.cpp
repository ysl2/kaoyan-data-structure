template <class T>
class BinaryTreeNode {
   public:
    BinaryTreeNode(const T &e, BinaryTreeNode *lchild, BinaryTreeNode *rchild) {
        data = e;
        BinaryTreeNode::lchild = lchild;
        BinaryTreeNode::rchild = rchild;
    }

   private:
    T data;
    BinaryTreeNode<T> *lchild, *rchild;
};
