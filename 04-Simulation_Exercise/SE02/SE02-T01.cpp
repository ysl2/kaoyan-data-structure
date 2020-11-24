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

// 有序单链表，递增有序，允许重复元素

// 确定序列中元素值比正整数x大的元素的个数（相同元素值只计算一次）
// -1表示输入错误
int judgeList(LinkList L, ElemType x) {
    if (L == NULL)
        return -1;
    LinkNode *p = L->next;
    while (p != NULL && p->data <= x)
        p = p->next;
    // 经过上述步骤，p最终停在了data == x的位置上。因此count从0开始
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

// 将单链表中比正整数x小的偶数从单链表删除
bool deleteList(LinkList &L, ElemType x) {
    if (L == NULL)
        return false;
    LinkNode *p = L->next;
    LinkNode *pre = L;
    while (p != NULL) {
        if (p->data < x && p->data % 2 == 0) {
            pre->next = p->next;
            delete p;
            p = pre->next;
        } else {
            p = p->next;
            pre = pre->next;
        }
    }
    return true;
}

void test(ElemType a[], int length, int index, ElemType x) {
    LinkList L = rearInsertCreate(a, length);
    if (index == 0)
        cout << judgeList(L, x) << endl;
    else {
        deleteList(L, x);
        outPut(L);
    }
}

int main() {
    ElemType arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(arr) / sizeof(arr[0]);

    int x0 = 7;
    test(arr, length, 0, x0);

    int x1 = 7;
    test(arr, length, 1, x1);

    return 0;
}

// 输出结果：
// 2
// 1 3 5 7 8 9

