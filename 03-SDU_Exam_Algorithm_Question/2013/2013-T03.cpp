#include <iostream>
using namespace std;

int converseMatrixToArray(int order, int i, int j) {
    return (i <= j) ? (i * (2 * order - i + 1) / 2 + j - i) : (order * (order + 1) / 2);  // 我这里矩阵下标从0, 0开始的
}

void printArrayToMatrix(int *arr, int order) {
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++)
            cout << arr[converseMatrixToArray(order, i, j)] << " ";
        cout << endl;
    }
}

int *matrixAdd(int arr1[], int arr2[], int order) {
    int *result = new int[order * (order + 1) / 2 + 1];  // 注意存储的元素个数究竟是多少
    for (int i = 0; i < order * (order + 1) / 2 + 1; i++)
        result[i] = arr1[i] + arr2[i];
    return result;
}

void test(int arr1[], int arr2[], int order) {
    printArrayToMatrix(matrixAdd(arr1, arr2, order), order);
}

int main() {
    /*
         输入：
        {
            1, 0, 0,
            0, 2, 1,
            0, 0, 3
        },{
            2, 0, 1,
            0, 3, 0,
            0, 0, 4
        }
        输出：两个矩阵相加后的矩阵
    */
    // 矩阵应该有两个属性：值（指矩阵元素）和阶（指矩阵的阶数）
    int arr1[] = {1, 0, 0, 2, 1, 3, 0};
    int arr2[] = {2, 0, 1, 3, 0, 4, 0};
    int order = 3;

    test(arr1, arr2, order);

    return 0;
}

// 输出结果：
// 3 0 1
// 0 5 1
// 0 0 7
