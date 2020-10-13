#include <stdio.h>
#define maxSize 6
typedef char ElemType;

void preToPost(ElemType pre[], int low1, int high1, ElemType post[], int low2, int high2) {
    if (low1 > high1)
        return;
    int half = (high1 - low1) / 2;  // 满二叉树结点数一定是奇数，因此不用考虑奇偶数的问题;
    post[high2] = pre[low1];
    preToPost(pre, low1 + 1, low1 + half, post, low2, low2 + half - 1);    // 左子树
    preToPost(pre, low1 + half + 1, high1, post, low2 + half, high2 - 1);  // 右子树
}
// 测试用例：
void test() {
    ElemType *pre = "ABCDEFG";
    ElemType post[maxSize];
    preToPost(pre, 0, 6, post, 0, 6);
    for (int i = 0; i <= 6; i++) {
        printf("%c\t", post[i]);
    }
    printf("\n");
}
int main() {
    test();
    return 0;
}

// 运行结果：
// C       D       B       F       G       E       A
