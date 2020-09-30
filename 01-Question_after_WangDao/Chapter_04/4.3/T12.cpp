// 第四次修订 2020-09-30 递归方式 https://blog.csdn.net/LaoJiu_/article/details/50820874
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

bool search(BiTree T, int x) {
    if (T == NULL)
        return false;
    if (T->data == x)
        return true;
    if (search(T->lchild, x) || search(T->rchild, x)) {
        cout << T->data << " ";
        return true;
    }
    return false;
}

// ------------------------------------------------------------------

// 第三次修订
void PostOrder(BiTree T, ElemType x) {
    initStack(S);
    BiTree p = T;
    BiTree r = NULL;
    while (p != NULL || !StackEmpty(S)) {
        if (p != NULL) {
            Push(S, p);
            p = p->lchlid;
        } else {
            GetTop(S, p);
            if (p->rchlid != NULL && p->rchild != r)
                p = p->rchild;
            else {
                Pop(S, p);
                if (visit(S, p, x) == true)
                    exit(0);
                r = p;
                p = NULL;
            }
        }
    }
}

bool visit(Stack S, BiTree p, ElemType x) {
    if (p->data != x)
        return false;
    while (!StackEmpty(S)) {
        BiTNode *temp;
        Pop(S, temp);
        cout << temp->data << " ";
    }
    return true;
}

// ------------------------------------------------------------------
// 第二次修订
void PostOrder(BiTree T) {
    InitStack(S);
    BiTNode *p = T;
    BiTNode *r = NULL;
    while (p != NULL || !IsEmpty(S)) {
        if (p != NULL) {
            Push(S, p);
            p = p->lchild;
            continue;  // 如果不想要else，就必须写这一句
        }
        GetTop(S, p);
        if (p->rchild != NULL && p->rchild != r) {
            p = p->rchild;
            Push(S, p);
            p = p->lchild;
        } else {
            Pop(S, p);
            if (visit(S, p) == 1) {
                exit(0);
            }
            r = p;
            p = NULL;
        }
    }
}

int visit(Stack S, BiTNode *p) {
    if (p->data != x) {
        return 0;
    }
    BiTNode *temp;
    while (!StackEmpty(S)) {
        Pop(S, temp);
        printf("%d\t", temp->data);
    }
    return 1;
}


--------------------------------------------------------------
typedef struct {
    BiTree T;
    int tag;
    // tag = 0表示lchild被访问，tag = 1表示rchild被访问
} Stack;

void search(BiTree T, ElemType x) {
    Stack S[maxSize];
    int top = 0;
    while (T != NULL || top > 0) {
        while (T != NULL && T->data != x) {
            // 入栈
            S[++top].T = T;
            S[top].tag = 0;
            T = T->lchild;
        }
        if (T->data == x) {
            // 输出结果
            for (int i = 1, i <= top; i++) {
                printf("%d\t", S[i]->data);
            }
            exit(0);
        }
        while (top != 0 && S[top].tag == 1) {
            top--;
        }
        if (top != 0) {
            S[top].tag = 1;
            T = S[top].T->rchild;
        }
    }
}

