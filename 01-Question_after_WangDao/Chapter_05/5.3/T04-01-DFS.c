bool visited[G.vexnum];  // 全局数组

// 题目要求用i, j，但是i占了我的迭代器变量了，不舒服。所以我给改成a, b了
bool test(AdjacentList &G, int a, int b) {
    // 初始化数组
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false;
    }
    return DFS(G, a, b);  // 开始寻找边
}

bool DFS(AdjacentList &G, int a, int b) {
    if (a == b) {
        return true;
    }
    visited[a] = true;
    for (int w = FirstNeighbor(G, a); w >= 0; w = NextNeighbor(G, a, w)) {
        if (!visited[w] && DFS(G, w, b)) {
            return true;
        }
    }
    return false;
}
