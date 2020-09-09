// 先第一部分，再第二部分，再整体
void reverse(int A[], int left, int right) {
    for (int i = 0; i < (right - left + 1) / 2; i++) {
    // i指的是距离，不是下标。因此无论left是多少，i始终从0开始计数
    // i表示距离left有多远，是相对的。
        int temp = A[left + i];
        A[left + i] = A[right - i];
        A[right - i] = temp;
    }
}

void converse(int A[], int p, int n) {
    // n表示两个数组加起来一共n个元素
    // p表示第一个子数组有p个元素
    // 也就是第二个子数组有(n - p)个元素
    // 但是实际上这个题用不到n - p。只要知道left和right就可以了
    // 虽然上面的i是相对距离，但是left和right却是下标值
    reverse(A, 0, p - 1);
    reverse(A, p, n - 1);
    reverse(A, 0, n - 1);
}

