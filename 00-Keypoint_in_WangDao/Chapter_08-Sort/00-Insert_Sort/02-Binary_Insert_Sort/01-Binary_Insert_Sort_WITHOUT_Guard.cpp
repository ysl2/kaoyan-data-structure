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

void binaryInsertSortWITHOUTGuard(int *a, int length) {
    for (int i = 1; i < length; i++) {
        int low = 0, high = i - 1;  // 注意这里low必须等于0
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (a[mid] <= a[i])  // 这里等号加或者不加，都一样。不加的话，实际上是相当于是else里有个等于号
                low = mid + 1;
            else
                high = mid - 1;
        }  // 折半查找完成后，此时high + 1 = low
        int temp = a[i];
        for (int j = i - 1; j >= low; j--)  // 将[low, i - 1]范围的元素全部右移
            a[j + 1] = a[j];
        a[low] = temp;  // 将原先的a[i]复制到low所指位置
    }
}

int main() {
    ElemType A[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(A) / sizeof(int);
    binaryInsertSortWITHOUTGuard(A, length);
    outPut(A, length);
    return 0;
}

// 输出结果：
// 0:  0 1 2 3 4 5 6 7 8 9
