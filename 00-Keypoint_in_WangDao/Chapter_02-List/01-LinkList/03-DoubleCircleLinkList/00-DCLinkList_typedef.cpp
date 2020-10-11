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

void test(int arr[], int length) {
    DCLinkList A = rearInsertCreateDoubleCircleList(arr, length);
    outPut(A);
    reverseOutPut(A);
}

int main() {
    ElemType arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length1 = sizeof(arr1) / sizeof(int);

    test(arr1, length1);

    return 0;
}

// 输出结果：
// 1 2 3 4 5 6 7 8 9
// 9 8 7 6 5 4 3 2 1
