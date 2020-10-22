// 2020-10-22
// 本题是王道的课后题，但是由于我自己掌握的不是很熟练，因此我选择重新写一遍
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

bool deleteList(SqList &L, ElemType x, ElemType y) {
    if (L.length == 0 || x >= y)
        return false;
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] >= x && L.data[i] <= y) {
            k++;
        } else {
            L.data[i - k] = L.data[i];
        }
    }
    L.length -= k;
    return true;
}

void test(int arr[], int length) {
    SqList L = initList(arr, length);
    deleteList(L, 4, 6);
    outPutList(L);
}

int main() {
    ElemType A[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};

    int length1 = sizeof(A) / sizeof(int);

    test(A, length1);

    return 0;
}

// 输出结果：
// 0 2 8 1 3 7 9
