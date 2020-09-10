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

int kthElem(int *A, int low, int high, int k) {
	int pivot = A[low];
	int _LOW = low;
	int _HIGH = high;
	while (low < high) {
		while (low < high && A[high] >= pivot)
			high--;
		A[low] = A[high];
		while (low < high && A[low] <= pivot)
			low++;
		A[high] = A[low];
	}
	A[low] = pivot;
	if (low == k)
		return A[low];
	else if (low > k)
		return kthElem(A, _LOW, low - 1, k);
	else
		return kthElem(A, low + 1, _HIGH, k - low);
}

int main() {
	ElemType A[] = {2, 4, 6, 8, 1, 3, 5, 7, 9};
	int length = sizeof(A) / sizeof(int);
	int answer = kthElem(A, 0, length - 1, 4);
	outPut(A, length);  
	cout << answer << endl;
}

// 输出结果：
// 0:  1 2 3 4 5 6 8 7 9
// 4