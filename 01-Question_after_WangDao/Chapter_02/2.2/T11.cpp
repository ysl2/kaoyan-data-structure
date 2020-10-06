// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/

#include <limits.h>  // 存放常量INT_MAX 和 INT_MIN 的库
#include <iostream>
#include <vector>
using namespace std;

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();
    //保证数组1一定最短
    if (n > m)
        return findMedianSortedArrays(nums2, nums1);

    // ci 为第i个数组的割,比如c1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
    int LMax1, LMax2, RMin1, RMin2, c1, c2, low = 0, high = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n长度

    //二分
    while (low <= high) {
        c1 = (low + high) / 2;  //c1是二分的结果
        c2 = m + n - c1;

        LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
        RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
        LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
        RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

        if (LMax1 > RMin2)
            high = c1 - 1;
        else if (LMax2 > RMin1)
            low = c1 + 1;
        else
            break;
    }
    return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
}

int main(int argc, char *argv[]) {
    vector<int> nums1 = {2, 3, 5};
    vector<int> nums2 = {1, 4, 7, 9};

    double ret = findMedianSortedArrays(nums1, nums2);
    cout << ret << endl;
    return 0;
}

// 输出结果：
// 4

// ---------------------------------------------------------------------------------
int middle(int A[], int B[], int n) {
    int start1 = 0, end1 = n - 1, mid1,
        start2 = 0, end2 = n - 1, mid2;
    while (start1 != end1 || start2 != end2) {
        mid1 = (start1 + end1) / 2;
        mid2 = (start2 + end2) / 2;
        if (A[mid1] == B[mid2]) {
            return A[mid1];
        }
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
