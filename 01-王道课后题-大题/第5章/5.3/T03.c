#define maxSize 100
void DFS(AdjacentList &G, int v0) {
    // 初始化
    Stack S;
    InitStack(S);
    bool visited[G.vexnum];
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false;
    }
    Push(S, v0);
    visited[v0] = true;
    // 循环
    while (!StackEmpty(S)) {
        int v;
        Pop(S, v);
        visit(v);
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
            if (!visited[w]) {
                Push(S, w);
                visited[w] = true;
            }
        }
    }
}




