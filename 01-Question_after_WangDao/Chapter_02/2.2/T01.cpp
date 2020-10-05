#include <iostream>
#include <string.h>
using namespace std;

#define INFINITY 9999

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

bool deleteList(SqList &L, ElemType &e) {
    if (L.length == 0)
        return false;
    ElemType minValue = INFINITY;
    int minIndex = -1;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] < minValue) {
            minValue = L.data[i];
            minIndex = i;
        }
    }
    e = minValue;
    L.data[minIndex] = L.data[L.length - 1];
    L.length--;
    return true;
}

SqList initList(int arr[], int length) {
    SqList L;
    L.length = length;
    L.data = (ElemType *)malloc(sizeof(ElemType) * L.length);
    for (int i = 0; i < length; i++)
        L.data[i] = arr[i];
    return L;
}

void test(int arr1[], int length1) {
    SqList L = initList(arr1, length1);
    ElemType e;
    deleteList(L, e);
    cout << e << endl;
    outPutList(L);
}

int main() {
    ElemType A[] = {3, 4, 5, 0, 1, 2, 6, 7, 8};
    int length1 = sizeof(A) / sizeof(int);

    test(A, length1);
    return 0;
}

// 输出结果：
// 0
// 3 4 5 8 1 2 6 7

