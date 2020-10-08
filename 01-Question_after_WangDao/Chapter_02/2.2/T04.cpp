#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
} SqList;

SqList initList(int arr[], int length) {
    SqList L;
    L.length = length;
    L.data = (ElemType *)malloc(sizeof(ElemType) * L.length);
    for (int i = 0; i < length; i++)
        L.data[i] = arr[i];
    return L;
}

void outPutList(SqList L) {
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
}

bool deleteList(SqList &L, ElemType s, ElemType t) {
    if (L.length == 0 || s >= t)
        return false;
    int i = 0;
    for (; i < L.length && L.data[i] < s; i++)
        ;
    if (i == L.length)
        return false;
    int j = i;
    for (; j < L.length && L.data[j] <= t; j++)
        ;
    for (; j < L.length; i++, j++)
        L.data[i] = L.data[j];
    L.length = i;
    return true;
}

void test(int arr1[], int length1) {
    SqList L = initList(arr1, length1);
    deleteList(L, 3, 5);
    outPutList(L);
}

int main() {
    ElemType A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length1 = sizeof(A) / sizeof(int);

    test(A, length1);
    return 0;
}

// 输出结果：
// 1 2 6 7 8 9

