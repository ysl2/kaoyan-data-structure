#include <iostream>
using namespace std;

typedef int ElemType;

void outPut(ElemType *A, int length) {
    static int i = 1;
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

//后序遍历
void postOrder(int tree[], int i, int n) {
    if (i > n)
        return;
    postOrder(tree, i * 2, n);
    postOrder(tree, i * 2 + 1, n);
    printf("%d%s", tree[i], i == 1 ? "" : " ");
}

// 王道课后题的代码：
bool is_min_heap(int tree[], int n) {  // 只能判断是不是小顶堆
    if (n % 2 == 0) {
        if (tree[n / 2] > tree[n])
            return false;
        for (int i = n / 2 - 1; i >= 1; i--) {
            if (tree[i] > tree[2 * i] || tree[i] > tree[2 * i + 1])
                return false;
        }
    } else {
        for (int i = n / 2; i >= 1; i--) {
            if (tree[i] > tree[2 * i] || tree[i] > tree[2 * i + 1])
                return false;
        }
    }
    return true;
}

// 一共有n个结点。按层序从1开始编号，最后一个结点的下标是n，
// 如果算上第一个下标0，那么数组的长度应该是n + 1，但是有效存储下标范围只有1 ~ n
// 结点i <= floor(n / 2) 时，是分支结点，i > floor(n / 2) 为叶子结点
// 当2 * i <= n时，左孩子存在。当2 * i + 1 <= n时，右孩子存在
// 堆默认已经是完全二叉树了，因此不用再针对完全二叉树进行判断

// is_heap参考：https://blog.csdn.net/Daniel_2046/article/details/80963737
void is_heap(int tree[], int n) {           // 大顶堆、小顶堆、不是堆，都能判断
// 此方法中，n是最后一个下标，而不是数组长度。这个数组的长度是n + 1
    int flag = tree[1] > tree[2] ? 1 : -1;  //由第1，2个元素判定堆序
    for (int i = 1; i <= n / 2; i++) {
        int lchild = i * 2, rchild = i * 2 + 1;  //堆的数组表示
        if (flag == 1 && ((lchild <= n && tree[i] < tree[lchild]) || (rchild <= n && tree[i] < tree[rchild])))
            flag = 0;  //大根堆的判定
        if (flag == -1 && ((lchild <= n && tree[i] > tree[lchild]) || (rchild <= n && tree[i] > tree[rchild])))
            flag = 0;  //小根堆的判定
    }

    if (flag == 1) {
        printf("Max Heap\n");
    } else if (flag == -1) {
        printf("Min Heap\n");
    } else if (flag == 0) {
        printf("Not Heap\n");
    }
}

void heapify(int tree[], int length, int i) {  // 从第 i 个 开始做 heapify
    if (i >= length)
        return;
    int c1 = 2 * i + 1;
    int c2 = 2 * i + 2;

    int max = i;
    if (c1 < length && tree[c1] > tree[max])
        max = c1;
    if (c2 < length && tree[c2] > tree[max])
        max = c2;
    if (max != i) {
        swap(tree, max, i);
        heapify(tree, length, max);
    }
}

void build_heap(int tree[], int length) {
    int last_node = length - 1;
    int parent = (last_node - 1) / 2;

    for (int i = parent; i >= 0; i--)
        heapify(tree, length, i);
}

// 堆排序
void heap_sort(int tree[], int length) {
    build_heap(tree, length);
    for (int i = length - 1; i >= 0; i--) {
        swap(tree, i, 0);
        heapify(tree, i, 0);
    }
}

// 测试模板：
void test(int tree[], int n) {
    // n是数组长度减1。注意看下面哪些是n，哪些是n + 1
    if (is_min_heap(tree, n))
        cout << "is min heap" << endl;
    is_heap(tree, n);
    postOrder(tree, 1, n);
    cout << endl;
    heap_sort(tree, n + 1);
    outPut(tree, n + 1);
    cout << endl;
}

int main() {
    // length是数组长度
    // n是数组长度减1，表示含有真实元素部分的长度
    // 第一个位置不存元素，只是为了保证数组下标和树的特性吻合，做占位符，用-1作为标记
    int tree1[] = {-1, 98, 72, 86, 60, 65, 12, 23, 50};
    int tree2[] = {-1, 8, 38, 25, 58, 52, 82, 70, 60};
    int tree3[] = {-1, 10, 28, 15, 12, 34, 9, 8, 56};

    int length1 = sizeof(tree1) / sizeof(int);
    int n1 = length1 - 1;
    int length2 = sizeof(tree2) / sizeof(int);
    int n2 = length2 - 1;
    int length3 = sizeof(tree3) / sizeof(int);
    int n3 = length3 - 1;

    test(tree1, n1);
    test(tree2, n2);
    test(tree3, n3);

    return 0;
}

// 输出结果：

// Max Heap
// 50 60 65 72 12 23 86 98
// 1:  -1 12 23 50 60 65 72 86 98

// Min Heap
// is min heap
// 60 58 52 38 82 70 25 8
// 2:  -1 8 25 38 52 58 60 70 82

// Not Heap
// 56 12 34 28 9 8 15 10
// 3:  -1 8 9 10 12 15 28 34 56
