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

void directlyInsertSortWithGuard(int a[], int length) {
    for (int i = 2; i < length; i++) {
        a[0] = a[i];
        int j;
        for (j = i - 1; j >= 0 && a[j] > a[0]; j--)
            a[j + 1] = a[j];
        a[j + 1] = a[0];
    }
}

int main() {
    ElemType A[] = {-1, 0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(A) / sizeof(int);
    directlyInsertSortWithGuard(A, length);
    outPut(A, length);
    return 0;
}

// 输出结果：
// 0:  9 0 1 2 3 4 5 6 7 8 9
