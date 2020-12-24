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

int search(SqTable T, ElemType key) {
    int i;
    for (i = 0; i < T.length && T.data[i] != key; ++i)
        ;
    return i == T.length ? -1 : i;
}

void test(ElemType a[], int length, ElemType key) {
    SqTable T = getTable(a, length);
    cout << search(T, key) << endl;
}

int main() {
    ElemType A[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(A) / sizeof(A[0]);
    test(A, length, 1);
    return 0;
}

// 输出结果：
// 5
