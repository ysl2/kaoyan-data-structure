typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
} SqTable;

int binarySearch(SqTable T, ElemType key) {
    if (T == NULL || T.length == 0) return -1;
    int left = 0, right = T.length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (T.data[mid] == key) return mid;
        if (T.data[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}