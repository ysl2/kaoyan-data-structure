#define maxSize 100
#define INFINITY 9999

bool visited[maxSize];
int time;
int finishTime[maxSize];
// 将经过DFS后的finishTime数组中的值从大到小排序，就是拓扑序列

void DFSTraverse(Graph G) {
    for (int i = 0; i < maxSize; i++) {
        visited[i] = false;
        finishTime = INFINITY;  // 将初值置为无穷大
        // INFINITY为无穷大，这里假设INFINITY表示顶点不存在
        // 当输出结果遍历到INFINITY时，
        // 说明从这个结点开始（包括此结点）往后已经不存在了，就停止输出
    }
    time = 0;
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            DFS(G, i);
        }
    }
}

void DFS(Graph G, int v0) {
    visit(v0);
    visited[v0] = true;
    for (int w = FirstNeighbor(G, v0); w >= 0; w = NextNeighbor(G, v0, w)) {
        if (!visited[w]) {
            DFS(G, w);
        }
    }
    time++;
    finishTime[v0] = time;
}

