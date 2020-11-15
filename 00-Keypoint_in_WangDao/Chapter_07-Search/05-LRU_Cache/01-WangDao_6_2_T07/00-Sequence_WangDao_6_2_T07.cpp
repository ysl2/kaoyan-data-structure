#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct {
    ElemType *data;
    int length;
} SqTable;

void outputTable(SqTable T) {
    for (int i = 0; i < T.length; i++)
        cout << T.data[i] << " ";
    cout << endl;
}

int search(SqTable T, ElemType value) {
    int i;
    for (i = 0; i < T.length && T.data[i] != value; i++)
        ;
    if (i != T.length && i != 0) {  // 如果找到了，并且不是第一个结点
        int temp = T.data[i - 1];
        T.data[i - 1] = T.data[i];
        T.data[i] = temp;
        return i - 1;  // 这里返回的是交换后的新位置
    } else
        return i == T.length ? -1 : i;  // 否则，返回原先的位置
}

// 本题类似于LRU缓存。（并不完全是）
// 关键词：LRU缓存、页面置换算法
SqTable getTable(int arr[], int length) {
    SqTable T;
    T.data = arr;
    T.length = length;
    return T;
}

void test(ElemType a[], int length, ElemType key) {
    SqTable T = getTable(a, length);
    search(T, key);
    outputTable(T);
}

int main() {
    ElemType A[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(A) / sizeof(A[0]);
    test(A, length, 1);
    return 0;
}

// 输出结果：
// 0 2 4 6 1 8 3 5 7 9
