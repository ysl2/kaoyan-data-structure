// 2020-10-11
#include <iostream>
#include <string.h>
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

// 由于n是正整数，因此结点data的取值范围是[1, n]，一共n个数，所以辅助数组的大小为n
// 王道上说要n + 1，其实他是想把下标0空出来，直接从1开始用。但是我这个在录入的时候减了1，最终效果是一样的
void deleteList(LinkList &L, ElemType n) {
    if (L == NULL)
        return;
    ElemType *B = new ElemType[n];
    memset(B, 0, n * sizeof(ElemType));
    LinkNode *pre = L;
    LinkNode *p = L->next;
    while (p != NULL) {
        if (B[abs(p->data) - 1] == 0) {
            B[abs(p->data) - 1] = 1;
            pre = pre->next;
            p = p->next;
        } else {
            pre->next = p->next;
            delete p;
            p = pre->next;
        }
    }
    delete[] B;
}

void test(ElemType a[], int length, ElemType n) {
    LinkList L = rearInsertCreate(a, length);
    deleteList(L, n);
    outPut(L);
}

int main() {
    ElemType arr[] = {1, -1, 2, -1, 3, -3, 4, -4, 5, -5, 1, 2, 3, 4, 5};
    int length = sizeof(arr) / sizeof(int);
    int n = 5;

    test(arr, length, n);

    return 0;
}

// 输出结果：
// 1 2 3 4 5


//--------------------------------------------------------------------------
// 2020-09-07 第三次修订
#include <stdlib.h>  // abs函数的库声明
#include <string.h>  // memset函数的库声明

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

LinkList L;

void delete(LinkList &L, int n) {
// abs(data) <= n，所以abs(data) ∈ [0, n]，一共n + 1个值
    int *B = (int *) malloc(sizeof(int) * (n + 1));
    memset(B, 0, sizeof(int) * (n + 1));  // 给数组赋初值0
    LinkNode *pre = L;  // 取前驱指针
    while (pre->next != NULL) {
        int index = abs(pre->next->data);
        if (B[index] == 0) {  // 第一次出现
            B[index] = 1;
			pre = pre->next;
        } else {  // 之前已经出现过，但是现在又出现了
            LinkNode *temp = pre->next;
            pre->next = temp->next;
            free(temp);
        }
    }
    free(B);  // 释放辅助空间
}


---------------------------------------------------------------
typedef struct Node {
    int data;
    struct Node *link;
} LinkNode, *LinkList;

void func(LinkNode *L, int n) {
    LinkNode *p = L, *r;
    int *B, m;
    B = (int *) malloc(sizeof(int) * (n + 1));
    memset(B, 0, sizeof(int) * (n + 1));
    while (p->link != NULL) {
        m = (p->link->data > 0)? (p->link->data) : (-1) * (p->link->data);
        if (*(B + m) == 0) {
            *(B + m) = 1;
            p = p->link;
        } else {
            r = p->link;
            p->link = r->link;
            free(r);
        }
    }
    free(B);
}
