#include <stdlib.h>  // malloc函数需要用这个库
#define maxSize 100
typedef int ElemType;
typedef struct {
    ElemType *data;  // 注意，我这种方式是对的，山大那种不对
    int length;
} SqList;

int main() {
    int initSize = 5;
    // 两种初始化方式（二选一）：
    // 1
    SqList L1;
    L1.data = (ElemType *)malloc(sizeof(ElemType) * (initSize));  // 如果按照山大那种，数组是静态分配的，将无法再次对其动态分配。按照我这种没问题
    // 2
    SqList L2;
    L2.data = new ElemType[initSize];  // new是C++语法，就相当于C的动态分配
    return 0;
}
