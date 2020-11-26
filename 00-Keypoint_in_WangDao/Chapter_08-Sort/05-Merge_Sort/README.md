# 归并排序

## 归并排序的时间复杂度

归并排序的时间复杂度与原始序列无关，任何情况下都是$O(n\log{n})$

但是归并排序应用不如快速排序应用广泛的原因是：归并排序不是原地排序

## 归并排序的空间复杂度

尽管每次合并操作都需要申请额外的内存空间，但在合并完成之后，临时开辟的内存空间就被释放掉了。

在任意时刻，CPU只会有一个函数在执行，也就是只会有一个临时的内存空间在使用。临时内存空间最大也不会超过n个数据的大小，所以空间复杂度是$O(n)$