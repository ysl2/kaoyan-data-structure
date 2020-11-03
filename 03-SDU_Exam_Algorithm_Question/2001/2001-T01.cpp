#include <iostream>
using namespace std;

typedef int ElemType;

void outPut(ElemType *A, int length) {
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

void swap(ElemType *A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// 顺序表，拆分，使用新的存储空间
void seprate1(ElemType arr[], int &length, ElemType result1[], int &length1, ElemType result2[], int &length2) {
    int i = 0, j = 0;
    for (int k = 0; k < length; ++k) {
        if (arr[k] >= 0)
            result1[i++] = arr[k];
        else
            result2[j++] = arr[k];
    }
    length1 = i;
    length2 = j;
}

// 顺序表，拆分，不完全依靠新的存储空间，而是利用原先数组的空间
void seprate2(ElemType arr[], int &length, ElemType result1[], int &length1) {
    int offset = 0;
    int i = 0;
    int k;
    for (k = 0; k < length; ++k) {
        if (arr[k] < 0) {
            result1[i++] = arr[k];
            ++offset;
        } else
            arr[k - offset] = arr[k];
    }
    length = k - offset;
    length1 = i;
}

void test(ElemType arr[], int &length, ElemType result1[], int &length1, ElemType result2[], int &length2) {
    seprate1(arr, length, result1, length1, result2, length2);
    outPut(arr, length);
    outPut(result1, length1);
    outPut(result2, length2);

    cout << endl;

    seprate2(arr, length, result1, length1);
    outPut(arr, length);
    outPut(result1, length1);
}

int main() {
    ElemType arr[] = {1, -1, 1, 1, -1, -1, 1, 1, 1, -1, -1, -1};
    int length = sizeof(arr) / sizeof(int);
    int length1 = sizeof(arr) / sizeof(int);
    int length2 = sizeof(arr) / sizeof(int);
    ElemType *result1 = new int[length1];
    ElemType *result2 = new int[length2];
    test(arr, length, result1, length1, result2, length2);
    return 0;
}

// 输出结果：
// 1 -1 1 1 -1 -1 1 1 1 -1 -1 -1
// 1 1 1 1 1 1
// -1 -1 -1 -1 -1 -1

// 1 1 1 1 1 1
// -1 -1 -1 -1 -1 -1
