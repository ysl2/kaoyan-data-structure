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

bool searchList(SqList L, ElemType target, int &result) {  //寻找第一次出现值为target的数组下标，下标由result返回
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == target) {
            result = i;
            return true;
        }
    }
    return false;
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
