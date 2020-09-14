#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void outPut(int a[], int n) {  // 一维数组形参可以用*a，也可以用a[]
    // *(a + 4) = 2;
    a[4] = 2;
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int *createArray(int n) {
    int *a = (int *) malloc(sizeof(int) * n);
    memset(a, 0, sizeof(int) * n);
    return a;
}

void test() {
    int n = 5;
    int *a = createArray(n);
    a[3] = 1;
    outPut(a, n);
}

int main() {
    test();
    return 0;
}

// 运行结果：
// 0       0       0       1       2
