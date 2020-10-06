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

// 注：408原题中说，
// 对所有尚未确定最终位置的所有元素进行一遍处理称为“一趟”排序，
// 因此一次“划分” != 一趟排序
// 一次划分可以确定一个元素的最终位置，
// 而一趟排序也许可以确定多个元素的最终位置。
int partition(int *A, int low, int high) {
    int pivot = A[low];  // 假设每次都以第一个元素作为枢轴值，进行一趟划分：
    while (low < high) {
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];  // 停下来做交换
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];  // 停下来做交换
    }
    A[low] = pivot;  // pivot的最终落点
    return low;
}

// 递归快排
void quickSort(int *A, int low, int high) {
    if (low >= high)
        return;
    int pivotPos = partition(A, low, high);
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
