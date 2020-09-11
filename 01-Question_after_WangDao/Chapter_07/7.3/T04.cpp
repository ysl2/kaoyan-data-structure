#include <stdlib.h>
#include <time.h>
#include <iostream>
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

int partition(ElemType *A, int low, int high) {
    srand((unsigned)time(NULL));  // 重新播种，使每次生成的随机数都不同
    // rand, srand, time用法参考：http://c.biancheng.net/view/2043.html
    int randIndex = low + rand() % (high - low + 1);
    swap(A, randIndex, low);
    outPut(A, high - low + 1);  // 测试语句
    ElemType pivot = A[low];
    int i = low;
    for (int j = low + 1; j <= high; j++) {
        if (A[j] < pivot) {
            swap(A[++i], A[j]);
            outPut(A, high - low + 1);  // 测试语句
        }
    }
    swap(A, i, low);
    outPut(A, high - low + 1);  // 测试语句
    return i;
}

int main() {
    ElemType A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(A) / sizeof(int);
    outPut(A, length);  // 输出原始序列（第0趟）
    partition(A, 0, length - 1);
    return 0;
}

// 输出结果：
// 0:  1 2 3 4 5 6 7 8 9
// 1:  4 2 3 1 5 6 7 8 9
// 2:  4 2 3 1 5 6 7 8 9
// 3:  4 2 3 1 5 6 7 8 9
// 4:  4 2 3 1 5 6 7 8 9
// 5:  1 2 3 4 5 6 7 8 9
