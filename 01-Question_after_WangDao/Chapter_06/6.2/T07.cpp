// 2020-09-27
#include <stdlib.h>  // malloc函数需要用这个库
#include <iostream>  //C++的标准输入输出流库
#define maxSize 10

typedef int ElemType;
typedef struct {
    ElemType data[maxSize];
    int length;
} SqList;

int search(SqList L, ElemType value) {
    int i;
    for (i = 0; i < L.length && L.data[i] != value; i++)
        ;
    if (i != L.length && i != 0) {  // 如果找到了，并且不是第一个结点
        int temp = L.data[i - 1];
        L.data[i - 1] = L.data[i];
        L.data[i] = temp;
        return i - 1;  // 这里返回的是交换后的新位置
    } else
        return i == L.length ? -1 : i;  // 否则，返回原先的位置
}

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

int search(LinkList L, ElemType value) {
    LinkNode *pre = L, *p = L->next;
    int i = 1;
    for (; p != NULL && p->data != value; pre = pre->next, p = p->next, i++)
        ;
    if (p != NULL && pre != L) {  // 如果找到了，并且不是第一个结点
        int temp = pre->data;
        pre->data = p->data;
        p->data = temp;
        return i - 1;
    } else
        return p == NULL ? -1 : i;  // 否则，返回原先的位置
}

//------------------------------------------
#define maxSize;

typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
} SqTable;

int search(SqTable T, ElemType key) {
    int i;  // 表示下标，i ∈ [0 ~ T.length - 1]
    for (i = 0 ; i < T.length && T.data[i] != key; i++);  // 寻找i
    // 判断i是否越界。注意i = 0时没有前驱，不用交换，所以直接返回i
    // 如果i不是0，这时候才是真的错误情况，所以返回-1
    if (i <= 0 || i >= T.length) return i == 0? i : -1;
    // 交换：
    int temp = T.data[i];
    T.data[i] = T.data[i - 1];
    T.data[i - 1] = temp;

    return i - 1;  // 返回交换之后，原先的i对应的新位置i - 1
}

