// 2020-10-12
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


//------------------------------------------------------------------------------
#define maxSize 10

typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
} SqTable;

// 代码中 left + (right - left) / 2 和 (left + right) / 2 的结果相同，
// 但是有效防止了 left 和 right 太大直接相加导致溢出
int binarySearch(SqTable T, ElemType key, int left, int right) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (T.data[mid] == key) return mid;
    if (T.data[mid] < key) return binarySearch(T, key, mid + 1, right);
    return binarySearch(T, key, left, mid - 1);
}

// #include <stdio.h>

// int binarySearch(int *a, int key, int left, int right) {
//     if (left > right) return -1;
//     int mid = left + (right - left) / 2;
//     if (a[mid] == key) return mid;
//     if (a[mid] < key) return binarySearch(a, key, mid + 1, right);
//     return binarySearch(a, key, left, mid - 1);
// }

// void test() {
//     int n = 10;
//     int target = 14;
//     int a[n];
//     for (int i = 0; i < n; i++) {
//         a[i] = i + 10;
//     }
//     printf("%d", binarySearch(a, target, 0, n - 1));
// }

// int main() {
//     test();
//     return 0;
// }

