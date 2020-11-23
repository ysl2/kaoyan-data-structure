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

// 下面这三种形式的冒泡排序效果相同

void bubbleSort1(int a[], int length) {
    for (int i = 0; i < length - 1; i++) {
        bool flag = false;
        for (int j = 0; j < length - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a, j, j + 1);
                flag = true;
            }
        }
        if (flag == false)
            break;
    }
}

void bubbleSort2(int a[], int length) {
    int low = 0, high = length - 1;
    while (low < high) {
        bool flag = false;
        for (int j = low; j < high; j++) {
            if (a[j] > a[j + 1]) {
                swap(a, j, j + 1);
                flag = true;
            }
        }
        high--;
        if (flag == false)
            break;
    }
}

void bubbleSort3(int a[], int length) {
    while (length >= 1) {
        bool flag = false;
        for (int j = 0; j < length; j++) {
            if (a[j] > a[j + 1]) {
                swap(a, j, j + 1);
                flag = true;
            }
        }
        length--;
        if (flag == false)
            break;
    }
}

void test(int a[], int length, int index) {
    if (index == 1)
        bubbleSort1(a, length);
    else if (index == 2)
        bubbleSort2(a, length);
    else if (index == 3)
        bubbleSort3(a, length);
    outPut(a, length);
}

int main() {
    ElemType A1[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length1 = sizeof(A1) / sizeof(int);
    ElemType A2[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length2 = sizeof(A2) / sizeof(int);
    ElemType A3[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length3 = sizeof(A3) / sizeof(int);

    test(A1, length1, 1);
    test(A2, length2, 2);
    test(A3, length3, 3);

    return 0;
}

// 输出结果：
// 0 1 2 3 4 5 6 7 8 9
// 0 1 2 3 4 5 6 7 8 9
// 0 1 2 3 4 5 6 7 8 9
