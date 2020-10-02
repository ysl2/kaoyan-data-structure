typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
} SqTable;

int search(SqTable T, ElemType key) {
    T.data[0] = key;
    int i;
    for (i = T.length; T.data[i] != key; i--);
    return i;
}

