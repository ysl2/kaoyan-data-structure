参考资料：

* 2020王道数据结构
* [数据结构&算法可视化网站](https://www.cs.usfca.edu/~galles/visualization/Algorithms.html) 

---

## 2020-09-05：[数组动态分配.c](./02-测试代码/00-数组动态分配.c)

C语言和java有非常大的不同。尤其是指针比较难把握

### 1. C语言二维数组的动态分配：

```c
int **createMatrix(int m, int n) {
// 动态申请数组并置初值为0
    int **a = (int **) malloc(sizeof(int *) * m);  // 申请列空间
    for (int i = 0; i < m; i++) {
        *(a + i) = (int *) malloc(sizeof(int) * n);  // 申请行空间
        memset(*(a + i), 0, sizeof(int) * n);  // 把整行置0
    }
    return a;
}

void test() {
    int m = 5, n = 4;
    int **a = createMatrix(m, n);
}
```

### 2. C语言二维数组的函数传入：

> 注意: 在函数中使用传参过来的二维数组（指针）进行数组取值的时候不能使用`a[i][j]`这种形式来取值。
>

在C语言的**二维**数组的函数形参声明中，不能简单地声明为`a[][]`，必须：

1. 传入`**a`，然后也传入行数列数信息`m`, `n`

此时在取值时应以`*(a + i) + j)`这种方式取（`i`, `j`为数组行下标与列下标）

```c
void outPut1(int **a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", *(*(a + i) + j));  
            // 对于传入**a的和传入a[row][column]的有不同的访问方式。
            // 传入**a的必须通过这种方式（见上面C语言文件）
        }
        printf("\n");
    }
    printf("\n");
}
```

2. 或者带上列数，即`a[][4]`这种

```c
// 这个函数有问题，在修改中
void outPut2(int a[][4], int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t", *((int *)a + i * m + j));  
        }
        printf("\n");
    }
    printf("\n");
}
```

