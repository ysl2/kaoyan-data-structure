# 快速排序

## 快速排序与归并排序的区别

快速排序的处理过程是由上到下的，归并排序的处理过程的从下到上的

快速排序是原地排序，归并排序不是原地排序

快速排序不稳定，归并排序稳定

## 快速排序优化

### 三数取中法

从区间的首、尾、中间分别取出一个数，然后对比大小，取这三个数的中间值作为分区点。这样每隔某个固定长度，取数据出来比较，将中间值作为分区点的分区算法，肯定要比单纯取某一个数据更好。但是，如果要排序的数组比较大，那“三数取中”可能就不够了，可能要“五数取中”或“十数取中”。

### 随机法

随机选择一个元素作为分区点。这种方法不能保证每次分区点都选的比较好。但是从概率学角度来看，也不大可能出现每次分区点都选的很差的情况。所以平均情况下，这样选的分区点是比较好的。时间复杂度退化为最糟糕的$O(n^2)$的情况出现的可能性不大