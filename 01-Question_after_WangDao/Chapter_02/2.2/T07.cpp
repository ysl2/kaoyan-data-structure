#include <stddef.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
	int maxSize;
} SqList;

bool merge(SqList A, SqList B, SqList &C) {
	if (A.length + B.length > C.maxSize) {
		return false;
	}
	int i = 0, j = 0, k = 0;
	while (i < A.length && j < B.length) {
		if (A.data[i] <= B.data[j]) {
			C.data[k++] = A.data[i++];
		} else {
			C.data[k++] = B.data[j++];
		}
	}
	while (i < A.length) {
		C.data[k++] = A.data[i++];
	}
	while (j < B.length) {
		C.data[k++] = B.data[j++];
	}
	C.length = k;
	return true;
}