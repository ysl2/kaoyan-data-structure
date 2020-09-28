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

LinkNode *searchTheLastE(LinkList L, ElemType e, int &index) {
    LinkNode *locate = NULL;
    LinkNode *p = L->next;
    for (int i = 1; p != NULL; p = p->next, i++) {
        if (p->data == e) {
            locate = p;
            index = i;
        }
    }
    return locate;
}

void test(LinkList &L, ElemType e) {
    LinkNode *result;
    int index;
    if ((result = searchTheLastE(L, e, index)) != NULL)
        std::cout << index << std::endl;
    else
        std::cout << "false" << std::endl;
}

int main() {
    ElemType arr[] = {0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2};
    int length = sizeof(arr) / sizeof(int);

    LinkList L = NULL;

    rearInsertCreate(L, arr, length);
    outPut(L);

    // 正确用例：
    test(L, 1);

    // 错误用例：
    test(L, 3);

    return 0;
}

// 输出结果：
// 0 0 0 0 1 1 1 1 2 2 2 2
// 8
// false
