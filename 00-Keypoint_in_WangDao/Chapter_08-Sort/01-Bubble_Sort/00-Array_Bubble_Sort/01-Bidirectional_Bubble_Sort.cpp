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

void bidBubbleSort(ElemType *A, int length) {
    int low = 0, high = length - 1;
    while (low < high) {
        bool flag = false;
        for (int i = low; i < high; i++) {
            if (A[i] > A[i + 1]) {
                swap(A, i, i + 1);
                flag = true;
            }
        }
        high--;
        for (int i = high; i > low; i--) {
            if (A[i] < A[i - 1]) {
                swap(A, i, i - 1);
                flag = true;
            }
        }
        low++;
        if (flag == false)
            break;
    }
}

int main() {
    ElemType A[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(A) / sizeof(int);
    bidBubbleSort(A, length);
    outPut(A, length);
    return 0;
}

// 输出结果:
// 0 1 2 3 4 5 6 7 8 9
