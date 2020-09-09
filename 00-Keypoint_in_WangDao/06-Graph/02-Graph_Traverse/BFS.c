bool visited[maxSize];

void BFSTraverse(Graph G) {
    InitQueue(Q);
    for (int i = 0; i < maxSize; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            BFS(G, i);
        }
    }
}

void BFS(Graph G, int v0) {
    visit(v0);
    visited[v0] = true;
    EnQueue(Q, v0);
    int v;
    while (!QueueEmpty(Q)) {
        DeQueue(Q, v);
        while (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
            if (!visited[w]) {
                visit[w];
                visited[w] = true;
                EnQueue(Q, w);
            }
        }
    }
}

