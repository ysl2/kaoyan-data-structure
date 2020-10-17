#include <iostream>
#define maxSize 100

#define _LEFT1 '('
#define _LEFT2 '['
#define _LEFT3 '{'
#define _RIGHT1 ')'
#define _RIGHT2 ']'
#define _RIGHT3 '}'

typedef char ElemType;
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

bool isMatched(ElemType left, ElemType right) {
    bool flag = false;
    if ((left == _LEFT1 && right == _RIGHT1) ||
        (left == _LEFT2 && right == _RIGHT2) ||
        (left == _LEFT3 && right == _RIGHT3))
        flag = true;
    return flag;
}

bool bracketCheck(ElemType *a, int length) {

}

int main() {
    ElemType arr1[] = {'{', '(', '(', ')', ')', '}', '[', '{', '(', ')', '(', ')', '}', ']'};
    int length1 = sizeof(arr1) / sizeof(ElemType);
    ElemType arr2[] = {'{', '[', '}', ']', '[', '(', '(', ')', ')', ')'};
    int length2 = sizeof(arr2) / sizeof(ElemType);

    test(arr1, length1);

    test(arr2, length2);

    return 0;
}

// 运行结果：
// true
// false


