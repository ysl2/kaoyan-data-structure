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

void insertSort(int a[], int m, int n) {
    for (int i = m + 1; i < m + n + 1; i++) {
        a[0] = a[i];
        int j;
        for (j = i - 1; a[j] > a[0]; j--)
            a[j + 1] = a[j];
        a[j + 1] = a[0];
    }
}

int main() {
    ElemType A[] = {-1, 1, 3, 5, 7, 9, 0, 2, 4, 6, 8};
    int length = sizeof(A) / sizeof(int);
    insertSort(A, 5, 5);
    outPut(A, length);
    return 0;
}

// 输出结果：
// 0:  8 0 1 2 3 4 5 6 7 8 9
