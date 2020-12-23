#include <iostream>
using namespace std;

typedef char ElemType;
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

bool patternInvert(LinkList &L1, LinkList L2) {
    if (L1 == NULL || L2 == NULL || L1->next == NULL || L2->next == NULL)
        return false;
    LinkNode *pre = L1;  // p是每趟匹配时L1中的起始结点前驱的指针
    LinkNode *p = L1->next;  // q是L1的工作指针
    LinkNode *q = L2->next;  // s是L2中的工作指针
    while (pre != NULL && q != NULL) {
        if (p->data == q->data) {  // 对应字母相等，指针后移
            p = p->next;
            q = q->next;
        } else {  // 失败时，L1的起始结点后移，L2从首结点开始
            pre = pre->next;
            p = pre->next;
            q = L2->next;
        }
    }
    if (q != NULL)  // 匹配失败
        return false;
    // 匹配成功，这时p为L1中与L2中首字母结点相同数据域结点的前驱，q为L1中与L2最后一个结点相同数据域结点的后继
    LinkNode *r = pre->next;  // r为L1的工作指针，初始指向匹配的首字母结点
    pre->next = p;
    while (r != p) {        // 逐结点倒置
        q = r->next;        // 暂存r的后继
        r->next = pre->next;  // 将r所指结点倒置
        pre->next = r;
        r = q;  // 恢复r为当前结点
    }
    return true;
}

void test(ElemType arr1[], int length1, ElemType arr2[], int length2) {
    LinkList L1 = rearInsertCreate(arr1, length1);
    LinkList L2 = rearInsertCreate(arr2, length2);

    outPut(L1);
    outPut(L2);

    if (patternInvert(L1, L2)) {
        cout << endl;
        outPut(L1);
        outPut(L2);
    } else
        cout << "false" << endl;
}

int main() {
    ElemType arr1[] = {'a', 'c', 'a', 'b', 'd', 'a', 'd'};
    int length1 = sizeof(arr1) / sizeof(arr1[0]);

    ElemType arr2[] = {'a', 'b', 'd'};
    int length2 = sizeof(arr2) / sizeof(arr2[0]);

    test(arr1, length1, arr2, length2);

    return 0;
}

// 输出结果：
// a c a b d a d
// a b d

// a c d b a a d
// a b d
