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

// 这是我自己写的。还有一个是别人写的。在王道课后题7.4 T04
void linklistSelectSort(LinkList &L) {
    LinkNode *r = L;
    LinkList B = new LinkNode;
    B->next = L->next;
    L->next = NULL;

    // 完成初始化后，每次都从B链表中找到一个最小的，然后尾插到L
    // 这样每次都能从前往后确定出一个次小的，一直确定到最后，整体就是从小到大排好的
    while (B->next != NULL) {
        LinkNode *minpre = B;
        LinkNode *minp = B->next;
        LinkNode *pre = B;
        LinkNode *p = B->next;
        while (p != NULL) {
            if (p->data < minp->data) {
                minp = p;
                minpre = pre;
            }
            p = p->next;
            pre = pre->next;
        }
        // 到这一步找到了最小的结点
        minpre->next = minp->next;
        r->next = minp;
        r = r->next;
    }
    r->next = NULL;
    delete B;
}

void test(ElemType a[], int length) {
    LinkList L = rearInsertCreate(a, length);
    linklistSelectSort(L);
    outPut(L);
}

int main() {
    ElemType arr[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(arr) / sizeof(int);

    test(arr, length);

    return 0;
}

// 输出结果：
// 0 1 2 3 4 5 6 7 8 9

