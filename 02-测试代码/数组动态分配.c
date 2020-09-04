#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int **createMatrix(int m, int n) {
// 动态申请数组并置初值为0
    int **a = (int **) malloc(sizeof(int *) * m);  // 申请列空间
    for (int i = 0; i < m; i++) {
        *(a + i) = (int *) malloc(sizeof(int) * n);  // 申请行空间
        memset(a + i, 0, sizeof(int) * n);  // 把整行置0
		// 经过测试发现，在converse函数中仅申请了空间，但未执行memset
		// 因此此方法存在问题，可能是由于指针问题导致的。
    }
    return a;
}

void outPut(int a[][], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void test() {
    int a[][] = createMatrix(5, 4);
    outPut(a, 5, 4);
}
int main() {
    test();
    return 0;
}