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
}

void headInsert(LinkList &L, ElemType x) {
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = L->next;
    L->next = s;
}

void headInsertCreate(LinkList &L, ElemType arr[], int length) {
    L = new LinkNode;  // 这种方式与下面的纯C语言动态申请的效果相同。注意：这里new的是LinkNode（是正确的），而下面malloc的空间则最终强制转换为了（LinkNode *)
    L->next = NULL;
    for (int i = 0; i < length; i++) {
        headInsert(L, arr[i]);
    }
}

int main() {
    ElemType arr[] = {1, 3, 5, 7, 9};
    int length = sizeof(arr) / sizeof(int);
    LinkList L = NULL;
    headInsertCreate(L, arr, length);
    outPut(L);
    return 0;
}

// 输出结果：
// 9 7 5 3 1
