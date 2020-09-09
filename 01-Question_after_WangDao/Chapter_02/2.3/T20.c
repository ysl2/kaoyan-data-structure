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

typedef int ElemType;
typedef struct DLinkNode{
    ElemType data;
    struct DLinkNode *prior, *next;
    int freq = 0;
} DLinkNode, *DLinkList;
---------------------------------------------------------------------------
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
-------------------------------------------------------
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






