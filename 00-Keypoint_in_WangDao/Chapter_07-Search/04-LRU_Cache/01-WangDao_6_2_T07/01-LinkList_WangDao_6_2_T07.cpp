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

// 本题类似于LRU缓存。（并不完全是）
// 关键词：LRU缓存、页面置换算法
int search(LinkList L, ElemType key) {
    LinkNode *pre = L, *p = L->next;
    int i = 1;
    for (; p != NULL && p->data != key; pre = pre->next, p = p->next, i++)
        ;
    if (p != NULL && pre != L) {  // 如果找到了，并且不是第一个结点
        int temp = pre->data;
        pre->data = p->data;
        p->data = temp;
        return i - 1;
    } else
        return p == NULL ? -1 : i;  // 否则，返回原先的位置
}

void test(ElemType a[], int length, ElemType key) {
    LinkList L = rearInsertCreate(a, length);
    search(L, key);
    outPut(L);
}

int main() {
    ElemType arr[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(arr) / sizeof(arr[0]);

    test(arr, length, 1);

    return 0;
}

// 输出结果：
// 0 2 4 6 1 8 3 5 7 9

