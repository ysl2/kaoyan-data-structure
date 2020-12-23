#include <iostream>
using namespace std;

typedef int ElemType;

void outPut(ElemType *A, int length) {
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
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

// 在一个堆中，下标为i的结点与其父节点和孩子结点的关系：(注意：此处下标从1开始计算，n是含有待排序元素的下标，范围是[1, (length - 1)]
// 父节点：i / 2  ->  实际上这里是向下取整。只是对于编程语言来说，会直接以截取的方式除，因此自动向下取整
// 左子节点c1：2 * i
// 右子节点c2：2 * i + 1
// 当2 * i <= n时，左孩子存在。当2 * i + 1 <= n时，右孩子存在
// 堆默认已经是完全二叉树了，因此不用再针对是否是完全二叉树进行判断
// 因为对于顺序存储的树，只要数据部分没有空的位置，就说明是完全二叉树

// isHeap参考：https://blog.csdn.net/Daniel_2046/article/details/80963737
void isHeap(int tree[], int n) {           // 大顶堆、小顶堆、不是堆，都能判断
// 此方法中，n是最后一个下标，而不是数组长度。这个数组的长度是n + 1
    int flag = tree[1] > tree[2] ? 1 : -1;  //由第1，2个元素判定堆序
    for (int i = 1; i <= n / 2; i++) {
        int lchild = i * 2, rchild = i * 2 + 1;  //堆的数组表示
        if (flag == 1 && ((lchild <= n && tree[i] < tree[lchild]) || (rchild <= n && tree[i] < tree[rchild])))
            flag = 0;  //大根堆的判定
        if (flag == -1 && ((lchild <= n && tree[i] > tree[lchild]) || (rchild <= n && tree[i] > tree[rchild])))
            flag = 0;  //小根堆的判定
    }

    if (flag == 1)
        printf("Max Heap\n");
    else if (flag == -1)
        printf("Min Heap\n");
    else if (flag == 0)
        printf("Not Heap\n");
}



// 下面这三个函数是堆排序的代码：

void heapify(int a[], int length, int i) {  // 由下标为i的结点向下递归堆化
    // 获取结点i的左孩子和右孩子
    int left = 2 * i;
    int right = 2 * i + 1;

    // 找到i和i的孩子里面，值最大的那个。先假设i就是最大的，然后和它的孩子互相比较，最终选出一个真正最大的
    int maxIndex = i;
    // 为了确保叶子节点存在，需要判断叶子节点的下标是否在数组的合法下标范围之内。
    // 合法下标范围：[1 ~ (length - 1)]
    if (left <= length - 1 && a[left] > a[maxIndex])
        maxIndex = left;
    if (right <= length - 1 && a[right] > a[maxIndex])
        maxIndex = right;
    // 通过上面两个if，maxIndex中获取到了以i为根的小子树中含有最大值的结点下标
    if (maxIndex != i) {
        // 如果这个最大值不是i，也就是最大值是i的左孩子或右孩子
        // 必须做交换，并且被交换的那个i的孩子很有可能需要继续向下交换
        swap(a, maxIndex, i);
        // 因此递归向被交换了的孩子位置堆化
        heapify(a, length, maxIndex);
    }
}

void buildHeap(int a[], int length) {
    // 从最后一个非叶子结点开始，向上进行堆化。而堆化的过程又会向下进行
    // 当进行完上述步骤后，就会得到一个大根堆
    for (int i = (length - 1) / 2; i >= 1; i--)
        heapify(a, length, i);
}

void heapSort(int a[], int length) {
    // 先建立大根堆，然后交换第一个和最后一个节点。然后排除掉最后一个节点（此结点已经排好序了）进行堆化
    buildHeap(a, length);
    while (length >= 3/*或者length > 2*/) {
        swap(a, length - 1, 1);
        length--;
        heapify(a, length, 1);
    }
    // 当length等于1时，数组只剩下-1了。没有真正有效的元素。因此不需要排序
    // 当length等于2时，数组里含有-1和一个有效元素（假设为x）。真正有效的元素也只有x，因此也不需要再排序。
    // 当length等于3时，除了有效元素x以外，还有别的有效元素。这时才需要排序
}

// 测试模板：
void test(int tree[], int length) {
    // n是数组长度减1。注意看下面哪些是n，哪些是length
    int n = length - 1;
    if (is_min_heap(tree, n))
        cout << "is min heap" << endl;
    isHeap(tree, n);
    postOrder(tree, 1, n);
    cout << endl;
    heapSort(tree, length);
    outPut(tree, length);
    cout << endl;
}

int main() {
    // length是数组长度
    // n是数组长度减1，表示含有真实元素部分的长度
    // 第一个位置不存元素，只是为了保证数组下标和树的特性吻合，做占位符，用-1作为标记
    int tree1[] = {-1, 98, 72, 86, 60, 65, 12, 23, 50};
    int tree2[] = {-1, 8, 38, 25, 58, 52, 82, 70, 60};
    // int tree3[] = {-1, 10, 28, 15, 12, 34, 9, 8, 56};
    int tree3[] = {-1, 0, 2, 4, 6, 8, 1, 3, 5, 7, 9};

    int length1 = sizeof(tree1) / sizeof(tree1[0]);
    int length2 = sizeof(tree2) / sizeof(tree2[0]);
    int length3 = sizeof(tree3) / sizeof(tree3[0]);

    test(tree1, length1);
    test(tree2, length2);
    test(tree3, length3);

    return 0;
}

// 输出结果：

// Max Heap
// 50 60 65 72 12 23 86 98
// 1:  -1 12 23 50 60 65 72 86 98

// is min heap
// Min Heap
// 60 58 52 38 82 70 25 8
// 2:  -1 8 25 38 52 58 60 70 82

// Not Heap
// 56 12 34 28 9 8 15 10
// 3:  -1 8 9 10 12 15 28 34 56
