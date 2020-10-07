//2020-10-07

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

bool deleteList(LinkList &L) {
    if (L == NULL || L->next == NULL)
        return false;

    LinkNode *minpre = L, *minp = L->next;
    LinkNode *pre = L, *p = L->next;
    for (; p != NULL; pre = pre->next, p = p->next) {
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
    }

    minpre->next = minp->next;
    delete minp;
    return true;
}

void test(int a[], int length) {
    LinkList L = rearInsertCreate(a, length);
    outPut(L);
    deleteList(L);
    outPut(L);
}

int main() {
    ElemType arr1[] = {0, 2, 4, 6, 8, -1, 1, 3, 5, 7, 9};
    int length1 = sizeof(arr1) / sizeof(int);
    ElemType arr2[] = {};
    int length2 = sizeof(arr2) / sizeof(int);

    test(arr1, length1);
    test(arr2, length2);

    return 0;
}

// 输出结果：
// 0 2 4 6 8 -1 1 3 5 7 9
// 0 2 4 6 8 1 3 5 7 9
//
//


// -------------------------------------------
// 2020-09-06 第三次修订
void deleteMin(LinkList &L) {
	if (L == NULL) return ;
    LinkNode *p = L->next, *pre = L;
    LinkNode *minp = L->next, *minpre = L;
    while (p != NULL) {
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
}

