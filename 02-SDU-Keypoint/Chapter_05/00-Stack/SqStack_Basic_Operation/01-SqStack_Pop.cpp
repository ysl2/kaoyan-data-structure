#define maxSize 10
typedef int ElemType;
typedef struct {
    ElemType *data;  // 这里将来会是一个数组
    int top = -1;
    int length;
} SqStack;

bool Pop(SqStack &S, ElemType &x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}
