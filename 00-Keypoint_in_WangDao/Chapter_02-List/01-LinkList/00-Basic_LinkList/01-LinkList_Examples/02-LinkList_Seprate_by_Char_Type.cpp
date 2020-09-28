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

// 题目要求根据大写、小写和数字分类，这样我还得重新定义char类型的链表，太麻烦了
// 所以我按照大写、小写、数字的ASCII码范围来分类，这样都能保证是int型
// 数字：48 ~ 57，放在A里
// 大写：65 ~ 90，放在B里
// 小写：97 ~ 122，放在C里
void SeprateByCharType(LinkList &A, LinkList &B, LinkList &C) {
    LinkNode *pre = A;
    LinkNode *p = A->next;
    B = new LinkNode;
    LinkNode *q = B;
    C = new LinkNode;
    LinkNode *r = C;
    while (p != NULL) {
        // 放在A里
        if (p->data >= 48 && p->data <= 57) {
            p = p->next;
            pre = pre->next;
            continue; //终止当前这次循环，直接进入下一次循环
        }
        // 放在B里
        if (p->data >= 65 && p->data <= 90) {
            rearInsert(q, p->data);
            // 在A中删除p所指的位置，然后把p定位到下一个位置
            pre->next = p->next;
            delete p;
            p = pre->next;
            continue;
        }
        // 放在C里
        if (p->data >= 97 && p->data <= 122) {
            rearInsert(r, p->data);
            pre->next = p->next;
            delete p;
            p = pre->next;
            // 这里就不用加continue了，因为下面已经没有语句了，肯定会执行下一次循环
        }
    }
    q->next = NULL;
    r->next = NULL;
}

int main() {
    ElemType arr[] = {49, 66, 98, 50, 67, 99, 51, 68, 100, 52, 69, 101};
    int length = sizeof(arr) / sizeof(int);

    LinkList L1 = NULL;
    LinkList L2 = NULL;
    LinkList L3 = NULL;

    rearInsertCreate(L1, arr, length);
    outPut(L1);

    SeprateByCharType(L1, L2, L3);
    
    outPut(L1);
    outPut(L2);
    outPut(L3);
    return 0;
}

// 输出结果：
// 49 66 98 50 67 99 51 68 100 52 69 101
// 49 50 51 52
// 66 67 68 69
// 98 99 100 101
