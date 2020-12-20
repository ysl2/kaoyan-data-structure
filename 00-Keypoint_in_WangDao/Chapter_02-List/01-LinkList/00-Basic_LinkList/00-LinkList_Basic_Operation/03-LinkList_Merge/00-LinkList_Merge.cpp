#include <cstdlib>
#include <iostream>

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

void outPut(LinkList L) {
    LinkNode *p = L->next;
    while (p != NULL) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

void rearInsert(LinkList &L, ElemType x) {
    LinkNode *s = new LinkNode;
    s->data = x;
    L->next = s;
    L = s;
}

void rearInsertCreate(LinkList &L, ElemType arr[], int length) {
    L = new LinkNode;
    LinkNode *p = L;
    for (int i = 0; i < length; i++) {
        rearInsert(p, arr[i]);
    }
    p->next = NULL;
}

// 合并两个递增有序的单链表，使其合并后依然保持有序
// 本题也是求A = A ∪ B的算法
// 山大书上采用定义了一个C链表返回的方式，实际上这并不是必须要这么做，也可以直接用A返回：
void merge(LinkList &A, LinkList &B) {
    LinkNode *p = A->next;
    LinkNode *q = B->next;
    A->next = NULL;
    LinkNode *r = A;
    while (p != NULL && q != NULL) {
        if (p->data == q->data) {
            r->next = p;
            r = r->next;
            p = p->next;
            LinkNode *temp = q->next;
            delete q;
            q = temp;
        } else if (p->data < q->data)  {
            r->next = p;
            r = r->next;
            p = p->next;
        } else {
            r->next = q;
            r = r->next;
            q = q->next;
        }
    }
    while (p != NULL) {
        r->next = p;
        r = r->next;
        p = p->next;
    }
    while (q != NULL) {
        r->next = q;
        r = r->next;
        q = q->next;
    }
    r->next = NULL;
    delete B;
}

void test() {
    ElemType arr1[] = {-7, 3, 12, 23};
    int length1 = sizeof(arr1) / sizeof(arr1[0]);
    ElemType arr2[] = {-2, 4, 9, 15};
    int length2 = sizeof(arr2) / sizeof(arr2[0]);
    LinkList L1 = NULL;
    LinkList L2 = NULL;
    rearInsertCreate(L1, arr1, length1);
    rearInsertCreate(L2, arr2, length2);
    outPut(L1);
    outPut(L2);
    merge(L1, L2);
    outPut(L1);
}

int main() {
    test();
    return 0;
}

// 输出结果：
// -7 3 12 23
// -2 4 9 15
// -7 -2 3 4 9 12 15 23
