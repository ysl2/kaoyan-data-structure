#include <iostream>
#include <time.h>
using namespace std;

typedef int ElemType;

void outPut(ElemType *A, int length) {
    static int i = 0;
    cout << i++ << ":  ";
    for (int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

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

void quickSort(int *A, int low, int high) {
    if (low >= high)
        return;
    int pivotPos = partition1(A, low, high);
    quickSort(A, low, pivotPos - 1);
    quickSort(A, pivotPos + 1, high);
}

int main() {
    ElemType A[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(A) / sizeof(int);
    quickSort(A, 0, length - 1);
    outPut(A, length);
    return 0;
}

// 输出结果：
// 0:  0 1 2 3 4 5 6 7 8 9

