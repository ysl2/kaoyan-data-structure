#define maxSize;

typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
} SqTable;

// 代码中 left + (right - left) / 2 和 (left + right) / 2 的结果相同，
// 但是有效防止了 left 和 right 太大直接相加导致溢出
int binarySearch(SqTable T, ElemType key, int left, int right) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (T.data[mid] == key) return mid;
    if (T.data[mid] < key) return binarySearch(T, key, mid + 1, right);
    return binarySearch(T, key, left, mid - 1);
}

// #include <stdio.h>

// int binarySearch(int *a, int key, int left, int right) {
//     if (left > right) return -1;
//     int mid = left + (right - left) / 2;
//     if (a[mid] == key) return mid;
//     if (a[mid] < key) return binarySearch(a, key, mid + 1, right);
//     return binarySearch(a, key, left, mid - 1);
// }

// void test() {
//     int n = 10;
//     int target = 14;
//     int a[n];
//     for (int i = 0; i < n; i++) {
//         a[i] = i + 10;
//     }
//     printf("%d", binarySearch(a, target, 0, n - 1));
// }

// int main() {
//     test();
//     return 0;
// }

