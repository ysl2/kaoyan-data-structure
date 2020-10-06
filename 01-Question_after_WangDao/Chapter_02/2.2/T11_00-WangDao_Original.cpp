int middle(int A[], int B[], int n) {
    int start1 = 0, end1 = n - 1, mid1,
        start2 = 0, end2 = n - 1, mid2;
    while (start1 != end1 || start2 != end2) {
        mid1 = (start1 + end1) / 2;
        mid2 = (start2 + end2) / 2;
        if (A[mid1] == B[mid2])
            return A[mid1];
        if (A[mid1] < B[mid2]) {
            start1 = ((start1 + end1) % 2 == 0) ? mid1 : mid1 + 1;
            end2 = mid2;
        } else {
            start2 = ((start2 + end2) % 2 == 0) ? mid2 : mid2 + 1;
            end1 = mid1;
        }
    }
    return A[start1] < B[start2] ? A[start1] : B[start2];
}

// 时间复杂度：O(log_2(n))
// 空间复杂度：O(1)
// ---------------------------------------------------------------------------------
int m_Search(int A[], int B[], int n) {
    int start1 = 0, end1 = n - 1, middle1,
        start2 = 0, end2 = n - 1, middle2;
    //分别表示序列A和B的首位数、末位数和中位数
    while (start1 != end1 || start2 != end2) {
        middle1 = (start1 + end1) / 2;
        middle2 = (start2 + end2) / 2;
        if (A[middle1] == B[middle2]) {
            return A[middle1];  // 满足条件(1)
        }
        if (A[middle1] < B[middle2]) {  // 满足条件(2)
            // if ((start1 + end1) % 2 == 0) {  // 若元素个数为奇数
            //     start1 = middle1;  // 舍弃A中间点以前的部分且保留中间点
            // } else {  //元素个数为偶数
            //     start1 = middle1 + 1;  //舍弃A中间点及中间点以前的部分
            // }
            start1 = ((start1 + end1) % 2 == 0) ? middle1 : middle1 + 1;
            end2 = middle2;  //舍弃B中间点以后部分且保留中间点
        } else {             // 满足条件(3)
            // if((start2 + end2) % 2 == 0) {  //若元素个数为奇数
            //     start2 = middle2;  // 舍弃B中间点以前的部分且保留中间点
            // } else {
            //     start2 = middle2 + 1;  // 舍弃B中间点及中间点以前的的部分
            // }
            start2 = ((start2 + end2) % 2 == 0) ? middle2 : middle2 + 1;
            end1 = middle1;  // 舍弃A中间点以后的部分且保留中间点
        }
    }
    return A[start1] < B[start2] ? A[start1] : B[start2];
}

// 时间复杂度：O(log_2(n))
// 空间复杂度：O(1)
