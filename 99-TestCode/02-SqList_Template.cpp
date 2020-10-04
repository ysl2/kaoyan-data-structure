#include <iostream>
#include <string.h>
using namespace std;

#define INFINITY 99999
#define maxSize 100

typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
} SqList;

void outPutList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

SqList initList(int length) {
    SqList L;
    L.length = length;
    L.data = (ElemType *)malloc(sizeof(ElemType) * L.length);
    memset(L.data, 0, sizeof(ElemType) * length);
    return L;
}

SqList initList(int arr[], int length) {
    SqList L;
    L.length = length;
    L.data = (ElemType *)malloc(sizeof(ElemType) * L.length);
    for (int i = 0; i < length; i++) {
        L.data[i] = arr[i];
    }
    return L;
}

void test(int arr1[], int length1, int arr2[], int length2) {
    SqList C = initList(length1 + length2);
    SqList A = initList(arr1, length1);
    SqList B = initList(arr2, length2);

    outPutList(C);
}

int main() {
    ElemType A[] = {-1, 1, 2};
    ElemType B[] = {0, 1, 3, 4};

    int length1 = sizeof(A) / sizeof(int);
    int length2 = sizeof(B) / sizeof(int);

    test(A, length1, B, length2);
    return 0;
}

// 输出结果：
