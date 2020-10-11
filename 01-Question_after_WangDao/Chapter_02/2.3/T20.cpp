// 2020-10-11
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct DLinkNode {
    ElemType data;
    int freq = 0;
    struct DLinkNode *pre, *next;
} DLinkNode, *DLinkList;

void outPut(DLinkList L) {
    DLinkNode *p = L->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void reverseOutPut(DLinkList L) {
    if (L == NULL)
        return;
    DLinkNode *p = L;
    while (p->next != NULL)
        p = p->next;
    while (p != L) {
        cout << p->data << " ";
        p = p->pre;
    }
}

void rearInsert(DLinkList &L, ElemType x) {
    DLinkNode *s = new DLinkNode;
    s->data = x;
    L->next = s;
    s->pre = L;
    L = s;
}

DLinkList rearInsertCreate(ElemType arr[], int length) {
    DLinkList L = new DLinkNode;
    DLinkNode *pre = L;
    for (int i = 0; i < length; i++)
        rearInsert(pre, arr[i]);
    pre->next = NULL;
    return L;
}

DLinkNode *locate(DLinkList &L, ElemType e) {
    if (L == NULL)
        return NULL;
    DLinkNode *p = L->next;
    while (p != NULL && p->data != e)
        p = p->next;
    // 经过上面这个while后，会有两种情况:
    // 1 找到。此时p->next != NULL
    // 2 没找到。此时p->next == NULL
    if (p == NULL)
        return NULL;
    p->freq++;
    DLinkNode *q = p->pre;
    while (q != L && q->freq <= p->freq)
        q = q->pre;
    // 经过这个while后，q定位到了要插入位置的前驱
    // 现在要做的就是将p->next指向的结点插入到q->next处，并且还要保证不断链
    // 1 把待操作结点从链表中分离出来，并恢连接两侧使链表完整
    p->pre->next = p->next;
    p->next->pre = p->pre;
    // 2 把待操作结点连接到新位置
    p->next = q->next;
    q->next = p;
    return q;
}

void test(ElemType a[], int length) {
    DLinkList L = rearInsertCreate(a, length);
    locate(L, 7);
    outPut(L);
}

int main() {
    ElemType arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(arr) / sizeof(int);

    test(arr, length);

    return 0;
}

// 输出结果：
// 7 1 2 3 4 5 6 8 9


//------------------------------------------------------------------------------
// 2020.08.31 第三次修订
DLinkNode Locate(DLinkList &L, ElemType x) {
// 此方法采用单链表的遍历模式（采用插入排序的思想）
// 只要把“向前连接”的三行步骤删掉，就可以用在单链表上
    if (L == NULL) {
        return NULL;
    }
    // 1.搜索
    // 通过下面两次while遍历，下面的p和q最终都停在要操作结点的前驱位置
    DLinkNode *p = L;
    while (p->next != NULL && p->next->data != x) {
        p = p->next;
    }
    if (p->next == NULL) {
        return NULL;  // 遍历链表越界，说明表中没有值为x的结点，返回
    }
    p->next->freq++;  // 更新freq属性值
    DLinkNode *q = L;
    while (q->next != p->next && q->next->freq > p->next->freq) {
        q = q->next;  // 这里是从前向后寻找
    }
    if (q->next == p->next) {
        return p->next;  // 遍历后发现不需要插入元素，返回
    }
    // 2.插入
    // 标记值为x的结点的后继位置
    DLinkNode *temp = p->next->next;
    // 向后连接（头插法）
    p->next->next = q->next;
    q->next = p->next;
    p->next = temp;
    // 向前连接
    q->next->prior = q;
    q->next->next->prior = q->next;
    temp->prior = p;
    // 3.返回
    return q->next;
}

// ---------------------------------------------------------------------------
typedef int ElemType;
typedef struct DLinkNode{
    ElemType data;
    struct DLinkNode *prior, *next;
    int freq = 0;
} DLinkNode, *DLinkList;
// 第二次修订
LinkNode * locate(LinkList &L, ElemType x) {
    LinkNode *p, *q;
    for (p = L->next; p != NULL; p = p->next) {
        if (p->data == x) {
            break;
        }
    }
    if (p == NULL) {
        printf("未找到\n");
        exit(0);
    }
    p->freq++;
    for (q = p->pre; (q != L) && (q->freq <= p->freq); q = q->pre);

    p->next->pre = p->pre;
    p->pre->next = p->next;

    q->next->pre = p;
    p->pext = q->next;
    q->next = p;
    p->pre = q;
    return p;
}
// -------------------------------------------------------
#include <stdio.h>
typedef int ElenType;
typedef struct DLinkNode{
    ElemType data;
    struct DLinkNode *pre, *next;
} DLinkNode, *DLinkList;

DLinkList Locate(DLinkList &L, ElemType x) {
    DLinkNode *p = L->next, *q;
    while (p != NULL && p->data != x) {
        p = p->next;
    }
    if (p == NULL) {
        printf("不存在值为x的结点\n");
        exit(0);
    } else {
        p->freq++;
        p->next->pre = p->pre;
        p->pre->next = p->next;
        q = p->pre;
        while (q != L && q->freq <= p->freq) {
            q = q->pre;
        }
        p->next = q->next;
        q->next->pre = p;
        p->pre = q;
        q->next = p;
    }
    return p;
}






