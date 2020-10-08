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

// 与第10题思路相同，把B链表的尾插换成头插就行了
LinkList seprateList(LinkList &A) {
    if (A == NULL || A->next == NULL)
        return NULL;
    LinkNode *pre = A, *p = A->next;
    LinkList B = new LinkNode;
    B->next = NULL;  // 对于头插必须限制最后一个结点指向NULL，否则在遍历B的时候会造成无限循环遍历
    while (p != NULL && p->next != NULL) {
        p = p->next;
        pre = pre->next;
        pre->next = p->next;
        // 只改了下面这两行：
        p->next = B->next;
        B->next = p;
        //
        p = pre->next;
    }
    return B;
}

void test(int a[], int length) {
    LinkList L = rearInsertCreate(a, length);
    LinkList B = seprateList(L);

    outPut(L);
    outPut(B);
}

int main() {
    ElemType arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length1 = sizeof(arr1) / sizeof(int);

    test(arr1, length1);

    return 0;
}

// 输出结果：
// 1 3 5 7 9
// 8 6 4 2


//----------------------------------------------------------------
LinkList seprate(LinkList L) {
// L表相当于题中的C表和A表。A表（L表）尾插，B表头插
    LinkList B = (LinkList) malloc(sizeof(LinkNode));
    B->next = NULL;
    LinkNode *p = L->next;
    L->next = NULL;  // 把L摘下来
    LinkNode *r = L;  // L的工作指针。B因为是头插，所以不需要工作指针
    while (p != NULL) {
        // L表尾插
        r->next = p;
        r = r->next;
        // 过渡语句1
        p = p->next;
        LinkNode *temp = p->next;
        // B表头插
		// 这里不用判断p是NULL的情况。
		// 因为a和b最终下标都是n，说明C有2n个结点，一定是偶数。
        p->next = B->next;
        B->next = p;
        // 过渡语句2
        p = temp;
    }
    r->next = NULL;
    return B;
}

