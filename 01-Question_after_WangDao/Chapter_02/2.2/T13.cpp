#include <string.h>
#include <iostream>
using namespace std;

typedef int ElemType;

int getmin(int *A, int length) {
    int *B = (int *)malloc(sizeof(int) * length);
    memset(B, 0, sizeof(int) * length);
    for (int i = 0; i < length && A[i] > 0 && A[i] <= length; i++)
        if (B[A[i] - 1] == 0)
            B[A[i] - 1] = 1;
    int i;
    for (i = 0; i < length; i++)
        if (B[i] == 0)
            break;
    free(B);
    return i + 1;
}

int main() {
    ElemType A1[] = {-5, 3, 2, 3};
    int length1 = sizeof(A1) / sizeof(int);
    ElemType A2[] = {1, 2, 3};
    int length2 = sizeof(A2) / sizeof(int);

    cout << getmin(A1, length1) << endl;
    cout << getmin(A2, length2) << endl;
    return 0;
}

// 输出结果：
// 1
// 4
