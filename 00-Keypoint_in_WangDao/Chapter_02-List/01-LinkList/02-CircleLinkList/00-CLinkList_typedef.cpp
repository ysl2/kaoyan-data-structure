#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct CLinkNode {  // Circle
    ElemType data;
    struct CLinkNode *next;
} CLinkNode, *CLinkList;

void outPut(CLinkList L) {
    CLinkNode *p = L->next;
    while (p != L) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

CLinkList rearInsertCreateCircleList(ElemType arr[], int length) {
    CLinkList L = new CLinkNode;
    CLinkNode *r = L;
    for (int i = 0; i < length; i++) {
        CLinkNode *s = new CLinkNode;
        s->data = arr[i];
        r->next = s;
        r = s;
    }
    r->next = L;
    return L;
}

bool isEmpty(CLinkList L) {
    return L->next == L;
}

bool isTail(CLinkList L, CLinkNode *p) {
    return p->next == L;
}

void test(int arr[], int length) {
    CLinkList A = rearInsertCreateCircleList(arr, length);

    outPut(A);
}

int main() {
    ElemType arr1[] = {1, 2, 3, 4, 4, 3, 2, 1};
    int length1 = sizeof(arr1) / sizeof(int);

    test(arr1, length1);

    return 0;
}

// 输出结果：
// 1 2 3 4 4 3 2 1
