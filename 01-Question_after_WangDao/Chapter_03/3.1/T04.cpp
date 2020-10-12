// 2020-09-10 第二次修订：通过C++库中提供的栈来简化代码
#include <stdlib.h>
#include <stack>
using namespace std;

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

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

