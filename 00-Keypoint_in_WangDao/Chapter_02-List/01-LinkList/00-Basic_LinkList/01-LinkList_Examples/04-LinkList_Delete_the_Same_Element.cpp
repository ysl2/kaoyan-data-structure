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

// 注意：本题中结点值按顺序排列。如果是无序排列，需要再定义一个辅助数组或者辅助链表，用来判断是否有重复元素
void deleteTheSameElement(LinkList &L) {
    LinkNode *pre = L->next;
    if (pre == NULL)
        return;
    LinkNode *p = pre->next;
    if (p == NULL)
        return;
    while (pre != NULL && p != NULL) {
        if (pre->data != p->data) {
            pre = pre->next;
            p = p->next;

        } else {
            pre->next = p->next;
            delete p;
            p = pre->next;
        }
    }
}

int main() {
    ElemType arr[] = {0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2};
    int length = sizeof(arr) / sizeof(int);

    LinkList L = NULL;

    rearInsertCreate(L, arr, length);
    outPut(L);

    deleteTheSameElement(L);
    outPut(L);
    
    return 0;
}

// 输出结果：
// 0 0 0 0 1 1 1 1 2 2 2 2
// 0 1 2
