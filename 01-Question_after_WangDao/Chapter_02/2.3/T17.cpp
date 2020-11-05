// 2020-10-10
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct DCLinkNode {  // Double Circle
    ElemType data;
    struct DCLinkNode *pre, *next;
} DCLinkNode, *DCLinkList;

void outPut(DCLinkList L) {
    DCLinkNode *p = L->next;
    while (p != L) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void reverseOutPut(DCLinkList L) {
    DCLinkNode *p = L->pre;
    while (p != L) {
        cout << p->data << " ";
        p = p->pre;
    }
    cout << endl;
}

DCLinkList rearInsertCreateDoubleCircleList(ElemType arr[], int length) {
    DCLinkList L = new DCLinkNode;
    DCLinkNode *r = L;
    for (int i = 0; i < length; i++) {
        DCLinkNode *s = new DCLinkNode;
        s->data = arr[i];
        r->next = s;
        s->pre = r;
        r = s;
    }
    r->next = L;
    L->pre = r;
    return L;
}

// 我自己写的
bool isSym1(DCLinkList L) {
    if (L->next == L || L->next->next == L)
        return false;
    DCLinkList p = L->next;
    DCLinkList q = L->pre;
    while ((p != q && p->next != q) && p->data == q->data) {
        p = p->next;
        q = q->pre;
    }
    return p == q || (p->next == q && p->data == q->data);
}

// 这是王道上写的代码，我原封没动直接搬过来了，根据测试用例显然可以发现，这个代码是有问题的
bool isSym2(DCLinkList L) {
    DCLinkNode *p = L->next, *q = L->pre;
    while (p != q && p->next != q) {
        if (p->data == q->data) {
            p = p->next;
            q = q->pre;
        } else
            return false;
    }
    return true;
}

void test(int arr[], int length) {
    DCLinkList A = rearInsertCreateDoubleCircleList(arr, length);

    if (isSym1(A))
        cout << "true" << "\t";
    else
        cout << "false" << "\t";

    if (isSym2(A))
        cout << "true" ;
    else
        cout << "false";
    cout << endl;
}

int main() {
    ElemType arr1[] = {1, 2, 3, 4, 4, 3, 2, 1};
    int length1 = sizeof(arr1) / sizeof(int);
    ElemType arr2[] = {1, 2, 3, 4, 5, 3, 2, 1};
    int length2 = sizeof(arr2) / sizeof(int);
    ElemType arr3[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    int length3 = sizeof(arr3) / sizeof(int);
    ElemType arr4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length4 = sizeof(arr4) / sizeof(int);
    ElemType arr5[] = {1};
    int length5 = sizeof(arr5) / sizeof(int);

    test(arr1, length1);
    test(arr2, length2);
    test(arr3, length3);
    test(arr4, length4);
    test(arr5, length5);

    return 0;
}

// 输出结果：（注：右边的是王道书上的，是有问题的。左边是我自己写的）
// true    true
// false   true
// true    true
// false   false
// false   true


//----------------------------------------------------------------------------------------
// 2020-09-06 第二次修订
typedef int ElemType;
typedef struct DCLinkNode {
    ElemType data;
    struct DCLinkNode *prior, *next;
} DCLinkNode, *DCLinkList;

DCLinkList L;

bool isSym(DCLinkList &L) {  // Double Circle LinkList
    DCLinkNode *p = L->next;
    DCLinkNode *q = L->prior;
    // L如果是奇数个结点，最终会判断p == q
    // L如果是偶数个结点，最终会判断p->next == q
    // 但上述两个情况不会同时发生，因此写在一起不会发生冲突
    for ( ; p->data == q->data && (p->next != q && p != q) ; p = p->next, q = q->prior);
    // 和上面一样，只要奇数或者偶数满足其中一种情况即可
    // 无论哪种情况，都必须保证整个链表遍历完整，而不是因为有不相等的元素导致退出循环
    // 但是一旦有不相等的元素，必然会导致链表遍历不完整，也就是两个指针没碰头
    // 除了一种情况，就是链表偶数的时候，
    // 遍历到最后的位置时，两个指针刚好碰头，但是不能保证这两个data一定相等
    // 所以需要在最终的判断里体现出来这一个信息：
    return (p->next == q && p->data == q->data) || p == q;
}
-------------------------------------------------------------------------
int symmetry(DCLinkList L) {
    DCLinkNode *p = L->next, *q = L->prior;
    while (p != q && p->next != q) {  // 分别对应奇数和偶数个结点
        if (p->data == q->data) {
            p = p->next;
            q = q->prior;
        } else {
            return 0;
        }
    }
    return 1;
}

