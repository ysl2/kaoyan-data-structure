// 2020-10-04
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

void reverse(SqList L, int low, int high) {
    if (low >= high)
        return;
    // 见doc文件夹中的Array_Mid.md，对于数组中点的解释
    for (int i = 0; i < (high - low + 1) / 2; i++) {
        int temp = L.data[low + i];
        L.data[low + i] = L.data[high - i];
        L.data[high - i] = temp;
    }
}

// 先整体换（前面是m，后面是n），再单独换。单独换的时候，前面是n，后面是m
void reverseList(SqList L, int m, int n) {
    reverse(L, 0, L.length - 1);
    // 注意下标从0开始计数，而n表示元素的个数，是从1开始算的。
    // 因此实际上0到n - 1就表示一共n个元素。
    reverse(L, 0, n - 1);
    // 下面的m + n - 1同理
    reverse(L, n, m + n - 1);  // (m + n - 1) 与 (L.length - 1) 相等
}

void test(int arr[], int length, int m, int n) {
    SqList L = initList(arr, length);
    reverseList(L, m, n);
    outPutList(L);
}

int main() {
    ElemType A[] = {1, 3, 5, 7, 9, 2, 4, 6};
    int length = sizeof(A) / sizeof(ElemType);

    int m = 5;
    int n = 3;

    test(A, length, m, n);

    return 0;
}

// 输出结果：
// 2 4 6 1 3 5 7 9


