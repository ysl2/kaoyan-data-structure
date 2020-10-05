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

void bubbleSort(int a[], int length) {
    for (int i = 0; i < length - 1; i++) {
        bool flag = false;
        for (int j = 0; j < length - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a, j, j + 1);
                flag = true;
            }
        }
        if (flag == false)
            return;
    }
}

int main() {
    ElemType A[] = {10, 0, 5, 2, 3, 4, 7, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(A) / sizeof(int);
    bubbleSort(A, length);
    outPut(A, length);
    return 0;
}

// 输出结果：
// 0:  0 1 2 3 3 4 5 5 6 7 7 8 9 10
