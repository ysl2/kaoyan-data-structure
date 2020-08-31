#include <stdlib.h>
// abs函数在<stdlib.h>库
// max没有，要自己写
bool isBalanced(BiTree T) {
    return recur(T) != -1;
}

int recur(BiTree T) {
    if (T == NULL) return 0;
    int left = recur(T->lchild);
    if(left == -1) return -1;
    int right = recur(T->rchild);
    if(right == -1) return -1;
    return abs(left - right) < 2 ? max(left, right) + 1 : -1;
}

int max(int i, int j) {
    return (i > j)? i : j;
}

