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

void insertSort(int A[], int length) {
	for (int i = 2; i < length; i++) {
		A[0] = A[i];
		int j;
		for (j = i - 1; A[0] < A[j]; j--) {  // 从后往前找待插入位置
			A[j + 1] = A[j];
		}
		A[j + 1] = A[0];
	}
}

int main() {
	ElemType A[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
	int length = sizeof(A) / sizeof(int);
	// A[0]是哨兵
	insertSort(A, length);
	outPut(A, length);  
}

// 输出结果：
// 0:  9 1 2 3 4 5 6 7 8 9 