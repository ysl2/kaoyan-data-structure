#define maxSize 10
typedef int ElemType;
typedef struct {
    ElemType *data;  // 这里将来会是一个数组
    int top = -1;
    int length;
} SqStack;

bool Push(SqStack &S, ElemType x) {
    if (S.top >= S.length)
        return false;
    S.data[++S.top] = x;
    return true;
}
