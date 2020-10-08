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

void sortPrintAndDeleteList(LinkList &L) {
    if (L == NULL)
        return;
    while (L->next != NULL) {
        LinkNode *pre = L, *p = L->next;
        LinkNode *minpre = L, *minp = L->next;
        while (p != NULL) {
            if (p->data < minp->data) {
                minp = p;
                minpre = pre;
            }
            p = p->next;
            pre = pre->next;
        }
        cout << minp->data << " ";
        minpre->next = minp->next;
        delete minp;
    }
}

int main() {
    ElemType arr1[] = {1, 3, 5, 7, 9, 11, 13, 20, 21, 22, 23, 24};
    int length1 = sizeof(arr1) / sizeof(int);

    LinkList A = rearInsertCreate(arr1, length1);

    sortPrintAndDeleteList(A);

    return 0;
}

// 输出结果：
// 1 3 5 7 9 11 13 20 21 22 23 24

//---------------------------------------------------------------
// 方法1：双指针
bool minDelete1(LinkList &L) {
	if (L == NULL || L->next == NULL) return false;
    LinkNode *minp, *p;
    // minp是元素最小值结点的前驱结点的指针
    while (L->next != NULL) {
        minp = L;
        p = L->next;
        while (p->next != NULL) {
            if (p->next->data < minp->next->data) {
                minp = p;
            }
            p = p->next;
        }
        visit(minp->next);
        LinkNode *temp = minp->next;
        minp->next = minp->next->next;
        free(temp);
    }
    free(L);
	return true;
}
// 方法2：四指针。思想相同，但是增加了代码可读性
bool minDelete(LinkList &L) {
    if (L == NULL || L->next == NULL) return false;
    LinkNode *p, *pre, *minp, *minpre;
    while (L->next != NULL) {
        p = L->next;
        pre = L;
        minp = L->next;
        minpre = L;
        while (p != NULL) {
            if (p->data < minp->data) {
                minp = p;
                minpre = pre;
            }
            pre = p;
            p = p->next;
        }
        visit(minp);
        minpre->next = minp->next;
        free(minp);
    }
    free(L);
    return true;
}

