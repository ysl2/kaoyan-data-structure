#include <string.h>
#include <cstdlib>
#include <iostream>
#define INFINITY 9999
using namespace std;

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
    for (int i = 0; i < length; i++)
        rearInsert(p, arr[i]);
    p->next = NULL;
}

// https://blog.csdn.net/baidu_30000217/article/details/77823084
// 针对带头结点的单链表进行选择排序
void selectSort(LinkList &L) {
    if ((L->next == NULL) || (L->next->next == NULL))
        return;

    LinkNode *head, *prep1, *p1, *prep2, *p2, *premin, *min, *temp;
    head = L;
    for (prep1 = head, p1 = prep1->next; p1->next != NULL; prep1 = prep1->next, p1 = prep1->next) {
        //保存最小节点
        premin = prep1;
        min = p1;
        for (prep2 = p1, p2 = prep2->next; p2 != NULL; prep2 = prep2->next, p2 = prep2->next) {
            if (min->data > p2->data) {
                premin = prep2;
                min = p2;
            }
        }

        if (p1 != min) {
            //一定要注意这个情况
            if (p1->next == min) {
                temp = min->next;
                prep1->next = min;
                min->next = p1;
                p1->next = temp;
            } else {
                temp = min->next;
                prep1->next = min;
                min->next = p1->next;
                premin->next = p1;
                p1->next = temp;
            }
        }
    }
}
void test(LinkList &L) {
    selectSort(L);
}

int main() {
    ElemType arr[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(arr) / sizeof(int);
    LinkList L = NULL;
    rearInsertCreate(L, arr, length);
    outPut(L);
    std::cout << std::endl;

    test(L);
    outPut(L);

    return 0;
}

// 输出结果：
// 0 2 4 6 8 1 3 5 7 9
//
// 0 1 2 3 4 5 6 7 8 9
