#include <string.h>
#include <iostream>
#define INFINITY 99999
typedef int ElemType;

void outPut(ElemType *A, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

void swap(ElemType *A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// 计数排序，适合量大但范围小的数据
// https://www.bilibili.com/video/BV1Wb41157ed

// 我自己写的计数排序 2020-09-30
// length : 待排序的数组长度
// range : 所有待排序数字的取值范围
void countSort(int a[], int length) {
    int max = -INFINITY, min = INFINITY;
    for (int i = 0; i < length; i++) {
        if (a[i] <= min)
            min = a[i];
        if (a[i] >= max)
            max = a[i];
    }
    int range = max - min + 1;

    int *count = (int *)malloc(sizeof(int) * range);
    memset(count, 0, sizeof(int) * range);
    for (int i = 0; i < length; i++)
        count[a[i] - min]++;

    int j = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            a[j++] = i + min;
            count[i]--;
        }
    }
    free(count);
}

int main() {
    ElemType A[] = {97, 91, 93, 95, 97, 99, 94, 92, 94, 96, 98};
    int length = sizeof(A) / sizeof(int);
    countSort(A, length);
    outPut(A, length);
    return 0;
}

// 输出结果：
// 91 92 93 94 94 95 96 97 97 98 99
