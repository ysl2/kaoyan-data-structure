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

void flagArrange(int a[], int length) {
    int red = 0, white = 0, blue = 0;
    for (int i = 0; i < length; i++) {
        if (a[i] == -1)
            red++;
        else if (a[i] == 0)
            white++;
        else
            blue++;
    }
    for (int i = 0; i < red; i++)
        a[i] = -1;
    for (int i = red; i < red + white; i++)
        a[i] = 0;
    for (int i = red + white; i < red + white + blue; i++)
        a[i] = 1;
}

int main() {
    ElemType A[] = {-1, 1, 0, -1, 1, 0, -1, 1, 0, 1};
    int length = sizeof(A) / sizeof(int);
    flagArrange(A, length);
    outPut(A, length);
    return 0;
}

// 输出结果：
// 0:  -1 -1 -1 0 0 0 1 1 1 1
