bool isTree(Graph &G){
    bool visited[G.vexnum];
    for(int i = 0; i < G.vexnum; i++)  // 初始化数组
        visited[i] = false;
    int Vnum = 0, Enum = 0;
    DFS(G, 1, Vnum, Enum, visited);
    return Vnum == G.vexnum && Enum == 2 * (G.vexnum - 1);
    // 返回true的条件：（图是树的条件）
    // 1. 遍历一次统计的顶点数等于整个图的顶点数，即图是连通的
    // 2. 遍历一次能得到n - 1条边。（如果n个顶点的图是树，则其边数等于n - 1）
    // 在第二条中，因为是无向图，所以每条边走了两遍。因此最终应该乘2
    // 无论是邻接矩阵还是邻接表，只要是无向图，那么存储的边数都是两倍的
}
 
void DFS(Graph &G, int v, int &Vnum, int &Enum, int visited[]) {
    Vnum++;  // 相当于基本DFS里的visit(v);
    visited[v] = true;
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
        Enum++;
        if(!visited[w]) {
            DFS(G, w, Vnum, Enum, visited);
        }
    }
}

