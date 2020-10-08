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

bool deleteList(SqList &L, ElemType x) {
    if (L.length == 0)
        return false;
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == x)
            k++;
        else
            L.data[i - k] = L.data[i];
    }
    L.length -= k;
    return true;
}

void test(int arr1[], int length1) {
    SqList L = initList(arr1, length1);
    deleteList(L, 0);
    outPutList(L);
}

int main() {
    ElemType A[] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    int length1 = sizeof(A) / sizeof(int);

    test(A, length1);
    return 0;
}

// 输出结果：
// 1 2 1 2 1 2
