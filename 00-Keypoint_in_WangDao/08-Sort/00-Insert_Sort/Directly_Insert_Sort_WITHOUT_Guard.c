void insertSort(int A[], int length) {
    for (int i = 1; i < length; i++) {
        int temp = A[i], j = i - 1;
        for ( ; j >= 0 && A[j] > temp; j--) 
            A[j + 1] = A[j];
        A[j + 1] = temp;
    }
}