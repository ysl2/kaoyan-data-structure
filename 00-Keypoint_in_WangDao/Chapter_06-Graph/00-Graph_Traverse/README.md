”BFS”和“DFS非递归“的区别？

1. 使用的辅助空间结构不同：

    BFS使用的是队列

    DFS非递归使用的是栈

2. visit的时机不同：

    BFS在每次入队之前visit（包括第一个结点的一开始的visit，和遍历邻接点的入队之前的visit）

    DFS非递归在每次出栈之后visit

