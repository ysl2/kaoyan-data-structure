bool visited[MAX_VEX_NUM];

void DFSTraverse(Grapg G) {
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            DFS(G, i);
        }
    }
}
void DFS(Graph G, int v0) {
    visited[v0] = true;
    int v = v0;
    for (int w = FirstNeighbor(G, v); w >= 0; w = NexiNeighbor(G, v, w)) {
        if (!visited[w]) {
            DFS(G, w);
        }
    }
    print(v);
}

