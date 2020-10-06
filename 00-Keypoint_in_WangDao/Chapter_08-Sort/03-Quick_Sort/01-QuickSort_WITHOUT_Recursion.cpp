#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <stack>
using namespace std;

typedef int ElemType;

void outPut(int *A, int length) {
    static int i = 0;
    cout << i++ << ":  ";
    for (int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void swap(int *A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// 划分算法
int partition(int *A, int low, int high) {
    int pivot = A[low];  // 假设每次都以第一个元素作为枢轴值，进行一趟划分：
    while (low < high) {
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];  // 停下来做交换
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];  // 停下来做交换
    }
    A[low] = pivot;  // pivot的最终落点
    return low;
}

// 非递归快排
void quickSort(int A[], int _LOW, int _HIGH) {
    // 手动利用栈来存储每次分块快排的起始点
    // 栈非空时循环获取中轴入栈
    stack<int> s;
    if (_LOW < _HIGH) {
        int pivotPos = partition(A, _LOW, _HIGH);
        if (pivotPos - 1 > _LOW) {  // 确保左分区存在
            // 将左分区端点入栈
            s.push(_LOW);
            s.push(pivotPos - 1);
        }
        if (pivotPos + 1 < _HIGH) {  // 确保右分区存在
            s.push(pivotPos + 1);
            s.push(_HIGH);
        }
        while (!s.empty()) {
            // 得到某分区的左右边界
            int high = s.top();
            s.pop();
            int low = s.top();
            s.pop();

            pivotPos = partition(A, low, high);
            if (pivotPos - 1 > low) {  // 确保左分区存在
                // 将左分区端点入栈
                s.push(low);
                s.push(pivotPos - 1);
            }
            if (pivotPos + 1 < high) {  //确保右分区存在
                s.push(pivotPos + 1);
                s.push(high);
            }
        }
    }
}

int main() {
    ElemType A[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(A) / sizeof(int);
    quickSort(A, 0, length - 1);
    //输出，检验结果
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}

// 输出结果：
// 0 1 2 3 4 5 6 7 8 9
