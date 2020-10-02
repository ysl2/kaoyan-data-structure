// 2020-10-02 第二次修订
#include <iostream>
#include <stack>
using namespace std;

#define maxSize 100

#define _LEFT1 '('
#define _LEFT2 '['
#define _LEFT3 '{'
#define _RIGHT1 ')'
#define _RIGHT2 ']'
#define _RIGHT3 '}'

typedef char ElemType;
bool isMatched(ElemType left, ElemType right) {
    if ((left == _LEFT1 && right == _RIGHT1) ||
        (left == _LEFT2 && right == _RIGHT2) ||
        (left == _LEFT3 && right == _RIGHT3))
        return true;
    return false;
}

bool bracketCheck(ElemType a[], int length) {
    stack<ElemType> s;
    for (int i = 0; i < length; i++) {
        if (a[i] == _LEFT1 || a[i] == _LEFT2 || a[i] == _LEFT3) {
            s.push(a[i]);
        } else if (a[i] == _RIGHT1 || a[i] == _RIGHT2 || a[i] == _RIGHT3) {
            if (s.empty())
                return false;
            ElemType topElem = s.top();
            s.pop();
            if (!isMatched(topElem, a[i]))
                return false;
        }
    }
    return s.empty();
}

void test(ElemType *arr, int length) {
    if (bracketCheck(arr, length))
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
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

//-------------------------------------------------------------------------------
bool isMatched(char left, char right) {
    bool flag = false;
    if ((left == '(' && right == ')') ||
        (left == '[' && right == ']') ||
        (left == '{' && right == '}'))
        flag = true;
    return flag;
}

bool bracketCheck(char str[]) {
    SqStack S;
    InitStack(S);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(S, str[i]);
        }
        // 注意下面这一行不同， 因为是在表达式中，除了括号还有别的字符
        if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (StackEmpty(S))
                return false;
            char topElem;
            Pop(S, topElem);
            if (!isMatched(topElem, str[i])) {
                return false;
            }
        }
    }
    return StackEmpty(S);
}
