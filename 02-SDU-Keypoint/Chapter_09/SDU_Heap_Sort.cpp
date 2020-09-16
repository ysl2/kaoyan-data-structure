#include <iostream>
using namespace std;

typedef int ElemType;

void outPut(ElemType *A, int length) {
    static int counter = 1;
    cout << counter++ << ":  ";
    for (int i = 1; i <= length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void swap(ElemType *A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// 删除堆顶元素时，先将最后一个元素与堆顶元素交换，然后把根节点向下进行调整
void heapify1(ElemType A[], int k, int len) {  //将元素k向下调整
    A[0] = A[k];
    for (int i = 2 * k; i <= len; i *= 2) {
        if (i < len && A[i] < A[i + 1])
            i++;
        if (A[0] >= A[i])
            break;
        else
            A[k] = A[i];
        k = i;
    }
    A[k] = A[0];
}

void build_heap1(ElemType A[], int len) {
    for (int i = len / 2; i > 0; i--) {
        heapify1(A, i, len);
    }
}

void heap_sort1(ElemType A[], int len) {
    build_heap1(A, len);
    for (int i = len; i > 1; i--) {
        swap(A[i], A[1]);
        heapify1(A, 1, i - 1);
    }
}

// 测试模板：
void test(int tree[], int n) {
    outPut(tree, n);
    heap_sort1(tree, n);
    outPut(tree, n);
    cout << endl;
}

int main() {
    // length是数组长度
    // n是数组长度减1，表示含有真实元素部分的长度
    // 第一个位置不存元素，只是为了保证数组下标和树的特性吻合，做占位符，用-1作为标记
    int tree1[] = {-1, 98, 72, 86, 60, 65, 12, 23, 50};
    int tree2[] = {-1, 8, 38, 25, 58, 52, 82, 70, 60};
    int tree3[] = {-1, 28, 15, 12, 34, 9, 8, 56};

    int length1 = sizeof(tree1) / sizeof(int);
    int length2 = sizeof(tree2) / sizeof(int);
    int length3 = sizeof(tree3) / sizeof(int);

    test(tree1, length1 - 1);
    test(tree2, length2 - 1);
    test(tree3, length3 - 1);
    return 0;
}

// 输出结果：
// 1:  98 72 86 60 65 12 23 50
// 2:  12 23 50 60 65 72 86 98

// 3:  8 38 25 58 52 82 70 60
// 4:  8 25 38 52 58 60 70 82

// 5:  28 15 12 34 9 8 56
// 6:  8 9 12 15 28 34 56
