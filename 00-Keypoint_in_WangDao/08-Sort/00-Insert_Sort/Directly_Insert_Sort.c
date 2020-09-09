void insertSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        if (A[i] > A[i - 1]) continue;
        int temp = A[i], j = i - 1;
        for ( ; j >= 0 && A[j] > temp; j--) A[j + 1] = A[j];
        A[j + 1] = temp;
    }
}