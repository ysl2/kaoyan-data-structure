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

bool insertList(SqList &L, int index, ElemType x) {            // index表示数组下标（下标从0开始算），而不是位序（位序从1开始算）
    if (index < 0 || index > L.length || L.length >= maxSize)  // 删除考虑下溢出，插入考虑上溢出。无论插入还是删除，都需要考虑index的上界和下界的合法范围
        return false;
    int j;
    for (j = L.length; j > index; j--)
        L.data[j] = L.data[j - 1];
    L.data[j] = x;
    L.length++;
    return true;
}

int main() {
    int length = 5;
    // 创建表和初始化表
    SqList L;
    initList(L, length);
    // 把数字'9'插入到数组下标为3的位置
    insertList(L, 3, 9);
    // 打印顺序表的内容
    outPut(L);
    return 0;
}

// 输出结果：
// 0 1 2 9 3 4
