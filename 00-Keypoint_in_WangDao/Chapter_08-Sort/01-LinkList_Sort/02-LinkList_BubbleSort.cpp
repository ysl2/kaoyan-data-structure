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

void linklistBubbleSort(LinkList &L) {
    if (L == NULL || L->next == NULL)
        return;
    LinkNode *rear = L->next;
    while (rear != NULL)
        rear = rear->next;
    LinkNode *pre = L, *p = L->next;
    while (rear != L->next) {
        bool flag = false;
        while (p->next != rear) {
            if (p->data > p->next->data) {
                LinkNode *temp = p->next;
                p->next = temp->next;
                pre->next = temp;
                temp->next = p;
                p = temp;
                flag = true;
            } else {
                p = p->next;
                pre = pre->next;
            }
        }
        // 如果本趟没有元素发生交换，则提前结束
        if (flag == false)
            return;
        rear = p;
        pre = L;
        p = L->next;
    }
}

void test(ElemType a[], int length) {
    LinkList L = rearInsertCreate(a, length);
    linklistBubbleSort(L);
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

