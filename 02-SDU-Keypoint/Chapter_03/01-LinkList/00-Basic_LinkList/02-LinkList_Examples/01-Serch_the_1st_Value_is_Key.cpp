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

int searchThe1stValueIsKey(LinkList L, ElemType key) {
    //i表示位序（从1开始算），而不是下标（从0开始算）
    int i = 1;
    while (L->next != NULL) {
        // 虽然L是要比较的结点p的前驱，但是每次比较都是针对p的值比的。因此上面i要初始化为1，而不是0
        if (L->next->data == key) {
            return i;
        }
        L = L->next;
        i++;
    }
    return -1;
}

int main() {
    ElemType arr[] = {1, 3, 5, 7, 9};
    int length = sizeof(arr) / sizeof(int);
    LinkList L = NULL;
    rearInsertCreate(L, arr, length);
    outPut(L);
    // 正确用例
    std::cout << searchThe1stValueIsKey(L, 5) << std::endl;
    // 错误用例
    std::cout << searchThe1stValueIsKey(L, 0) << std::endl;
    std::cout << searchThe1stValueIsKey(L, 10) << std::endl;
    return 0;
}

// 输出结果：
// 1 3 5 7 9
// 3
// -1
// -1
