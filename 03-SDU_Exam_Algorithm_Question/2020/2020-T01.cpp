#include <iostream>
using namespace std;

typedef int ElemType;

void outPut(ElemType *A, int length) {
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

// 基于冒泡排序
// 时间复杂度：O(n^2)
void move(int a[], int length) {
    for (int i = 0; i < length - 1; i++) {
        bool flag = false;
        for (int j = 0; j < length - 1 - i; j++) {
            if (a[j] == 0) {
                swap(a, j, j + 1);
                flag = true;
            }
        }
        if (flag == false)
            return;
    }
}

int main() {
    ElemType A[] = {0, 1, 0, 2, 0, 3, 0, 0, 0, 4, 0, 5, 0, 6, 0, 7, 0, 8, 0, 9};
    int length = sizeof(A) / sizeof(int);
    move(A, length);
    outPut(A, length);
    return 0;
}

// 输出结果：
// 1 2 3 4 5 6 7 8 9 0 0 0 0 0 0 0 0 0 0 0
