bool visited[G.vexnum];  // 全局数组

// 题目要求用i, j，但是i占了我的迭代器变量了，不舒服。所以我给改成a, b了
// bool test(AdjacentList &G, int a, int b) {
//     // 初始化数组
//     for (int i = 0; i < G.vexnum; i++) {
//         visited[i] = false;
//     }
//     return BFS(G, a, b);  // 开始寻找边
// }

bool BFS(AdjacentList &G, int a, int b) {
    InitQueue(Q);
    EnQueue(Q, a);
    while (!QueueEmpty(Q)) {
        int v;
        DeQueue(Q, v);
        visited[v] = true;
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
            if (w == b)
                return true;
            if (!visited[w])
                EnQueue(Q, w);
        }
    }
    return false;
}
// 书上没有指定w的类型，但是根据他写的代码，应该是把w作为结点类型，而不是int类型
// 这样的话，需要用的时候还要提取结点的index值，不仅容易误导，还麻烦了一小步

// 我这里写的是把w作为int类型了，
// 也就是在FirstNeighbor和NextNeighbor内部，已经获取到了相应的index值
// 参考T04-00，“邻接表的结构体定义”
