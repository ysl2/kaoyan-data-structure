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

void bidBubbleSort(ElemType *A, int length) {
	int low = 0, high = length - 1;
	bool flag = true;
	while (low < high && flag == true) {
		flag = false;
		for (int i = low; i < high; i++) {
			if (A[i] > A[i + 1]) {
				swap(A, i, i + 1);
				flag = true;
			}
		}
		high--;
		outPut(A, length);  // 测试语句
		for (int i = high; i > low; i--) {
			if (A[i] < A[i - 1]) {
				swap(A, i, i - 1);
				flag = true;
			}
		}
		low++;
		outPut(A, length);  // 测试语句
	}
}

int main() {
	ElemType A[] = {6, 5, 4, 3, 2, 1};
	int length = sizeof(A) / sizeof(int);
	outPut(A, length);  // 输出原始序列（第0趟）
	bidBubbleSort(A, length);
}

// 输出结果:
// 0:  6 5 4 3 2 1 
// 1:  5 4 3 2 1 6 
// 2:  1 5 4 3 2 6 
// 3:  1 4 3 2 5 6 
// 4:  1 2 4 3 5 6 
// 5:  1 2 3 4 5 6 
// 6:  1 2 3 4 5 6 

