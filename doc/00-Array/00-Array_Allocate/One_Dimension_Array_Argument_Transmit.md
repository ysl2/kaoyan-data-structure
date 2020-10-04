# 一维数组的参数传递

> 总结：
>
> 对于静态方式（`a[]`）定义数组和动态方式（`*a`）定义数组，传入时都可以用`*a`作声明。但是**只有动态方式（`*a`）可以用 `*&a`**
>
> 当数组以动态方式（`*a`）定义时，对于`*&a`方式的传入，会真实改变`a`数组的值。而对于`*a`则只会作为形参传入，不真实改变。当数组以静态方式（`a[]`）定义时，只能以`*a`方式传入，并且**会**真实改变。
>
> 对于char类型定义的数组，只能通过`char arr[]`方式定义，不能通过`char *arr`方式定义
>
> 为了避免误导，以下都是只给出了正确方式 。对于错误方式，我仅用语言形容。

---

## 一、指针传入与数组传入的区别

以下默认在**参数声明**中，`*a`与`a[]`效果等价，因为实际传入的依然是`*a`。不再赘述。

### 1. A数组以<u>指针</u>方式静态初始化，传入ranks的方式：

```c++
void ranks(int *a) {
	// ..
}

int main() {
	int *A = new int[]{1, 2, 3};
    int length = 3;  // 注意，这里不能用sizeof(A)/sizeof(int)，原因是A现在只是一个头指针。
    ranks(A, length);
}
```

或者：

```c++
void ranks(int *&a) {  // 注意与上面的不同，这里有&。先不要管&，后面再说
	// ..
}

int main() {
	int *A = new int[]{1, 2, 3};
    int length = 3;  // 注意，这里不能用sizeof(A)/sizeof(int)，原因是A现在只是一个头指针。
    ranks(A, length);
}
```

对于指针方式，可以在ranks的函数声明中加上&，也可以不加。先不要管&，后面再说

### 2. A数组以<u>数组</u>方式静态初始化，传入ranks的方式：

```c++
void ranks(int *a) {
    // ..
}

int main() {
	ElemType A[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = sizeof(A) / sizeof(int);  // 这里可以用。注意和上面的区别
    ranks(A, length);
}
```

**而此时如果加上了&，则会报错：**

```
SDU_Count_Sort.cpp:55:5: error: no matching function for call to 'ranks'
    ranks(A, length, r);
    ^~~~~
SDU_Count_Sort.cpp:23:6: note: candidate template ignored: could not match 'T *' against 'ElemType [10]'
void ranks(T *&a, int length, int *&r) {
     ^
1 error generated.
```

> 小结：对于指针方式定义数组和数组方式定义数组，传入时都可以用*a作声明。但是只有指针方式可以用 *&a

---

## 二、参数声明是`*&a`和`*a`的区别（&对结果产生的影响）

### 1.参数声明是`*&a`

```c++
void ranks(int *&a) {
    // ..
}
int main() {
	int *A = new int[]{0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = 10;  // 注意，这里不能用sizeof(A)/sizeof(int)，原因是A现在只是一个头指针。
    ranks(A, length);  // 此处ranks会对真实的a造成影响
}
```

### 2.参数声明是*a

```c++
void ranks(int *a) {
    // ..
}
int main() {
	int *A = new int[]{0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int length = 10;  // 注意，这里不能用sizeof(A)/sizeof(int)，原因是A现在只是一个头指针。
    ranks(A, length);  // 此处ranks不会产生影响
}
```

> 小结：
>
> 当数组以动态方式（`*a`）定义时，对于`*&a`方式的传入，会真实改变`a`数组的值。而对于`*a`则只会作为形参传入，不真实改变。
>
> 当数组以静态方式（`a[]`）定义时，只能以*a方式传入，并且会真实改变。

---

## 补充

```c++
正确方式：T *u = new T[length];
错误方式：T u[] = new T[length];  // 这是错误方式！

正确方式：delete[] u;
错误方式：delete u[];   delete *u;  // 这是错误方式！
```



```c++
对于char类型，只能以下面的方式定义：
char arr[] = {'a', 'b'};

下面这种定义方式错误：
char *arr = {'a', 'b'};  // 这种方式是错误的
```

