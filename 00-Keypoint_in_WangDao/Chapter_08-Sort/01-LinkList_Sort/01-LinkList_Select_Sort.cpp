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

    // 完成初始化后，每次都从B链表中找到一个最大的，然后尾插到L
    while (B->next != NULL) {
        LinkNode *maxpre = B;
        LinkNode *maxp = B->next;
        LinkNode *pre = B;
        LinkNode *p = B->next;
        while (p != NULL) {
            if (p->data < maxp->data) {
                maxp = p;
                maxpre = pre;
            }
            p = p->next;
            pre = pre->next;
        }
        // 到这一步找到了最大的结点
        maxpre->next = maxp->next;
        r->next = maxp;
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

