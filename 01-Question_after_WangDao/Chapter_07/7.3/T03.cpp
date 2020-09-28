#include <iostream>
using namespace std;

typedef int ElemType;

void outPut(ElemType *A, int length) {
    static int i = 0;
    cout << i++ << ":  ";
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

// 这是我自己写的，用插入排序思想也可以实现，优点在于不会改变原先序列的相对顺序
void insertSort(ElemType A[], int length) {
    for (int i = 1; i < length; i++) {
        if (A[i] % 2 == 1) {
            int temp = A[i];
            int j = i - 1;
            for (; j >= 0 && A[j] % 2 == 0; j--)
                A[j + 1] = A[j];
            A[j + 1] = temp;
        }
    }
}

// 本题要求时空复杂度最少，因此原题采用的快排思想是最佳的
void quickSort(ElemType *A, int length) {
    int low = 0, high = length - 1;
    while (low < high) {
        // 如果是奇数，略过，继续向后遍历
        while (low < high && A[low] % 2 != 0)
            low++;
        // 如果是偶数，略过，继续向前遍历
        while (low < high && A[high] % 2 != 1)
            high--;
        // 如果找到了一个偶数low和一个奇数high，并且偶数low在奇数high前面
        if (low < high)
            swap(A, low, high);
        // 交换完成后，当前位置已经不需要再被下一次遍历，
        // 因此low和high分别各自移动到下一个位置
        low++, high--;
    }
}

int main() {
    ElemType A[] = {2, 4, 6, 8, 1, 3, 5, 7, 9};
    ElemType B[] = {2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length1 = sizeof(A) / sizeof(int);
    int length2 = sizeof(B) / sizeof(int);

    quickSort(A,length1);  // 本题要求时空复杂度最少，因此原题采用的快排思想是最佳的
    insertSort(B, length2);  // 这是我自己写的，用插入排序思想也可以实现，优点在于不会改变原先序列的相对顺序

    outPut(A,length1);
    outPut(B,length2);

    return 0;
}

// 输出结果：
// 0:  9 7 5 3 1 8 6 4 2
// 1:  1 3 5 7 9 2 4 6 8
