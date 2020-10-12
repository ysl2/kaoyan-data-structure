// 2020-09-28
#include <stdlib.h>  // malloc函数需要用这个库
#include <iostream>  //C++的标准输入输出流库
#define maxSize 10

typedef int ElemType;
typedef struct {
    ElemType data[maxSize];
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

int search(SqList L, int value, int low, int high) {
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (L.data[mid] == value)
        return L.data[mid];
    if (L.data[mid] < value)
        return search(L, value, mid + 1, high);
    return search(L, value, low, mid - 1);
}

bool searchList(SqList L, int value, int &result) {
    result = search(L, value, 0, L.length - 1);
    return result != -1;
}

int main() {
    int length = 5;
    // 创建表和初始化表
    SqList L;
    initList(L, length);
    //查找值为3的下标
    int result;
    searchList(L, 3, result);
    // 打印查找结果
    std::cout << result << std::endl;
    return 0;
}

// 输出结果：
// 3


