// 2020-10-19 第三次修订：通过C++库中提供的栈来简化代码
#include <stdlib.h>
#include <stack>
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

// 2020-09-10 第二次修订：通过C++库中提供的栈来简化代码
bool isSym(LinkList L, int n) {
	stack<ElemType> s;
	LinkNode *p = L->next;
	for (int i = 0; i < n / 2; i++) {
		s.push(p->data);
		p = p->next;
	}
	if (n % 2 == 1)
		p = p->next;
	while (p != NULL && s.top() == p->data) {
		s.pop();
		p = p->next;
	}
	return s.empty();
}

void test(int a[], int length) {
    LinkList L = rearInsertCreate(a, length);

    if (isSym(L, length) == true)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

int main() {
    ElemType arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length1 = sizeof(arr1) / sizeof(int);
    ElemType arr2[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    int length2 = sizeof(arr2) / sizeof(int);
    ElemType arr3[] = {1, 2, 3, 4, 4, 3, 2, 1};
    int length3 = sizeof(arr3) / sizeof(int);

    test(arr1, length1);
    test(arr2, length2);
    test(arr3, length3);

    return 0;
}

// 输出结果：
// false
// true
// true


// -------------------------------------------------
int do(LinkList L, int n) {
    char s[n / 2];
    LinkNode *p = L->next;
	int i;
    for (i = 0, i < n / 2; i++) {
        s[i] = p->data;
        p = p->next;
    }
    i--;
    if (n % 2 == 1) {
        p = p->next;
    }
    while (p != NULL && s[i] == p->data) {
        i--;
        p = p->next;
    }
    return (i == -1)? 1 : 0;
}

