#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

typedef char ElemType;  // 把char强制转换成int。这样我可以使用上面写的测试用例，不然我还得重新写
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
    bool isLeaf = false;
} BiTNode, *BiTree;

typedef struct LinkNode {
    BiTNode *node;
    struct LinkNode *next;
} LinkNode, *LinkList;

BiTNode *construct(ElemType *preOrder, ElemType *midOrder, int len) {
    if (preOrder == NULL || midOrder == NULL || len <= 0)
        return NULL;

    //先根遍历（前序遍历）的第一个值就是根节点的键值
    ElemType rootKey = preOrder[0];
    BiTree T = new BiTNode;
    T->data = rootKey;
    T->lchild = T->rchild = NULL;
    if (len == 1 && *preOrder == *midOrder)  //只有一个节点
        return T;

    //在中根遍历（中序遍历）中找到根节点的值
    ElemType *rootMidOrder = midOrder;
    int leftLen = 0;  //左子树节点数
    while (*rootMidOrder != rootKey && rootMidOrder <= (midOrder + len - 1)) {
        ++rootMidOrder;
        ++leftLen;
    }
    if (*rootMidOrder != rootKey)  //在中根序列未找到根节点,输入错误
        return NULL;

    if (leftLen > 0) {  //构建左子树
        T->lchild = construct(preOrder + 1, midOrder, leftLen);
    }
    if (len - leftLen - 1 > 0) {  //构建右子树
        T->rchild = construct(preOrder + leftLen + 1, rootMidOrder + 1, len - leftLen - 1);
    }
    return T;
}

void visit(BiTree T) {
    std::cout << T->data << " ";
}

void PostOrder(BiTree T) {
    if (T == NULL)
        return;
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    visit(T);
}

void InOrder(BiTree T) {
    if (T == NULL)
        return;
    InOrder(T->lchild);
    visit(T);
    InOrder(T->rchild);
}

void PreOrder(BiTree T) {
    if (T == NULL)
        return;
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}

void setLeaf(BiTree &T) {
    if (T == NULL)
        return;
    if (T->lchild == NULL && T->rchild == NULL)
        T->isLeaf = true;
    setLeaf(T->lchild);
    setLeaf(T->rchild);
}

LinkList L;

void link(BiTree &T, LinkNode *&r) {
    if (T == NULL)
        return;
    if (T->isLeaf == true) {
        LinkNode *s = new LinkNode;
        s->node = T;
        s->next = NULL;
        r->next = s;
        r = s;
    }
    link(T->lchild, r);
    link(T->rchild, r);
}

void linkLeafNode(BiTree &T) {
    L = new LinkNode;
    L->next = NULL;
    LinkNode *r = L;

    link(T, r);

    LinkNode *p = L->next;

    while (p != NULL) {
        if (p->next != NULL)
            p->node->rchild = p->next->node;
        else
            p->node->rchild = NULL;
        p = p->next;
    }
}

bool flag = false;

void outputAllLeaves(BiTree T) {
    if (flag == true)
        return;
    if (T == NULL)
        return;
    if (T->isLeaf == true) {
        BiTNode *temp = T;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->rchild;
        }
        flag = true;
        return;
    }
    outputAllLeaves(T->lchild);
    outputAllLeaves(T->rchild);
}

BiTree getTreeWithLeafFlag(ElemType *preOrder, ElemType *inOrder, int length) {
    BiTree T = construct(preOrder, inOrder, length);
    setLeaf(T);
    return T;
}

void test(ElemType *preOrder, ElemType *inOrder, int length) {
    BiTree T = getTreeWithLeafFlag(preOrder, inOrder, length);

    PreOrder(T);
    cout << endl;

    InOrder(T);
    cout << endl;

    PostOrder(T);
    cout << endl;

    // 在此处写要测试的函数...

    linkLeafNode(T);

    outputAllLeaves(T);

    cout << endl;
}

int main() {
    ElemType preOrder1[] = {'B', 'E', 'F', 'C', 'G', 'D', 'H'};
    ElemType inOrder1[] = {'F', 'E', 'B', 'G', 'C', 'H', 'D'};
    int length1 = sizeof(preOrder1) / sizeof(ElemType);
    // ElemType preOrder2[] = {'B', 'E', 'F', 'H', 'C', 'G', 'D'};
    // ElemType inOrder2[] = {'F', 'E', 'H', 'B', 'G', 'C', 'D'};
    // int length2 = sizeof(preOrder2) / sizeof(ElemType);

    test(preOrder1, inOrder1, length1);

    // test(preOrder2, inOrder2, length2);

    return 0;
}

// 运行结果：
// B E F C G D H
// F E B G C H D
// F E G H D C B
// F G H


//--------------------------------------------------------------------------------
TreeLinkList L, pre = NULL;
TreeLinkList InOrder(BiTree T) {
    if (T == NULL)
        return NULL;
    InOrder(T->lchild);
    if (T->lchild == NULL && T->rchild == NULL) {
        if (pre == NULL) {
            L = T;  // 保存找到的第一个叶子结点（k指针）
            pre = T;
        } else {
            pre->rchild = T;  // 链接时用叶子结点的rchild域存放指针
            pre = T;
        }
    }
    InOrder(T->rchild);
    return L;
}

