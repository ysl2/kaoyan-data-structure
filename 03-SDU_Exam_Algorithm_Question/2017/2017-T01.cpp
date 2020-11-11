#include <iostream>
#include <stack>
using namespace std;

typedef int ElemType;

void outPut(ElemType *A, int length) {
    for (int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void swap(ElemType *A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// 法1
// 参考王道课后题 3.3 T02
void reverseOddAndEven1(ElemType a[], int length) {
    stack<ElemType> s;
    int k = 0;
    for (int i = 0; i < length; i++) {
        // 如果是奇数，就留下
        // 如果是偶数，就暂存
        if (a[i] % 2 == 1)
            a[i - k] = a[i];
        else {
            s.push(a[i]);
            k++;
        }
    }
    // 倒着录入，这样能保证偶数之间的相对顺序不变
    // 如果正着录入，会导致偶数部分是逆着原序列排列的
    for (int i = length - 1; i >= 0 && !s.empty(); i--) {
        a[i] = s.top();
        s.pop();
    }
}

// 法2
// 山大资料给的答案
// 基于快速排序
void reverseOddAndEven2(ElemType a[], int low, int high) {
    while (low < high) {
        while (low < high && a[low] % 2 == 1)
            ++low;
        while (low < high && a[high] % 2 == 0)
            --high;
        swap(a, low, high);
    }
}

void test(ElemType a[], int length, int index) {
    if (index == 1)
        reverseOddAndEven1(a, length);
    if (index == 2) {
        int low = 0, high = length - 1;
        reverseOddAndEven2(a, low, high);
    }
    outPut(a, length);
}

int main() {
    ElemType A[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(A) / sizeof(int);
    test(A, length, 1);
    test(A, length, 2);
    return 0;
}

// 输出结果：
// 1 3 5 7 9 0 2 4 6 8
// 1 3 5 7 9 0 2 4 6 8
