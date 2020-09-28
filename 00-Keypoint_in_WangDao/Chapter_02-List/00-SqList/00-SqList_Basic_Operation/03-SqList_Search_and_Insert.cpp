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
    std::cout << std::endl;
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
// 在顺序表中找到第一个值为x的元素，然后在该元素之前插入一个值为y的元素，如果找不到值为x的元素，则新元素为顺序表的最后一个元素
// 插入成功返回true，否则返回false
bool test(SqList &L, ElemType x, ElemType y) {
    // 由于在insert函数中已经有了对数组上溢的判断，因此这里的上溢判断可以忽略
    // if (L.length >= maxSize)
    //     return false;
    int index;                     //保存查找的下标结果
    if (!searchList(L, x, index))  //如果没找到，在最后面插入
        insertList(L, L.length, y);
    else
        insertList(L, index, y);  // 如果找到了，在这个下标的前一个位置插入
    return true;
}

int main() {
    int length = 5;
    // 创建表和初始化表
    SqList L;
    initList(L, length);  // 表的初始值为：0 1 2 3 4
    test(L, 5, 7);        // 在表中找值为5的元素，找不到，然后在末尾插入7
    // 打印顺序表的内容
    outPut(L);
    // 在表中找值为3的元素，找到，然后在它的前一个位置插入9
    test(L, 3, 9);
    // 打印顺序表的内容
    outPut(L);
    // 使劲往里填，直到填满为止，看看程序是否报错。如果报错，说明代码写的有问题。如果什么都没发生，说明正常
    test(L, 3, 9);
    test(L, 3, 9);
    test(L, 3, 9);
    test(L, 3, 9);
    test(L, 3, 9);
    test(L, 3, 9);
    test(L, 3, 9);
    test(L, 3, 9);
    test(L, 3, 9);
    // 打印顺序表的内容
    outPut(L);
    return 0;
}

// 输出结果：
// 0 1 2 3 4 7
// 0 1 2 9 3 4 7
// 0 1 2 9 9 9 9 3 4 7
