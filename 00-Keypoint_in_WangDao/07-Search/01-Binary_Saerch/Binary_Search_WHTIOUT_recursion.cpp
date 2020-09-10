#include <stddef.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
} SqTable;

int binarySearch(SqTable &T, ElemType key) {
    if (T.length == 0) 
        return -1;
    int low = 0, high = T.length - 1;
    while (low <= high) {  // 注意与快排的退出条件区分开
        int mid = low + (high - low) / 2;
        if (T.data[mid] == key) 
            return mid;
        if (T.data[mid] < key) 
            low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void initTable(SqTable &T, int length) {
    T.data = (ElemType *)malloc(sizeof(ElemType) * length);
    for (int i = 0; i < length; i++) {
        T.data[i] = 2 * i;  // 所有偶数
    }
    T.length = length;
}

void test() {
    SqTable T;  // 把T里面全部初始化成偶数
    int length = 10;
    int target1 = 6;
    int target2 = 7;
    initTable(T, length);
    cout << binarySearch(T, target1) << endl;
    cout << binarySearch(T, target2);
}

int main() {
    test();
    return 0;
}

// 输出结果：
// 3
// -1