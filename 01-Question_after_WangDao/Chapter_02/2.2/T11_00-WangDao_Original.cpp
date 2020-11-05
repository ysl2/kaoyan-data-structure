#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
} SqList;

void outPutList(SqList L) {
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
}

SqList initList(int arr[], int length) {
    SqList L;
    L.length = length;
    L.data = (ElemType *)malloc(sizeof(ElemType) * L.length);
    for (int i = 0; i < length; i++)
        L.data[i] = arr[i];
    return L;
}

// 根据王道书上的算法进行了代码可读性优化
double getMid(SqList A, SqList B) {
    int low1 = 0, high1 = A.length - 1, mid1,
        low2 = 0, high2 = B.length - 1, mid2;
    while (low1 != high1 || low2 != high2) {
        mid1 = (low1 + high1) / 2;
        mid2 = (low2 + high2) / 2;
        if (A.data[mid1] == B.data[mid2])
            return A.data[mid1];
        if (A.data[mid1] < B.data[mid2]) {
            low1 = ((low1 + high1) % 2 == 0) ? mid1 : mid1 + 1;
            high2 = mid2;
        } else {
            low2 = ((low2 + high2) % 2 == 0) ? mid2 : mid2 + 1;
            high1 = mid1;
        }
    }
    return A.data[low1] < B.data[low2] ? A.data[low1] : B.data[low2];
}

void test(int arr1[], int length1, int arr2[], int length2) {
    SqList A = initList(arr1, length1);
    SqList B = initList(arr2, length2);
    cout << getMid(A, B) << endl;
}

int main() {
    ElemType A[] = {1, 3, 5, 7, 9};
    ElemType B[] = {2, 4, 6, 8, 10};

    int length1 = sizeof(A) / sizeof(int);
    int length2 = sizeof(B) / sizeof(int);

    test(A, length1, B, length2);
    return 0;
}

// 输出结果：
// 5


// 下面的全部都有错误
// //-----------------------------------------------------------------------------
// int middle(int A[], int B[], int n) {
//     int low1 = 0, high1 = n - 1, mid1,
//         low2 = 0, high2 = n - 1, mid2;
//     while (low1 != high1 || low2 != high2) {
//         mid1 = (low1 + high1) / 2;
//         mid2 = (low2 + high2) / 2;
//         if (A[mid1] == B[mid2])
//             return A[mid1];
//         if (A[mid1] < B[mid2]) {
//             low1 = ((low1 + high1) % 2 == 0) ? mid1 : mid1 + 1;
//             high2 = mid2;
//         } else {
//             low2 = ((low2 + high2) % 2 == 0) ? mid2 : mid2 + 1;
//             high1 = mid1;
//         }
//     }
//     return A[low1] < B[low2] ? A[low1] : B[low2];
// }

// // 时间复杂度：O(log_2(n))
// // 空间复杂度：O(1)
// // ---------------------------------------------------------------------------------
// int m_Search(int A[], int B[], int n) {
//     int start1 = 0, end1 = n - 1, middle1,
//         start2 = 0, end2 = n - 1, middle2;
//     //分别表示序列A和B的首位数、末位数和中位数
//     while (start1 != end1 || start2 != end2) {
//         middle1 = (start1 + end1) / 2;
//         middle2 = (start2 + end2) / 2;
//         if (A[middle1] == B[middle2]) {
//             return A[middle1];  // 满足条件(1)
//         }
//         if (A[middle1] < B[middle2]) {  // 满足条件(2)
//             // if ((start1 + end1) % 2 == 0) {  // 若元素个数为奇数
//             //     start1 = middle1;  // 舍弃A中间点以前的部分且保留中间点
//             // } else {  //元素个数为偶数
//             //     start1 = middle1 + 1;  //舍弃A中间点及中间点以前的部分
//             // }
//             start1 = ((start1 + end1) % 2 == 0) ? middle1 : middle1 + 1;
//             end2 = middle2;  //舍弃B中间点以后部分且保留中间点
//         } else {             // 满足条件(3)
//             // if((start2 + end2) % 2 == 0) {  //若元素个数为奇数
//             //     start2 = middle2;  // 舍弃B中间点以前的部分且保留中间点
//             // } else {
//             //     start2 = middle2 + 1;  // 舍弃B中间点及中间点以前的的部分
//             // }
//             start2 = ((start2 + end2) % 2 == 0) ? middle2 : middle2 + 1;
//             end1 = middle1;  // 舍弃A中间点以后的部分且保留中间点
//         }
//     }
//     return A[start1] < B[start2] ? A[start1] : B[start2];
// }

// // 时间复杂度：O(log_2(n))
// // 空间复杂度：O(1)
