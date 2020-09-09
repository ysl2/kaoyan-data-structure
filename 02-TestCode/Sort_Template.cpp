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



int main() {
	ElemType A[] = {2, 4, 6, 8, 1, 3, 5, 7, 9};
	int length = sizeof(A) / sizeof(int);
	outPut(A, length);  // 输出原始序列（第0趟）

}

// 输出结果：
