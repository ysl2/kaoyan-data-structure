#include <cstdlib>
#include <iostream>
#define maxSize 100

typedef int ElemType;

typedef struct {
    ElemType *data;  // 这里将来会是一个数组
    int top = -1;
    int length;
} SqStack;

void outPut(SqStack S) {
    while (S.top != -1) {
        std::cout << S.data[S.top--] << " ";
    }
}

void initStack(SqStack &S, int length) {
    S.data = new ElemType[length];
    S.length = length;
}

bool Push(SqStack &S, ElemType x) {
    if (S.top >= S.length)
        return false;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, ElemType &x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}

bool stackEmpty(SqStack S) {
    return S.top == -1;
}

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

bool isSymmetry(LinkList L, int length) {
    SqStack S;
    initStack(S, length / 2);
    LinkNode *p = L->next;
    for (int i = 0; i < length / 2; i++) {
        Push(S, p->data);
        p = p->next;
    }
    if (length % 2 == 1)
        p = p->next;
    while (p != NULL && !stackEmpty(S)) {
        ElemType temp;
        Pop(S, temp);
        if (p->data != temp)
            return false;
        p = p->next;
    }
    return p == NULL;
}

void test(ElemType *arr, int length) {
    LinkList L;
    rearInsertCreate(L, arr, length);
    if (isSymmetry(L, length))
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
}

int main() {
    ElemType arr1[] = {1, 4, 6, 4, 1};
    int length1 = sizeof(arr1) / sizeof(ElemType);
    ElemType arr2[] = {1, 4, 4, 1};
    int length2 = sizeof(arr2) / sizeof(ElemType);
    ElemType arr3[] = {1, 4, 6, 5, 1};
    int length3 = sizeof(arr3) / sizeof(ElemType);
    ElemType arr4[] = {1, 4, 5, 1};
    int length4 = sizeof(arr4) / sizeof(ElemType);

    test(arr1, length1);

    test(arr2, length2);

    test(arr3, length3);

    test(arr4, length4);

    return 0;
}

// 运行结果：
// true
// true
// false
// false
