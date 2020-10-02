// 2020-10-01 第三次修订
#define maxSize 10

typedef int ElemType;
typedef struct {
    ElemType data[maxSize];
    int top1 = -1, top2 = maxSize;
} CommonStack;

// index: 入的是哪个栈（top1还是top2）
bool Push(CommonStack &S, int index, ElemType e) {
    if (S.top1 + 1 == S.top2)
        return false;
    if (index == 1) {
        S.data[++S.top1] = e;
        return true;
    } else if (index == 2) {
        S.data[--S.top2] = e;
        return true;
    }
    return false;
}

bool Pop(CommonStack &S, int index, ElemType &x) {
    if ((index == 1 && S.top1 == -1) || (index == 2 && S.top2 == maxSize))
        return false;
    if (index == 1) {
        x = S.data[S.top1--];
        return true;
    } else if (index == 2) {
        x = S.data[S.top2++];
        return true;
    }
    return false;
}

-------------------------------------------------------------
// 2020-09-10 第二次修订
#define maxSize 10

typedef int ElemType;
typedef struct {
	ElemType data[maxSize];
	int top0 = -1, top1 = maxSize;
} Stack;

bool push(Stack &S, ElemType value, int index) {
	if (S.top0 + 1 == S.top1)
		return false;
	if (index == 0) {
		S.data[++S.top0] = value;
		return true;
	} else if (index == 1) {
		S.data[--S.top1] = value;
		return true;
	}
	return false;
}

bool pop(Stack &S, ElemType &value, int index) {
	if (index != 0 && index != 1)
		return false;
	if ((index == 0 && S.top0 == -1) || (index == 1 && S.top1 == maxSize)) {
		return false;
	}
	value = (index == 0) ? S.data[S.top0--] : S.data[S.top1++];
	return true;
}

-------------------------------------------------------------
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

