#define maxSize 100

typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
} SqList;

void reverse(SqList &L) {
    for (int i = 0; i < L.length / 2; i++) {
        int temp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = temp;
    }
}

