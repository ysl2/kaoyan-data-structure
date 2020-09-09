先整体换
再分开换

void reverse(int A[], int left, int right, int arraySize) {
    if (left >= right || right >= arraySize) {
        return ;
    }
    for (int i = 0; i < (left - right + 1) / 2; i++) {
        int temp = A[left + i];
        A[left + i] = A[right - i];
        A[right - i] = temp;
    }
}

void conserse(int A[], int m, int n, int arraySize) {
    reverse(A, 0, m + n - 1, arraySize);
    reverse(A, 0, n - 1, arraySize);
    reverse(A, n, m + n - 1, arraySize);
}

