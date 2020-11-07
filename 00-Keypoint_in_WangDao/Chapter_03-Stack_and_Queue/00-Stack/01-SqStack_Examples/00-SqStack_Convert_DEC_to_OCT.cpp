#include <iostream>
#define maxSize 100

typedef int ElemType;
typedef struct {
    ElemType *data;  // 这里将来会是一个数组
    int top = -1;
    int length;
} SqStack;

void outPut(SqStack S) {
    while (S.top != -1)
        std::cout << S.data[S.top--] << " ";
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

int getNumberLength(int n) {
    int length = 1;
    while (n / 10 > 0) {
        n /= 10;
        length++;
    }
    return length;
}

// 把十进制数转换成d进制数（d为2或8其中之一）
void conversion(int n, int d) {
    int length = getNumberLength(n);
    SqStack S;
    initStack(S, length);
    while (n > 0) {
        Push(S, (n % d));
        n /= d;
    }
    outPut(S);
}

int main() {
    conversion(1348, 8);
}

// 输出结果：
// 2 5 0 4
