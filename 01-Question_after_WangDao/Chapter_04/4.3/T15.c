#include <stdio.h>
#define maxSize 6
typedef char ElemType;

void preToPost(ElemType pre[], int left1, int right1, ElemType post[], int left2, int right2) {
    if (left1 > right1) {
        return ;
    }
    int half = (right1 - left1) / 2;  // 满二叉树结点数一定是奇数，因此不用考虑奇偶数的问题;
    post[right2] = pre[left1];
    preToPost(pre, left1 + 1, left1 + half, post, left2, left2 + half - 1);  // 左子树
    preToPost(pre, left1 + half + 1, right1, post, left2 + half, right2 - 1);  // 右子树
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

