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

int *B;  // 必须放在外面，这是全局辅助数组

void merge(int A[], int low, int mid, int high) {
    int i, j, k;
    for (k = low; k <= high; k++)
        B[k] = A[k];
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
        if (B[i] <= B[j])
            A[k] = B[i++];
        else
            A[k] = B[j++];
    }
    while (i <= mid)
        A[k++] = B[i++];
    while (j <= high)
        A[k++] = B[j++];
}

void mergeSort(int A[], int low, int high) {
    if (low >= high)
        return;
    if (!B)  // 如果没有创建辅助空间，就创建。如果已经创建了，就继续下面的代码
        B = (int *)malloc(sizeof(int) * (high - low + 1));
    int mid = (low + high) / 2;
    mergeSort(A, low, mid);
    mergeSort(A, mid + 1, high);
    merge(A, low, mid, high);
}

int main() {
    ElemType A[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(A) / sizeof(int);
    mergeSort(A, 0, length - 1);
    outPut(A, length);
}

// 输出结果：
// 0:  0 1 2 3 4 5 6 7 8 9
