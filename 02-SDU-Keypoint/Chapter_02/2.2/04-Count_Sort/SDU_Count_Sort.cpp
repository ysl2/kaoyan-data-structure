#include <string.h>
#include <iostream>
// using namespace std;

typedef int ElemType;

void outPut(ElemType *A, int length) {
    static int i = 0;
    std::cout << i++ << ":  ";
    for (int i = 0; i < length; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

void swap(ElemType *A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

template <class T>
void ranks(T a[], int length, int *&r) {
// 注意有没有&是不一样的。如果想在ranks里面初始化main里面定义的r数组，就要带着&。否则只是形参传入，出了函数之后，r依然是NULL
// 而对于a数组，如果前面带了&，就会直接报错
    r = new int[length];
    memset(r, 0, sizeof(int) * length);
    for (int i = 1; i < length; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] <= a[i])
                r[i]++;
            else
                r[j]++;
        }
    }
}
template <class T>
void countSort(T a[], int length, int *r) {
    T *u = new T[length];
    for (int i = 0; i < length; i++) {
        u[r[i]] = a[i];
    }
    for (int i = 0; i < length; i++) {
        a[i] = u[i];
    }
    delete[] u;
}

int main() {
    // ElemType *A = new int[]{0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    // int length = 10;
    ElemType A[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(A) / sizeof(int);
    int *r = NULL;
    ranks(A, length, r);
    countSort(A, length, r);
    outPut(A, length);
    return 0;
}

// rank是系统结构体定义，一旦用了std，就会和你自己定义的rank名字发生冲突。
// 有两种解决方案：1: 换个名字。2: 不要使用using namespace std，而是用std::代替
// 参考链接：https://stackoverflow.com/questions/50902596/reference-to-rank-is-ambiguous
// Compile your code with -std=c++03 mode or change rank name because since c++11 there is rank struct in library - rank. You can remove using namespace std; line to avoid this error, but then you need to add std:: prefix before every call of standard library function i.e. std::sort.

// 输出结果：
// 0:  0 1 2 3 4 5 6 7 8 9
