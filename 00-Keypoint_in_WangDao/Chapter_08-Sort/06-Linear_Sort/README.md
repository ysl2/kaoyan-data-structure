# 线性排序

包括桶排序、基数排序、计数排序

## 箱子排序和基数排序的不同点

### 箱子排序

就是桶排序

### 基数排序

辅助空间：链队

#### 两种方式

* 低位优先：LSD

* 高位优先：MSD

#### 例子

这个例子是低位优先

分配和收集：按照先进先出原则（链队），头插。

## 计数排序

计数排序只能用在数据范围不大的场景中，如果数据范围k比要排序的数据n大很多，就不适合用计数排序了

计数排序只能给非负整数排序，如果要排序的数据是其他类型的，要将其在不改变相对大小的情况下，转化为非负整数