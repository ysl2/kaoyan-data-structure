#include <stdbool.h>
const int maxSize = 100;

// 把所有基本函数全都分离出来，反而变得不简洁。因此不推荐用这个

typedef struct {
    int no;
    double value;
} Cell;

typedef struct {
    Cell data[maxSize];
    int top = -1;
} Stack;

void setNo(Stack S, int no) {
    S.data[S.top].no = no;
}

int getNo(Stack S) {
    return S.data[S.top].no;
}

void setValue(Stack S, double value) {
    S.data[S.top].value = value;
}

// double getValue(Stack S) {
//     return S.data[S.top].value;
// }

bool IsEmpty(Stack S) {
    return S.top == -1;
}

void movePointer(Stack S, int index) {
    S.top += index;
}

void PushNo(Stack S, int no) {
    movePointer(1);
    setNo(S, no);
}

void PushValue_Reverse(Stack S, double value) {
    setValue(S, value);
    movePointer(-1);
}

double p(int n, double x) {
    Stack S;
    double fv1 = 1, fv2 = 2 * x;
    for (int i = n; i >= 2; i--) {
        PushNo(S, i);
    }
    while (!IsEmpty(S)) {
        int value = 2 * x * fv2 - 2 * (getNo(S) - 1) * fv1;
        fv1 = fv2;
        fv2 = value;
        PushValue_Reverse(S, value);
    }
    return (n == 0)? fv1 : fv2;
}

