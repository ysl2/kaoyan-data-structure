#include <iostream>
using namespace std;

typedef int ElemType;

void outPut(ElemType *A, int length) {
	static int i = 0;
	cout << i++ << ":  ";
	for (int i = 0; i < length; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}

void swap(ElemType *A, int i, int j) {
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void move(ElemType *A, int length) {
	int low = 0, high = length - 1;
	while (low < high) {
		// 如果是奇数，略过，继续向后遍历
		while (low < high && A[low] % 2 != 0) low++;
		// 如果是偶数，略过，继续向前遍历
		while (low < high && A[high] % 2 != 1) high--;
		// 如果找到了一个偶数low和一个奇数high，并且偶数low在奇数high前面
		if (low < high) {  
			swap(A, low, high);
			outPut(A, length);  // 测试语句，输出每一次交换后的情况
		}
		// 交换完成后，当前位置已经不需要再被下一次遍历，
		// 因此low和high分别各自移动到下一个位置
		low++, high--;  
	}
}

int main() {
	ElemType A[] = {2, 4, 6, 8, 1, 3, 5, 7, 9};
	int length = sizeof(A) / sizeof(int);
	outPut(A, length);  // 输出原始序列（第0趟）
	move(A, length);
}

// 输出结果：
// 0:  2 4 6 8 1 3 5 7 9 
// 1:  9 4 6 8 1 3 5 7 2 
// 2:  9 7 6 8 1 3 5 4 2 
// 3:  9 7 5 8 1 3 6 4 2 
// 4:  9 7 5 3 1 8 6 4 2 
