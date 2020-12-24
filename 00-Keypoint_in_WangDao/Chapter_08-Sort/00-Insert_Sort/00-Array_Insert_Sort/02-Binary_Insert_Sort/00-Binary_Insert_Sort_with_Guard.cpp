#include <iostream>
using namespace std;

typedef int ElemType;

void outPut(ElemType *A, int length) {
    static int i = 0;
    cout << ++i << ":  ";
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

void binaryInsertSortWithGuard(int *a, int length) {
    for (int i = 2; i < length; ++i) {
        int low = 1, high = i - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (a[mid] <= a[i])
                low = mid + 1;
            else
                high = mid - 1;
        }  // 折半查找完成后，此时high + 1 = low
        a[0] = a[i];
        for (int j = i - 1; j >= low; --j)  // 将[low, i - 1]范围的元素全部右移
            a[j + 1] = a[j];
        a[low] = a[0];  // 将原先的a[i]复制到low所指位置
    }
}

int main() {
    ElemType A[] = {-1, 0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(A) / sizeof(A[0]);
    binaryInsertSortWithGuard(A, length);
    outPut(A, length);
    return 0;
}

// 输出结果：
// 0:  9 0 1 2 3 4 5 6 7 8 9
