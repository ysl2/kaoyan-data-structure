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

int serPartition(int A[], int length) {
	int _LOW = 0, _HIGH = length - 1;  // 保存边界值
	int low = _LOW, high = _HIGH;
	int k = length / 2;
	int s1 = 0, s2 = 0;
	bool flag = true;
	int pivot;
	while (flag == true) {  
		pivot = A[low];  // 选择枢轴
		while (low < high) {  // 基于枢轴对数据进行划分
			while (low < high && A[high] >= pivot)
				high--;
			if (low != high)
				A[low] = A[high];
			while (low < high && A[low] <= pivot)
				low++;
			if (low != high)
				A[high] = A[low];
		}
		A[low] = pivot;
		if (low == k - 1)
			flag = false;
		else {
			if (low < k - 1) {
				_LOW = ++low;
				high = _HIGH;
			} else {
				_HIGH = --high;
				low = _LOW;
			}
		}
	}
	for (int i = 0; i < k; i++)
		s1 += A[i];
	for (int i = k; i < length; i++)
		s2 += A[i];
	return s2 - s1;
}

int main() {
	ElemType A[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
	int length = sizeof(A) / sizeof(int);
	int answer = serPartition(A, length);
	outPut(A, length);
	cout << answer;
}

// 输出结果：
// 0:  0 1 2 3 4 5 6 8 7 9
// 25