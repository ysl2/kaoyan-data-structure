// 2020-10-17
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

// 由于题目和问题“数字的回文”等价，只是一个用char类型表示，另一个用int类型表示。为了简化代码，这里采用int类型作为问题

// 方法1：采用入栈出栈的方式。这样做会导致空间复杂度较高。空间复杂度是O(n)
bool judgeIsSym1(ElemType a[], int length) {
    stack<int> s;
    int i = 0;
    for (; i < length / 2; i++)
        s.push(a[i]);
    if (length % 2 == 1)
        i++;
    while (i < length) {
        int temp = s.top();
        s.pop();
        if (a[i] != temp)
            return false;
        i++;
    }
    return s.empty();
}

// 方法2：直接双指针遍历，空间复杂度是O(1)
bool judgeIsSym2(ElemType a[], int length) {
    int i = 0, j = length - 1;
    while (i != j && i + 1 != j) {  // 分别对应奇数和偶数
        if (a[i] != a[j])
            return false;
        i++;
        j--;
    }
    return (i == j) || (i + 1 == j && a[i] == a[j]);
}

void test(ElemType a[], int length) {
    outPut(a, length);

    if (judgeIsSym2(a, length) == true)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

int main() {
    ElemType arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length1 = sizeof(arr1) / sizeof(int);
    ElemType arr2[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    int length2 = sizeof(arr2) / sizeof(int);
    ElemType arr3[] = {1, 2, 3, 4, 4, 3, 2, 1};
    int length3 = sizeof(arr3) / sizeof(int);

    test(arr1, length1);
    test(arr2, length2);
    test(arr3, length3);

    return 0;
}

// 输出结果：
// 0 1 2 3 4 5 6 7 8 9
// false
// 1 2 3 4 5 4 3 2 1
// true
// 1 2 3 4 4 3 2 1
// true

