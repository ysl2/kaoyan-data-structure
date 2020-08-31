int getmin(int A[], int n) {
    int i, *B;  // i必须放外面，因为和最后的返回值有关
    B = (int *) malloc(sizeof(int) * n);
    memset(B, 0, sizeof(int) * n);
    for (i = 0; i < n; i++) {
        if (A[i] > 0 && A[i] <= n) {  //注意，左开右闭区间
            B[A[i] - 1] = 1;
        }
    }
    for (i = 0; i < n; i++) {
        if (B[i] == 0) {  //要的是等于0的。因为等于0说明当前值没有在A中出现
            break;
        }
    }
    return i + 1;
}

