#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct {
    ElemType *data;
    int length;
} SqTable;

SqTable getTable(int arr[], int length) {
    SqTable T;
    T.data = arr;
    T.length = length;
    return T;
}

int binarySearch(SqTable T, ElemType key) {
    if (T.length == 0)
        return -1;
    int low = 0, high = T.length - 1;
    while (low <= high) {  // 注意与快排的退出条件区分开
        int mid = low + (high - low) / 2;
        if (T.data[mid] == key)
            return mid;
        if (T.data[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void test(ElemType a[], int length, ElemType key) {
    SqTable T = getTable(a, length);
    cout << binarySearch(T, key) << endl;
}

int main() {
    ElemType A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(A) / sizeof(A[0]);
    test(A, length, 1);
    return 0;
}

// 输出结果：
// 1
