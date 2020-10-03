#define maxSize 100
#define INFINITY 9999

typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
} SqList;

bool deleteList(SqList &L, ElemType s, ElemType t) {
    if (L.length == 0 || s >= t)
        return false;
    int i = 0;
    for (; i < L.length && L.data[i] < s; i++)
        ;
    if (i == L.length)
        return false;
    int j = i;
    for (; j < L.length && L.data[j] <= t; j++)
        ;
    for (; j < L.length; i++, j++)
        L.data[i] = L.data[j];
    L.length = i;
    return true;
}
