// 2020-10-08
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

void outPut(LinkList L) {
    LinkNode *p = L->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void rearInsert(LinkList &L, ElemType x) {
    LinkNode *s = new LinkNode;
    s->data = x;
    L->next = s;
    L = s;
}

LinkList rearInsertCreate(ElemType arr[], int length) {
    LinkList L = new LinkNode;
    LinkNode *p = L;
    for (int i = 0; i < length; i++)
        rearInsert(p, arr[i]);
    p->next = NULL;
    return L;
}

// 两个链表构成了一个Y型链表，从某结点之后共享结点，找出开始分叉的那个结点。注意两个链表的长度不一定相同。

// 整个算法由下面三个函数构成：

// 1
int getLength(LinkList L) {
    int i = 0;
    while (L->next != NULL) {
        i++;
        L = L->next;
    }
    return i;
}

// 2
LinkNode *get(LinkList A, int &length1, LinkList B, int &length2) {
    if (length1 == 0)
        length1 = getLength(A);
    if (length2 == 0)
        length2 = getLength(B);
    if (length1 == 0 || length2 == 0)
        return NULL;
    if (length1 > length2)
        return get(B, length2, A, length1);

    // 通过上面的步骤，A的长度始终小于等于B的长度

    LinkNode *p = A, *q = B;
    for (int i = 0; i < (length2 - length1); i++)
        q = q->next;
    while (p->next != NULL && p->next->data != q->next->data) {
        p = p->next;
        q = q->next;
    }
    return p->next;
}

// 3
void getCommon(LinkList A, LinkList B) {
    int length1 = 0, length2 = 0;
    LinkNode *common = get(A, length1, B, length2);
    if (common != NULL)
        cout << common->data << endl;
    else
        cout << "NULL" << endl;
}

int main() {
    ElemType arr1[] = {1, 3, 5, 7, 9, 11, 13, 20, 21, 22, 23, 24};
    int length1 = sizeof(arr1) / sizeof(int);
    ElemType arr2[] = {2, 4, 6, 12, 20, 21, 22, 23, 24};
    int length2 = sizeof(arr2) / sizeof(int);
    ElemType arr3[] = {};
    int length3 = sizeof(arr3) / sizeof(int);

    LinkList A = rearInsertCreate(arr1, length1);
    LinkList B = rearInsertCreate(arr2, length2);
    LinkList C = rearInsertCreate(arr3, length3);

    getCommon(A, B);
    getCommon(A, C);

    return 0;
}

// 输出结果：
// 20
// NULL

//--------------------------------------------------------------------------
LinkNode *getCommon2(LinkList &A, LinkList &B) {
    int len1 = getLength(A), len2 = getLength(B);
    int n = (len2 > len1) ? len2 - len1 : len1 - len2;
    LinkNode *p = A->next, *q = B->next;
    for (; len2 > len1 && n > 0; q = q->next, n--)
        ;
    for (; len1 > len2 && n > 0; p = p->next, n--)
        ;
    while (p != NULL && p->data != q->data) {
        p = p->next;
        q = q->next;
    }
    return p;
}
