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
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] >= s && L.data[i] <= t)
            k++;
        else
            L.data[i - k] = L.data[i];
    }
    L.length -= k;
    return true;
}

void test(int arr1[], int length1) {
    SqList L = initList(arr1, length1);
    deleteList(L, 3, 5);
    outPutList(L);
}

int main() {
    ElemType A[] = {4, 5, 6, 1, 2, 3, 7, 8, 9};
    int length1 = sizeof(A) / sizeof(int);

    test(A, length1);
    return 0;
}

// 输出结果：
// 6 1 2 7 8 9


