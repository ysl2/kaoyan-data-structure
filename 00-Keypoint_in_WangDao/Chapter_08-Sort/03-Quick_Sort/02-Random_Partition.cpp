#include <iostream>
#include <time.h>
using namespace std;

typedef int ElemType;

void swap(ElemType *A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// rand() 会随机生成一个位于 0 ~ RAND_MAX 之间的整数。
// RAND_MAX 是 <stdlib.h> 头文件中的一个宏，它用来指明 rand() 所能返回的随机数的最大值。
// C语言标准并没有规定 RAND_MAX 的具体数值，只是规定它的值至少为 32767。
// 在实际编程中，我们也不需要知道 RAND_MAX 的具体值，把它当做一个很大的数来对待即可。

// 王道书上写的划分算法
int partition(ElemType *A, int low, int high) {
    srand((unsigned)time(NULL));  // 重新播种，使每次生成的随机数都不同
    // rand, srand, time用法参考：http://c.biancheng.net/view/2043.html
    int randIndex = low + rand() % (high - low + 1);
    swap(A, randIndex, low);
    ElemType pivot = A[low];
    int i = low;
    for (int j = low + 1; j <= high; j++) {
        if (A[j] < pivot)
            swap(A[++i], A[j]);
    }
    swap(A, i, low);
    return i;
}

// 我根据王道书的思想，自己按照常规的划分算法改了一下。效果一样
int partition1(int *A, int low, int high) {
    srand((unsigned)time(NULL));
    int randIndex = low + rand() % (high - low + 1);
    swap(A, low, randIndex);
    int pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}
