#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 成功运行。
// 对于函数声明是**a的情况，在使用时必须是*(*(a + i) + j)
// 对于函数声明是a[][column]的情况，在使用时必须是*((int *)a + i * line + j)
// 参考：
// https://blog.csdn.net/weixin_41666244/article/details/80615661
// https://blog.csdn.net/Mr_ck/article/details/107216164?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param
// https://blog.csdn.net/mayue_web/article/details/86590044?utm_medium=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param

int **createMatrix(int m, int n) {
// 动态申请数组并置初值为0
    int **a = (int **) malloc(sizeof(int *) * m);  // 申请列空间
    for (int i = 0; i < m; i++) {
        *(a + i) = (int *) malloc(sizeof(int) * n);  // 申请行空间
        memset(*(a + i), 0, sizeof(int) * n);  // 把整行置0
    }
    return a;
}

void outPut1(int **a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", *(*(a + i) + j));  
            // 对于传入**a的和传入a[row][column]的有不同的访问方式。
            // 传入**a的必须通过这种方式（见上面参考资料）
        }
        printf("\n");
    }
    printf("\n");
}

// outPut2仍然有问题：
void outPut2(int a[][4], int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t", *((int *)a + i * m + j));  
            // 对于传入**a的和传入a[row][column]的有不同的访问方式。
            // 传入**a的必须通过这种方式（见上面参考资料）
        }
        printf("\n");
    }
    printf("\n");
}

void test() {
    int m = 5, n = 4;
    int **a = createMatrix(m, n);
    a[3][2] = 1;  // 测试赋值有没有问题
    outPut1(a, m, n);  // outPut1正常
    // outPut2(a, m);  // outPut2仍有问题
}
int main() {
    test();
    return 0;
}

// 运行结果：
// 0	0	0	0	
// 0	0	0	0	
// 0	0	0	0	
// 0	0	1	0	
// 0	0	0	0