// 主元素：大于数组的一半的数
// 摩尔投票法：
// 建立统计变量，然后依次遍历，只要是，变量+1，只要不是，
// 如果统计变量大于0，就减1; 如果统计变量小于0，换别的元素继续统计。
// 然后再遍历一遍看看筛出来的这个数到底是不是主元素。
// （如果变量小于等于0，说明压根没筛出来，就直接等着返回就行了，不需要再遍历）

#include <iostream>
using namespace std;

int majority(int A[], int length) {
    int count = 1;
    int mainElement = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] == mainElement)
            count++;
        else {  // 如果不相等
            if (count > 0)
                count--;
            else {  //count此时等于0
                mainElement = A[i];
                count = 1;
            }
        }
    }

    if (count > 0) {
        count = 0;
        for (int i = 0; i < length; i++)
            if (A[i] == mainElement)
                count++;
    }

    return count > length / 2 ? mainElement : -1;
}

int main() {
    int arr1[] = {0, 5, 5, 3, 5, 7, 5, 5};
    int arr2[] = {0, 5, 5, 3, 5, 1, 5, 7};

    int length1 = sizeof(arr1) / sizeof(int);
    int length2 = sizeof(arr2) / sizeof(int);

    cout << majority(arr1, length1) << endl;
    cout << majority(arr2, length2) << endl;
}

// 运行结果：
// 5
// -1
