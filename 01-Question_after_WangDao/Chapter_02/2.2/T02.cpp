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

void reverse(SqList &L) {
    for (int i = 0; i < L.length / 2; i++) {
        int temp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = temp;
    }
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
    reverse(L);
    outPutList(L);
}

int main() {
    ElemType A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length1 = sizeof(A) / sizeof(int);

    test(A, length1);
    return 0;
}

// 输出结果：
// 9 8 7 6 5 4 3 2 1
