#include <iostream>
using namespace std;

typedef int ElemType;

void outPut(ElemType *A, int length) {
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

void swap(ElemType *A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// 参考堆排序

// m叉树，结点i的第k个孩子：(i - 1) * m + k + 1
void heapify(ElemType arr[], int i, int n) {
    // 从第i个结点开始向下做heapify
    int first = (i - 1) * 3 + 1 + 1;
    int second = (i - 1) * 3 + 2 + 1;
    int third = (i - 1) * 3 + 3 + 1;

    ElemType maxValue = arr[i];
    int maxIndex = i;
    if (first <= n && arr[first] > maxValue) {
        maxValue = arr[first];
        maxIndex = first;
    }
    if (second <= n && arr[second] > maxValue) {
        maxValue = arr[second];
        maxIndex = second;
    }
    if (third <= n && arr[third] > maxValue) {
        maxValue = arr[third];
        maxIndex = third;
    }
    if (maxIndex != i) {
        swap(arr, maxIndex, i);
        heapify(arr, maxIndex, n);
    }
}

void buildHeap(ElemType arr[], int length) {
    int n = length - 1;
    // 对于完全m叉树，如果结点总数是n的话，最后一个分支结点是； floor((n - 2) / m) + 1
    for (int i = ((n - 2) / 3 + 1); i >= 1; i--)
        heapify(arr, i, n);
}

void test(ElemType arr[], int length) {
    buildHeap(arr, length);
    outPut(arr, length);
}

int main() {
    ElemType A[] = {-1, 0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(A) / sizeof(A[0]);
    test(A, length);
    return 0;
}

// 输出结果：
// -1 9 8 7 6 2 1 3 5 0 4
