#include <stdlib.h>
#include <stdio.h>
#define MAX_TREE_HT 10

struct MinHeapNode {
    char data;  // 输入的字符数组中的一个字符
    unsigned freq;  // 字符出现的次数
    struct MinHeapNode *left, *right;
};

struct MinHeap {  // 最小堆，作为优先队列使用
    unsigned size;  // 最小堆元素的个数
    unsigned capacity;  // 最大容量
    struct MinHeapNode **array;
};

// 初始化一个最小堆结点
struct MinHeapNode *newNode(char data, unsigned freq) {
    struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// 初始化一个容量为capacity的最小堆
struct MinHeap *newMinHeap(unsigned capacity) {
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    struct MinHeapNode **array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode));
    minHeap->array = array;
    return minHeap;
}

// swap两个堆结点
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b) {
    struct MinHeapNode *temp = *a;
    *a = *b;
    *b = temp;
}

int getLeftIndex(int index) {
    return ((index << 1) + 1);
}

// 得到右孩子结点下标。默认第一个结点下标为0
int getRightIndex(int index) {
    return ((index << 1) + 2);
}

// 调整最小堆
void adjustMinHeap(struct MinHeap *minHeap, int index) {
    int less = index;
    int left = getLeftIndex(index);
    int right = getRightIndex(index);
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[less]->freq)
        less = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[less]->freq)
        less = right;
    if (less != index) {
        swapMinHeapNode(&minHeap->array[less], &minHeap->array[index]);
        adjustMinHeap(minHeap, less);
    }
}

// 检测堆的大小是否为1
int isSizeOne(struct MinHeap *minHeap) {
    return (minHeap->size == 1);
}

// 检测是否是叶子节点
int isLeaf(struct MinHeapNode *node) {
    return !(node->left) && !(node->right);
}

void printArr(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

// 取得堆中最小的结点
struct MinHeapNode *extractMin(struct MinHeap *minHeap) {
    struct MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    adjustMinHeap(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// 构建一个最小堆
void buildMinHeap(struct MinHeap *minHeap) {
    int index = minHeap->size - 1;
    int i;
    for (i = (index - 1) / 2; i >= 0; --i)
        adjustMinHeap(minHeap, i);
}

// 创建一个容量为size的最小堆，并插入data[]中的元素到最小堆
struct MinHeap *createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap *minHeap = newMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// 构建哈夫曼树
struct MinHeapNode *buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    // 第一步：创建最小堆
    struct MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);
    // 直到最小堆中只有一个元素
    while (!isSizeOne(minHeap)) {
        // 第二步：取到最小的两个元素
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        // 第三步：根据两个最小的结点，来创建一个新的内部结点
        // ‘$’只是对内部结点的一个特殊标记，没有使用
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    // 第四步：根据两个最小的结点，来创建一个新的内部结点
    return extractMin(minHeap);
 }

// 打印哈夫曼编码
void printCodes(struct MinHeapNode *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    // 如果是叶子结点就打印
    if (isLeaf(root)) {
        printf("%c:", root->data);
        printArr(arr, top);
    }
}

void HuffmanCodes(char data[], int freq[], int size) {
    // 构建哈夫曼树
    struct MinHeapNode *root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;  // 打印构建好的哈夫曼树
    printCodes(root, arr, top);
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
    return 0;
}

// 输出结果；
// f:0
// c:100
// d:101
// a:1100
// b:1101
// e:111
