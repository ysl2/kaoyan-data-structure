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

void flagArrange(int *A, int length) {
    // j是工作指针，i之前的全部都是-1，k之后的全部都是1
    int i = 0, j = 0, k = length - 1;
    while (j <= k) {
        if (A[j] == -1)
            swap(A, i++, j++);
        // 注意i++和++i的区别。
        // i++是先把i传入到swap里，然后执行完swap之后，i再自增
        // ++i是i先自增，然后把自增后的i传入到swap里去执行
        else if (A[j] == 0)
            j++;
        else
            swap(A, j, k--);
        // 这里没有j++以防止交换后A[j]为1或0
    }
}

int main() {
    ElemType A[] = {-1, 1, 0, -1, 1, 0, -1, 1, 0, 1};
    int length = sizeof(A) / sizeof(int);
    flagArrange(A, length);
    outPut(A, length);
    return 0;
}

// 输出结果：
// 0:  -1 -1 -1 0 0 0 1 1 1

