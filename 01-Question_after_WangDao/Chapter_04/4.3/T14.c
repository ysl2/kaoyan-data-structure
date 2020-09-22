// 2020-09-22
int widthOfBinaryTree(BiTNode *T) {
    if (!T)
        return 0;
    queue<pair<BiTNode *, int>> q;
    int ans = 1;
    q.push({T, 1});
    while (!q.empty()) {
        int qsize = q.size();
        ans = max((q.back().second - q.front().second + 1), ans);
        for (int i = 0; i < qsize; i++) {
            BiTNode *p = q.front().first;
            int pos = q.front().second;
            q.pop();
            if (p->lchild)
                q.push({p->lchild, 2 * pos});
            if (p->rchild)
                q.push({p->rchild, 2 * pos + 1});
        }
    }
    return ans;
}
//--------------------------------------------------
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct {
    BiTNode *p;
    int depth, pos;
} AnnotatedNode, *AnnotatedTree;

// AnnotatedNode的构造方法（假装是java）
//如果想用箭头，必须创建AnnotatedTree，而不是AnnotatedNode。AnnotatedNode只能用点。
AnnotatedTree newTree(BiTree p, int depth, int pos) {
    AnnotatedTree result = (AnnotatedTree)malloc(sizeof(AnnotatedNode));
    result->p = p;
    result->depth = depth;
    result->pos = pos;
    return result;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int widthOfBinaryTree(BiTree T) {
    AnnotatedTreeQueue Q;
    InitQueue(Q);
    EnQueue(Q, newTree(T, 0, 0));
    int curDepth = 0, lchild = 0, answer = 0;
    while (!QueueEmpty(Q)) {
        AnnotatedTree a;
        DeQueue(Q, a);
        if (a->p != NULL) {
            EnQueue(Q, newTree(a->p->lchild, a->depth + 1, a->pos * 2));
            EnQueue(Q, newTree(a->p->rchild, a->depth + 1, a->pos * 2 + 1));
            if (curDepth != a->depth) {
                curDepth = a->depth;
                lchild = a->pos;
            }
            answer = max(answer, a->pos - lchild + 1);
        }
    }
    return answer;
}
