#include <stdio.h>
#define maxSize 10
typedef int ElemType;
typedef struct {
    ElemType data[maxSize];
    int top[2];
    // top1初始是 -1，top2初始是maxSize
} Stack;

int Push(Stack S, int i, ElemType x) {
    if (i < 0 || i > 1) {
        return -1;  // 栈号输入错误
    }
    if (S.top[0] + 1 == S.top[1]) {
        return 0;  // 栈满
    }
    S.top[i] = (i == 0)? S.top[i] + 1 : S.top[i] - 1;
    S.data[S.top[i]] = x;
    return 1;  // 入栈成功
}

int Pop(Stack S, int i, ElemType &e) {
    if (i < 0 || i > 1) {
        return -1;  // 栈号输入错误
    }
    if ((i == 0) && (S.top[i] == -1) || 
        (i == 1) && (S.top[i] == maxSize)) {
        return 0;  // 栈空
    }
    e = S.data[S.top[i]];
    S.top[i] = (i == 0)? S.top[i] - 1 : S.top[i] + 1;
    return 1;  // 出栈成功
}

