typedef struct BiTNode {
     ElemType data;
     struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct {
    BiTNode *node;
    int depth, pos;
} NewNode, *NewTree;

// NewNode的构造方法（假装是java）
//如果想用箭头，必须创建NewTree，而不是NewNode。NewNode只能用点。
NewTree newTree(BiTree node, int depth, int pos) {
    NewTree result = (NewTree) malloc(sizeof(NewNode));
    result->node = node;
    result->depth = depth;
    result->pos = pos;
    return result;
}

int max(int a, int b) {
    return a > b? a : b;
}

int widthOfBinaryTree(BiTree root) {
    NewTreeQueue Q;
    InitQueue(Q);
    EnQueue(Q, newTree(root, 0, 0));
    int curDepth = 0, left = 0, answer = 0;
    while (!QueueEmpty(Q)) {
        NewTree a;
        DeQueue(Q, a);
        if (a->node != NULL) {
            EnQueue(Q, newTree(a->node->lchild, a->depth + 1, a->pos * 2));
            EnQueue(Q, newTree(a->node->rchild, a->depth + 1, a->pos * 2 + 1));
            if (curDepth != a->depth) {
                curDepth = a->depth;
                left = a->pos;
            }
            answer = max(answer, a->pos - left + 1);
        }
    }
    return answer;
}

