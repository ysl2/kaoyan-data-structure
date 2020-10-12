// 2020-10-04
#include <string.h>
#include <iostream>
using namespace std;

#define INFINITY 99999

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

// 这个方法的优势在于：不要求表必须有序。对于无序的表，也可以处理
// 但是由于定义了一个辅助数组，因此空间复杂度变高了
// 时间复杂度：当输入的元素是n个0到k之间的整数时，它的运行时间是 Θ(n + k)。（和计数排序相同）
bool deleteList(SqList &L) {
    if (L.length == 0)
        return false;
    int min = INFINITY, max = -INFINITY;
    for (int i = 0; i < L.length; i++) {
        if ((int)L.data[i] > max)
            max = (int)L.data[i];
        if ((int)L.data[i] < min)
            min = (int)L.data[i];
    }
    int range = max - min + 1;

    int *B = (int *)malloc(sizeof(int) * range);
    if (B == NULL)
        return false;
    memset(B, 0, sizeof(ElemType) * range);
    for (int i = 0; i < L.length; i++)
        B[(int)L.data[i] - min]++;

    int j = 0;
    for (int i = 0; i < range; i++) {
        if (B[i] > 0) // 注意此处与计数排序不同。计数排序应该把if改成while。但是这里题目要求仅删除重复元素而不是排序，因此只需每个元素写入一次即可
            L.data[j++] = (ElemType)(i + min);
    }
    L.length = j;  // 这里让length为j，而不是为range。因为数组B中可能包含0，而值为0的元素下标不会计入L，因此应该以L的实际长度j为最终的长度
    return true;
}

void test(int arr[], int length) {
    SqList L;
    L.length = length;
    L.data = (ElemType *)malloc(sizeof(ElemType) * L.length);
    for (int i = 0; i < length; i++)
        L.data[i] = arr[i];

    deleteList(L);
    outPutList(L);
}

int main() {
    ElemType A[] = {-1, 1, -2, -1, 1, 0, -1, 1, 0, 1, 3};
    int length = sizeof(A) / sizeof(int);
    test(A, length);
    return 0;
}

// 输出结果：
// -2 -1 0 1 3

