// 2020-10-09
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

// 最简单的办法是：建立一个辅助数组，然后遍历并维护这个数组统计出现的次数

// 或者不建立辅助数组，而采用双指针的方式：
LinkList getCommon(LinkList A, LinkList B) {
    if (A == NULL || B == NULL)
        return NULL;
    LinkList C = new LinkNode;
    C->next = NULL;
    LinkNode *r = C;
    LinkNode *p = A->next, *q = B->next;
    while (p != NULL && q != NULL) {
        if (p->data == q->data) {
            LinkNode *s = new LinkNode;
            s->data = p->data;
            r->next = s;
            r = r->next;
            p = p->next;
            q = q->next;
        } else if (p->data < q->data)
            p = p->next;
        else
            q = q->next;
    }
    r->next = NULL;
    return C;
}

void test(ElemType a1[], int length1, ElemType a2[], int length2) {
    LinkList L1 = rearInsertCreate(a1, length1);
    LinkList L2 = rearInsertCreate(a2, length2);

    outPut(getCommon(L1, L2));
}

int main() {
    ElemType arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length1 = sizeof(arr1) / sizeof(int);
    ElemType arr2[] = {2, 4, 6, 8};
    int length2 = sizeof(arr2) / sizeof(int);
    ElemType arr3[] = {};
    int length3 = sizeof(arr3) / sizeof(int);

    test(arr1, length1, arr2, length2);
    test(arr2, length2, arr3, length3);

    return 0;
}

// 输出结果：
// 2 4 6 8
//


//---------------------------------------------------------------------
// 2020.08.31 第二次修订
LinkList getLink(LinkList &A, LinkList &B) {
    LinkNode *p = A->next;
    LinkNode *q = B->next;
    LinkList C = (LinkList) malloc(sizeof(LinkNode));
    C->next = NULL;
    LinkNode *r = C;
    while (p != NULL && q != NULL) {
        if (p->data == q->data) {
            // 创建
            LinkNode *temp = (LinkNode *) malloc(sizeof(LinkNode));
            temp->data = p->data;
            // 尾插
            r->next = temp;
            r = r->next;
            // 后移
            p = p->next;
            q = q->next;
            continue;
        }
        // 后移
        if (p->data < q->data) {
            p = p->next;
        } else {
            q = q->next;
        }
    }
    // 如果A或B某一个是空的，会直接跳到这里向下执行
    r->next = NULL;
    return C;
}
----------------------------------------------------------
LinkList getCommon(LinkList A, LinkList B) {
    LinkNode *p = A->next, *q = B->next, *r, *s;
    LinkList C = (LinkList) malloc(sizeof(LinkNode));
    r = C;
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            p = p->next;
        } else if (p->data > q->data) {
            q = q->next;
        } else {
            s = (LinkNode *) malloc(sizeof(LinkNode));
            s->data = p->data;
            r->next = s;
            r = s;
            p = p->next;
            q = q->next;
        }
    }
    r->next = NULL;
    return C;
}

