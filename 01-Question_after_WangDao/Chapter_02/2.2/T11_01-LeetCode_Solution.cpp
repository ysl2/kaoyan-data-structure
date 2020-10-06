// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/

#include <limits.h>  // 存放常量INT_MAX 和 INT_MIN 的库
#include <iostream>
#include <vector>
using namespace std;

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
    int n = nums1.size();
    int m = nums2.size();

    if (n > m)  //保证数组1一定最短 //为了加快速度 对长度短的进行二分
        return findMedianSortedArrays(nums2, nums1);

    int LMax1 = 0, LMax2 = 0, RMin1 = 0, RMin2 = 0, c1, c2, low = 0, high = n;
    while (low <= high) {
        // c1 = (high + low) / 2 + 1;
        c1 = (high + low) / 2;
        c2 = (m + n) / 2 - c1;

        LMax1 = (c1 == 0) ? INT_MIN : nums1[c1 - 1];
        RMin1 = (c1 == n) ? INT_MAX : nums1[c1];
        LMax2 = (c2 == 0) ? INT_MIN : nums2[c2 - 1];
        RMin2 = (c2 == m) ? INT_MAX : nums2[c2];

        if (LMax1 > RMin2)
            high = c1 - 1;
        else if (LMax2 > RMin1)
            low = c1 + 1;
        else
            break;
    }

    if ((m + n) % 2)
        return min(RMin1, RMin2);
    else
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
