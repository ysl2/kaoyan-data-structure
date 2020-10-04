# 数组中点

**代码规范：**

**如果求数组中点索引值，变量用mid**

**如果求数组中间距离，变量用half**

### 1.求数组中点的索引值

```c
mid = (left + right) / 2

mid = left + (right - left) / 2
```

二者等价，但是建议用后者：

```c
代码中 left + (right - left) / 2 就和 (left + right) / 2 的结果相同，

但是有效防止了 left 和 right 太大直接相加导致溢出
```

### 2.求数组的中间距离

```c
i < (right - left + 1) / 2
```

或

```c
i <= (right - left) / 2
```

二者只差了一个等于号。

如果是第一种情况，将不能取到中间，否则会越界

第二种情况，必须取到等号，否则会漏掉一个值

### 补充：

数组的中点索引值和数组的中间距离是不同的

中间距离是指距离左端点为数组长度一半的距离，不是索引

而中点索引值，是中点的数组下标值

### 参考：

[https://www.cnblogs.com/Howe-Young/p/9340702.html](https://www.cnblogs.com/Howe-Young/p/9340702.html)

[https://www.zhihu.com/question/384114264](https://www.zhihu.com/question/384114264)