#include <string.h>
#include <iostream>
using namespace std;

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

// 注意，题目说明是有序的表。如果表无序，就不能用这个方法，只能用基于计数排序的方法（见下面的01）
bool deleteList(SqList &L)  {
    if (L.length == 0)
        return false;
    int i, j;
    for (i = 0, j = 1; j < L.length; j++)
        if (L.data[i] != L.data[j])
            L.data[++i] = L.data[j];
    L.length = i + 1;
    return true;
}

void test(int arr[], int length) {
    SqList L;
    L.length = length;
    L.data = (ElemType *)malloc(sizeof(ElemType) * L.length);
    for (int i = 0; i < length; i++)
        L.data[i] = arr[i];

    outPutList(L);
    deleteList(L);
    outPutList(L);
}

int main() {
    ElemType A[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3};
    int length = sizeof(A) / sizeof(int);
    test(A, length);
    return 0;
}

// 输出结果：
// -1 -1 -1 0 0 0 1 1 1 2 2 2 3 3 3 3
// -1 0 1 2 3
