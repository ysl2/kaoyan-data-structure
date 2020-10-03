#include <stdlib.h>
#define maxSize 100
#define INFINITY 9999

typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
} SqList;

bool deleteList(SqList &L, ElemType &e) {
    if (L.length == 0)
        return false;
    ElemType minValue = INFINITY;
    int minIndex = -1;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] < minValue) {
            minValue = L.data[i];
            minIndex = i;
        }
    }
    e = minValue;
    L.data[minIndex] = L.data[L.length - 1];
    L.length--;
    return true;
}
