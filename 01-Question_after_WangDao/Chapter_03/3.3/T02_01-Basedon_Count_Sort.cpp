#include <stack>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define INFINITY 99999
using namespace std;

void outPut(char *A, int length) {
    static int i = 0;
    cout << i++ << ":  ";
    for (int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

// 这里没有采用王道用栈的思路，而是采用计数排序的思想。
// 虽然要排序的值是char类型，但是可以根据对应的ASCII码值进行排序
// 实际上对于这种数据量大，但范围小的序列，十分适合采用计数排序
void adjustArray(char a[], int length) {
    int min = INFINITY, max = -INFINITY;
    for (int i = 0; i < length; i++) {
        if ((int)a[i] >= max)
            max = (int)a[i];
        if ((int)a[i] <= min)
            min = (int)a[i];
    }
    int range = max - min + 1;

    int *count = (int *)malloc(sizeof(int) * range);
    memset(count, 0, sizeof(int) * range);
    for (int i = 0; i < length; i++)
        count[(int)a[i] - min]++;

    // 与常规的计数排序不同，这里采用倒序替换的方式。
    // 原因是S的ASCII码在H的后面， 因此必须倒着替换才能让S到H的前面
    int j = length - 1;  // 注意j初值的位置，是最后一个下标，而不是数组长度
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            a[j--] = (char)(i + min);
            count[i]--;
        }
    }
}

int main() {
    char arr[] = {'S', 'H', 'S', 'H', 'S', 'H', 'S', 'H', 'S'};
    int length = sizeof(arr) / sizeof(char);
    adjustArray(arr,length);
    outPut(arr, length);
}

// 输出结果：
// 0:  S S S S S H H H H
