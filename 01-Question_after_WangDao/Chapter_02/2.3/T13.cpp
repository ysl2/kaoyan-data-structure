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

// 注意题目要求反序归并，因此应该选头插法归并
void mergeList(LinkList &A, LinkList &B) {
    LinkNode *p = A->next;
    LinkNode *q = B->next;
    A->next = NULL;
    B->next = NULL;
    delete B;
    while (p != NULL && q != NULL) {
        if (p->data <= q->data) {
            LinkNode *temp = p->next;
            p->next = A->next;
            A->next = p;
            p = temp;
        } else {
            LinkNode *temp = q->next;
            q->next = A->next;
            A->next = q;
            q = temp;
        }
    }
    while (p != NULL) {
        LinkNode *temp = p->next;
        p->next = A->next;
        A->next = p;
        p = temp;
    }
    while (q != NULL) {
        LinkNode *temp = q->next;
        q->next = A->next;
        A->next = q;
        q = temp;
    }
}

void test(ElemType a1[], int length1, ElemType a2[], int length2) {
    LinkList L1 = rearInsertCreate(a1, length1);
    LinkList L2 = rearInsertCreate(a2, length2);

    mergeList(L1, L2);

    outPut(L1);
}

int main() {
    ElemType arr1[] = {1, 3, 5, 7, 9};
    int length1 = sizeof(arr1) / sizeof(int);
    ElemType arr2[] = {2, 4, 6};
    int length2 = sizeof(arr2) / sizeof(int);

    test(arr1, length1, arr2, length2);

    return 0;
}

// 输出结果：
// 9 7 6 5 4 3 2 1


//---------------------------------------------------
void headInsert(LinkList &L, LinkNode *p) {
    // 将p指向的结点从其后续结点中分离出来头插到L中
    // 然后恢复p在原先的后续结点中的0号位置
    LinkNode *temp = p->next;
    p->next = L->next;
    L->next = p;
    p = temp;
}

void merge(LinkList &A, LinkList &B) {
    LinkNode *p = A->next, *q = B->next;
    A->next = NULL;
    while (p != NULL && q != NULL) {
        if (p->data <= q->data) {
            headInsert(A, p);
        } else {
            headInsert(A, q);
        }
    }
    while (p != NULL) {
        headInsert(A, p);
    }
    while (q != NULL) {
        headInsert(A, q);
    }
    free(B);
}

