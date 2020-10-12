// 2020-10-05
#include <iostream>
using namespace std;

#define maxSize 20

typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
} SqList;

SqList initList(int arr[], int length) {
    SqList L;
    L.length = length;
    L.data = (ElemType *)malloc(sizeof(ElemType) * maxSize);
    for (int i = 0; i < length; i++)
        L.data[i] = arr[i];
    return L;
}

void outPutList(SqList L) {
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
}

// 在表L中以折半方式查找值为x的下标。如果找到了返回下标mid，如果没找到返回插入位置low
bool search(SqList L, ElemType x, int &result) {
    int low = 0, high = L.length - 1;
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (L.data[mid] == x)
            break;
        if (L.data[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    // 如果找到了，返回目标位置mid。否则，返回插入位置low
    if (L.data[mid] == x) {
        result = mid;
        return true;
    } else {
        result = low;
        return false;
    }
}

// 将当前位置index与后一个位置index + 1做交换
void exchange(SqList &L, int index) {
    int temp = L.data[index];
    L.data[index] = L.data[index + 1];
    L.data[index + 1] = temp;
}

// 把x插入到表的下标为index的位置
void insert(SqList &L, int index, ElemType x) {
    for (int j = L.length; j > index; j--)
        L.data[j] = L.data[j - 1];
    L.data[index] = x;
    L.length++;
}
void searchExchangeInsert(SqList &L, ElemType x) {
    int result;
    int flag = search(L, x, result);
    if (flag == true && result != L.length - 1)  // 如果找到了，并且不是最后一个元素
        exchange(L, result);
    else if (flag == false)  // 如果没找到
        insert(L, result, x);
    // 注：这里还有一种情况是如果找到了，但是是最后一个元素。此时就什么都不做直接返回
}

void test(int arr[], int length) {
    SqList L1 = initList(arr, length);
    SqList L2 = initList(arr, length);
    SqList L3 = initList(arr, length);

    searchExchangeInsert(L1, 2);
    searchExchangeInsert(L2, 9);
    searchExchangeInsert(L3, 4);

    outPutList(L1);
    outPutList(L2);
    outPutList(L3);
}

int main() {
    ElemType A[] = {1, 2, 3, 5, 6, 7, 8, 9};
    int length1 = sizeof(A) / sizeof(int);

    test(A, length1);

    return 0;
}

// 输出结果：
// 1 3 2 5 6 7 8 9
// 1 2 3 5 6 7 8 9
// 1 2 3 4 5 6 7 8 9
