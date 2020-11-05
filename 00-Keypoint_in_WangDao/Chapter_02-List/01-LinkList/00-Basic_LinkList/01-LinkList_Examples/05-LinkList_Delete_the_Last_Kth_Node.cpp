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

// 王道课后题有这道题：2.3 T21
bool deleteTheLastKthNode(LinkList &L, int k) {
    if (k <= 0)
        return false;
    LinkNode *pre = L;  // 慢指针
    LinkNode *p = L;    // 快指针
    while (k > 0 && p->next != NULL) {
        p = p->next;
        k--;
    }
    if (k > 0 && p->next == NULL)
        return false;
    while (p->next != NULL) {
        p = p->next;
        pre = pre->next;
    }
    LinkNode *temp = pre->next;
    pre->next = temp->next;
    delete temp;
    return true;
}

void test(LinkList &L, int i) {
    if (deleteTheLastKthNode(L, i))
        outPut(L);
    else
        std::cout << "false" << std::endl;
}

int main() {
    ElemType arr[] = {1, 2, 3, 4, 5};
    int length = sizeof(arr) / sizeof(int);

    LinkList L = NULL;

    rearInsertCreate(L, arr, length);
    outPut(L);
    std::cout << std::endl;
    // 测试用例如下：

    // 1. 错误情况
    test(L, -1);

    test(L, 0);

    test(L, 6);

    // 2. 边界情况
    test(L, 5);

    test(L, 1);

    // // 3. 正确情况
    test(L, 2);

    return 0;
}

// 输出结果：
// 1 2 3 4 5

// false
// false
// false
// 2 3 4 5
// 2 3 4
// 2 4
