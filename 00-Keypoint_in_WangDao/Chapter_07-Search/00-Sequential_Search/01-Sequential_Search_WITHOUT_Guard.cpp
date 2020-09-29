typedef struct {
    ElemType *data;
    int length;
} SqTable;

int search(SqTable T, ElemType key) {
    int i;
    for (i = 0; i < T.length && T.data[i] != key; i++);
    return i == T.length? -1 : i;
}

