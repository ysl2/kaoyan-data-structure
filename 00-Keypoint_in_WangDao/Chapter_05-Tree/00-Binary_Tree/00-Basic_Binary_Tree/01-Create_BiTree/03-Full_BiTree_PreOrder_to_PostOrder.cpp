#include <iostream>
using namespace std;
typedef char ElemType;

void printArray(ElemType arr[], int length) {
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// 满二叉树
// 根据先序遍历序列，得到后序遍历序列
void preToPost(ElemType preOrder[], int preOrderSize, ElemType postOrder[], int postOrderSize) {
    if (postOrderSize <= 0)
        return;
    postOrder[postOrderSize - 1] = preOrder[0];
    int half = preOrderSize / 2;  // 满二叉树结点数一定是奇数，因此不用考虑奇偶数的问题;
    preToPost(preOrder + 1, half , postOrder, half);  // 左子树
    preToPost(preOrder + 1 + half, preOrderSize - (half + 1), postOrder + half, postOrderSize - (half + 1));  // 右子树
}

void test(ElemType arr[], int length) {
    ElemType postOrder[length];
    preToPost(arr, length, postOrder, length);
    printArray(postOrder, length);
}

int main() {
    ElemType arr[] = {'A','B','C','D','E','F','G'};
    int length = sizeof(arr) / sizeof(arr[0]);

    test(arr, length);

    return 0;
}

// 运行结果：
// C D B F G E A
