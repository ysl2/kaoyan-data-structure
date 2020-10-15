#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
} SqList;

void outPutList(SqList L) {
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
}

SqList initList(int arr[], int length) {
    SqList L;
    L.length = length;
    L.data = (ElemType *)malloc(sizeof(ElemType) * L.length);
    for (int i = 0; i < length; i++)
        L.data[i] = arr[i];
    return L;
}

// 注意：在这种情况下，无法达到最佳时间复杂度，但是这个方法很简单
double getMid(SqList A, SqList B) {
    SqList C;
    C.length = A.length + B.length;
    C.data = new int[C.length];
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length) {
        if (A.data[i] <= B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }
    while (i < A.length)
        C.data[k++] = A.data[i++];
    while (j < B.length)
        C.data[k++] = B.data[j++];
    for (k = 0; k < (C.length - 1) / 2; k++)  // 注意取中点时候的临界
        ;
    if (C.length % 2 == 1)
        return C.data[k];
    else
        return (C.data[k] + C.data[k + 1]) / 2.0;
}

void test(int arr1[], int length1, int arr2[], int length2) {
    SqList A = initList(arr1, length1);
    SqList B = initList(arr2, length2);
    cout << getMid(A, B) << endl;
}

int main() {
    ElemType A[] = {1, 3, 5, 7, 9};
    ElemType B[] = {2, 4, 6, 8, 10};
    ElemType C[] = {2, 4, 6, 8};

    int length1 = sizeof(A) / sizeof(int);
    int length2 = sizeof(B) / sizeof(int);
    int length3 = sizeof(C) / sizeof(int);

    test(A, length1, B, length2);
    test(A, length1, C, length3);
    return 0;
}

// 输出结果：
// 5.5
// 5

