#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct {
    ElemType *data;
    int length;
} SqTable;

SqTable getTable(int arr[], int length) {
    SqTable T;
    T.data = arr;
    T.length = length;
    return T;
}

int search(SqTable T, ElemType key, int low, int high) {
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (T.data[mid] == key)
        return T.data[mid];
    if (T.data[mid] < key)
        return search(T, key, mid + 1, high);
    return search(T, key, low, mid - 1);
}

void test(ElemType a[], int length, ElemType key) {
    SqTable T = getTable(a, length);
    cout << search(T, key, 0, (T.length - 1)) << endl;
}

int main() {
    ElemType A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(A) / sizeof(A[0]);
    test(A, length, 1);
    return 0;
}

// 输出结果：
// 1

