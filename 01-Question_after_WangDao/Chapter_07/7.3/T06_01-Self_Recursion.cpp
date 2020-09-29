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

// 这是我自己写的采用递归方式划分两个集合。空间复杂度比王道的高，但是相对容易理解一些
int mid;
int partition(int a[], int low, int high) {
    int _LOW = low, _HIGH = high;
    int pivot = a[low];
    while (low < high) {
        while (low < high && a[high] >= pivot)
            high--;
        a[low] = a[high];
        while (low < high && a[low] <= pivot)
            low++;
        a[high] = a[low];
    }
    a[low] = pivot;

    if (low < mid)
        partition(a, low + 1, _HIGH);
    else if (low > mid)
        partition(a, _LOW, low - 1);
    return low;
}

int setPartition(int a[], int length) {
    mid = length / 2 - 1;  // 向下取整
    int low = 0, high = length - 1;
    partition(a, low, high);

    int s1 = 0, s2 = 0;
    for (int i = 0; i < length / 2; i++)
        s1 += a[i];
    for (int i = length / 2; i < length; i++)
        s2 += a[i];
    return s2 - s1;
}

int main() {
    ElemType A[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(A) / sizeof(int);
    int answer = setPartition(A, length);
    outPut(A, length);
    cout << answer;
    return 0;
}

// 输出结果：
