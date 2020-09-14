#include <stdlib.h>  // malloc函数需要用这个库
#include <iostream>  //C++的标准输入输出流库
#define maxSize 10

typedef int ElemType;
typedef struct {
    ElemType data[maxSize];  // 注意，我这种方式是对的，山大那种不对
    int length;
} SqList;

void initList(SqList &L, int length) {
    for (int i = 0; i < length; i++)
        L.data[i] = i;
    L.length = length;
}

void outPut(SqList L) {
    for (int i = 0; i < L.length; i++)
        std::cout << L.data[i] << " ";
}

void deleteList(SqList &L, int index, ElemType &e) {  // 由e返回被删除的元素。index表示下标，从0开始算
    if (index < 0 || )
}

int main() {
    int length = 5;
    // 创建表和初始化表
    SqList L;
    initList(L, length);

    // 打印顺序表的内容
    outPut(L);
    return 0;
}

// 输出结果：
