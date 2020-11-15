#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct {
    ElemType *data;
    int length;
} SqTable;

void outputTable(SqTable T) {
    for (int i = 0; i < T.length; i++)
        cout << T.data[i] << " ";
    cout << endl;
}

SqTable getTable(int arr[], int length) {
    SqTable T;
    T.data = arr;
    T.length = length;
    return T;
}

void test(ElemType a[], int length, ElemType key) {
    SqTable T = getTable(a, length);
    outputTable(T);
}

int main() {
    ElemType A[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(A) / sizeof(A[0]);
    test(A, length, 1);
    return 0;
}

// 输出结果：

