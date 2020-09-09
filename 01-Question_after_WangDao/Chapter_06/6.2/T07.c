#define maxSize;

typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
} SqTable;

int search(SqTable T, ElemType key) {
    int i;  // 表示下标，i ∈ [0 ~ T.length - 1]
    for (i = 0 ; i < T.length && T.data[i] != key; i++);  // 寻找i
    // 判断i是否越界。注意i = 0时没有前驱，不用交换，所以直接返回i
    // 如果i不是0，这时候才是真的错误情况，所以返回-1
    if (i <= 0 || i >= T.length) return i == 0? i : -1;
    // 交换：
    int temp = T.data[i];
    T.data[i] = T.data[i - 1];
    T.data[i - 1] = temp;

    return i - 1;  // 返回交换之后，原先的i对应的新位置i - 1
}

