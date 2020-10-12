// 2020-10-05
#include <iostream>
using namespace std;

void outPut(int arr[], int length) {
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
}

// 循环左移p个单位长度
// 先部分，再整体
void reverse(int a[], int low, int high) {
    if (low >= high)
        return;
    for (int i = 0; i < (high - low + 1) / 2; i++) {
        // i指的是距离，不是下标。因此无论low是多少，i始终从0开始计数
        // i表示距离low有多远，是相对的。
        int temp = a[low + i];
        a[low + i] = a[high - i];
        a[high - i] = temp;
    }
}

void reverseArray(int a[], int length, int p) {
    // n表示两个数组加起来一共n个元素
    // p表示第一个子数组有p个元素
    // 也就是第二个子数组有(n - p)个元素
    // 但是实际上这个题用不到n - p。只要知道low和high就可以了
    // 虽然上面的i是相对距离，但是low和high却是下标值
    reverse(a, 0, p - 1);
    reverse(a, p, length - 1);
    reverse(a, 0, length - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(arr) / sizeof(int);

    reverseArray(arr, length, 3);
    outPut(arr, length);
}

// 输出结果：
// 4 5 6 7 8 9 1 2 3
