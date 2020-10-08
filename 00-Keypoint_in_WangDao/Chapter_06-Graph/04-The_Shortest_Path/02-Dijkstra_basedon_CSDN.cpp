const int MAX_VEX_NUM = 10;
const int INFINITY = 9999;

bool selected[MAX_VEX_NUM];
int minDist[MAX_VEX_NUM];
int parent[MAX_VEX_NUM];

void Dijkstra(MatrixGraph G, int v0) {
// G.weight[u][v]表示边e=(u, v)的权值（不存在的情况下设为INFINITY）
    // 初始化
    for (int i = 0; i < G.vexnum; i++) {
        selected[i] = false;
        minDist[i] = INFINITY;
    }
    selected[v0] = true;
    minDist[v0] = 0;
    parent[v0] = -1;
    
    int v = v0;  // 表示新加入的结点。
    // 注意：后面导致minDist和parent更新的原因就是因为新节点v的加入
    while (true) {
        // 1. 更新连接两个区域边的信息(update)
        for (int i = 0; i < G.vexnum; i++) {
            if (!selected[i] && minDist[i] > minDist[v] + G.weight[v][i]) {
                minDist[i] = minDist[v] + G.weight[v][i];  // 更新到该顶点的最短路径长度
                parent[i] = v;  // 更新父节点
            }
        }
        // 2. 找连接两个区域的最小权边上的没有访问的顶点(scan)
        v = -2;
        for (int i = 0; i < G.vexnum; i++) {
            if (!selected[i] && (v == -2 || minDist[i] < minDist[v])) {
                v = i;
            }
        }
        if (v == -2) break;  // 所有的结点被访问
        // 3. 添加节点到集合(add)
        selected[v] = true;
    }
    
}

