#include <string.h>
#include <iostream>

using namespace std;

typedef int ElemType;

void outPut(ElemType *A, int length) {
    static int i = 0;
    cout << i++ << ":  ";
    for (int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void swap(ElemType *A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// https://blog.csdn.net/qq_34269988/article/details/90705977
// https://www.cnblogs.com/kyoner/p/10604781.html
void countSort(int *A, int length) {
    if (A == NULL)
        return;
    // 1. 得到数列的最大最小值
    int max = A[0], min = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] > max)
            max = A[i];
        if (A[i] < min)
            min = A[i];
    }
    // 2. 根据数列的最大值和最小值确定统计数组的长度
    int size = max - min + 1;
    // 创建统计数组
    int *count = (int *)malloc(sizeof(int) * size);
    memset(count, 0, sizeof(int) * size);
    // 计算统计对应的元素个数
    for (int i = 0; i < length; i++)
        count[A[i] - min]++;  //包含了自己！
    // 3. 统计数组变形，后面的元素等于前面的元素之和
    for (int i = 1; i < size; i++)
        count[i] += count[i - 1];
    // 4. 倒序遍历原始数组，从统计数组找到正确位置，输出到结果数组
    int *psort = (int *)malloc(sizeof(int) * length);
    memset(psort, 0, sizeof(int) * length);
    for (int i = length - 1; i >= 0; i--) {
        count[A[i] - min]--;  //要先把自己减去
        psort[count[A[i] - min]] = A[i];
    }
    // 5. 将结果复制回原数组
    for (int i = 0; i < length; i++) {
        A[i] = psort[i];
    }
    free(count);
    free(psort);
    count = NULL;
    psort = NULL;
}

int main() {
    ElemType A[] = {97, 91, 93, 95, 97, 99, 94, 92, 94, 96, 98};
    int length = sizeof(A) / sizeof(int);
    countSort(A, length);
    outPut(A, length);
    return 0;
}

// 输出结果：
// 0:  91 92 93 94 94 95 96 97 97 98 99
