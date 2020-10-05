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

void test(int arr1[], int length1, int arr2[], int length2) {
    SqList A = initList(arr1, length1);
    SqList B = initList(arr2, length2);
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
