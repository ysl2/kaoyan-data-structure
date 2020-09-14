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

bool deleteList(SqList &L, int index, ElemType &e) {     // 由e返回被删除的元素。index表示下标，从0开始算
    if (index < 0 || index > L.length || L.length <= 0)  // 删除考虑下溢出，插入考虑上溢出。无论插入还是删除，都需要考虑index的上界和下界的合法范围
        return false;
    e = L.data[index];
    for (int j = index; j < L.length - 1; j++)
        L.data[j] = L.data[j + 1];
    L.length--;
    return true;
}

int main() {
    int length = 5;
    // 创建表和初始化表
    SqList L;
    initList(L, length);
    // 删除数组下标为3的元素，并由e返回这个元素
    int e;
    deleteList(L, 3, e);
    // 打印顺序表的内容
    outPut(L);
    // 打印被删掉的元素
    std::cout << std::endl
              << e << std::endl;
    return 0;
}

// 输出结果：
// 0 1 2 4
// 3
