#include <iostream>
#define maxSize 20
using namespace std;

// 非递归
double caculate1(int n, double x) {
    // 栈结构体
    struct Cell {
        int number;
        double value;
    } Stack[maxSize];
    int top = -1;

    // 表达式初值
    double Pn0 = 1;  // n = 0时的初始值
    double Pn1 = 2 * x;  // n = 1时的初始值

    for (int i = n; i >= 2; i--)
        Stack[++top].number = i;

    while (top >= 0) {
        Stack[top].value = 2 * x * Pn1 - 2 * (Stack[top].number - 1) * Pn0;
        Pn0 = Pn1;
        Pn1 = Stack[top].value;
        top--;
    }
    return n == 0 ? Pn0 : Pn1;
}

// 递归
double caculate2(int n, double x) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 2 * x;
    return (2 * x * caculate2(n - 1, x) - 2 * (n - 1) * caculate2(n - 2, x));
}

int main() {
    double x = 5;
    int n = 4;
    cout << (caculate1(n, x) == caculate2(n, x)) << endl;  // 判断一下两种方案的结果是否一致
}

// 输出结果：
// 1
