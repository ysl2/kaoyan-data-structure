#include <iostream>
#include <string.h>
using namespace std;

typedef int ElemType;

// m表示竖向，n表示横向
ElemType **createTwoDimensionArray(int m, int n) {
    ElemType **arr = new ElemType *[m];
    for (int i = 0; i < m; i++) {  // 竖向
        arr[i] = new ElemType[n];  // 横向
        memset(arr[i], 0, sizeof(ElemType) * n);
    }
    return arr;
}

void outputTwoDimensionArray(ElemType **arr, int m, int n) {
    for (int i = 0; i < m; i++) {  // 竖向
        for (int j = 0; j < n; j++)  // 横向
            cout << *(*(arr + i) + j) << "\t";
        cout << endl;
    }
}

void inputOneDimensionArrayValueToTwoDimensionArray(ElemType *ARR, int length, ElemType **arr, int m, int n) {
    int count = 0;
    for (int i = 0; i < m; i++) {  // 竖向
        for (int j = 0; j < n; j++) {  // 横向
            if (count >= length)
                return;
            *(*(arr + i) + j) = ARR[count];
            count++;
        }
    }
}

bool isSaddlePoint(ElemType **arr, int m, int n, int indexI, int indexJ) {
    // 横向不动（固定j），竖向动
    for (int i = 0; i < m; i++) {
        if (*(*(arr + i) + indexJ) < *(*(arr + indexI) + indexJ))
            return false;
    }
    // 竖向不动（固定i），横向动
    for (int j = 0; j < n; j++) {
        if (*(*(arr + indexI) + j) > *(*(arr + indexI) + indexJ))
            return false;
    }
    return true;
}

void getSaddlePoint(ElemType **arr, int m, int n) {
    for (int i = 0; i < m; i++) {  // 竖向
        for (int j = 0; j < n; j++) {  // 横向
            if (isSaddlePoint(arr, m, n, i, j)) {
                cout << *(*(arr + i) + j) << endl;
                return;
            }
        }
    }
}

void test(ElemType *ARR, int length, int m, int n) {
    ElemType **arr = createTwoDimensionArray(m, n);
    inputOneDimensionArrayValueToTwoDimensionArray(ARR, length, arr, m, n);
    outputTwoDimensionArray(arr, m, n);
    cout << endl;
    getSaddlePoint(arr, m, n);
}

int main() {
    ElemType ARR[] = {5, 6, 11, 7, 8, 3, 4, 10, 2, 1, 9, 10, 12, 14, 15, 16, 17, 13, 18, 19};
    int length = sizeof(ARR) / sizeof(ARR[0]);
    int m = 4;  // 竖向
    int n = 5;  // 横向

    test(ARR, length, m, n);

    return 0;
}

// 输出结果：
// 5       6       11      7       8
// 3       4       10      2       1
// 9       10      12      14      15
// 16      17      13      18      19

// 10
