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

bool searchIstNode(LinkList L, int i, ElemType &result) {
    if (L == NULL || i < 1)
        return false;
    LinkNode *p = L->next;
    while (i > 1 && p != NULL) {
        p = p->next;
        i--;
    }
    if (p == NULL)
        return false;
    result = p->data;
    return true;
}

void test(LinkList &L, int i) {
    ElemType result;
    if (searchIstNode(L, i, result))
        std::cout << result << std::endl;
    else
        std::cout << "false" << std::endl;
}

int main() {
    ElemType arr[] = {1, 3, 5, 7, 9};
    int length = sizeof(arr) / sizeof(int);
    LinkList L = NULL;
    rearInsertCreate(L, arr, length);
    outPut(L);
    std::cout << std::endl;

    // 测试用例如下：

    // 正确情况：
    test(L, 3);
    // 边界情况：
    test(L, 1);
    // 错误情况：
    test(L, 0);
    test(L, 6);

    return 0;
}

// 输出结果：
// 1 3 5 7 9

// 5
// 1
// false
// false
