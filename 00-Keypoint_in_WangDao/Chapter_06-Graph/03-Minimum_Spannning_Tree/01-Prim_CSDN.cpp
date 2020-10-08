// 2020-09-06 第三次修订
#define maxSize 10
#define INFINITY 9999

bool selected[maxSize];  // 顶点i是否包含在集合中
int minDist[maxSize];  // 保存连接两个区域的边的最小权值
int parent[maxSize];  // 节点i的父节点

int Prim(MatrixGraph G, int v0) {  //v0取值范围：[0, G.vexnum - 1]
// G.edge[u][v]表示边e=(u,v)的权值(不存在的情况下设为INF )
    // 初始化
    for (int i = 0; i < maxSize; i++) {
        minDist[i] = INFINITY;
        selected[i] = false;
    }
    minDist[v0] = 0;
	parent[v0] = -1;
    selected[v0] = true;
    
    int sum = 0;
    int v = v0;  // 表示新加入的结点，
	// 注意：后面导致minDist和parent更新的原因就是因为新节点v的加入
    while (true) {
        // 1. 更新连接两个区域边的信息(update)
        for (int i = 0; i < G.vexnum; i++) {
            if (!selected[i] && minDist[i] > G.edge[v][i]) {
                minDist[i] = G.edge[v][i];  // 更新连接两个区域的边的最小权值
                parent[i] = v;  // 更新父节点
            }
        }
        // 2. 找连接两个区域的最小权边上的没有访问的顶点(scan)
        v = -1;
        for (int i = 0; i < G.vexnum; i++) {
            if (!selected[i] && (v == -1 || minDist[v] > minDist[i])) {
                v = i;
            }
        }
        if (v == -1) break;  // 所有的节点被访问
        // 3. 添加节点到集合(add)
        selected[v] = true;
        sum += minDist[v];
    }
    return sum;
}

---------------------------------------------------------------------------------
//原先的：
const int maxSize = 10;
const int INFINITY = 9999;

bool selected[maxSize];  // 顶点i是否包含在集合中
int minDist[maxSize];  // 保存连接两个区域的边的最小权值
int parent[maxSize];  // 节点i的父节点

int Prim(MatrixGraph G, int v0) {
// cost[u][v]表示边e=(u,v)的权值(不存在的情况下设为INF )
    // 初始化
    for (int i = 0; i < maxSize; i++) {
        minDist[i] = INFINITY;
        selected[i] = false;
    }
    minDist[v0] = 0;
    selected[v0] = true;
    int sum = 0;
    
    int v = v0;  // 表示新加入的结点，注意：后面导致mincost和parent更新的原因就是因为新节点v的加入
    while (true) {
        // 1. 更新连接两个区域边的信息(update)
        for (int i = 0; i < G.vexnum; i++) {
            if (!selected[i] && minDist[i] > G.edge[v][i]) {
                minDist[i] = G.edge[v][i];  // 更新连接两个区域的边的最小权值
                parent[i] = v;  // 更新父节点
            }
        }
        // 2. 找连接两个区域的最小权边上的没有访问的顶点(scan)
        v = -1;
        for (int i = 0; i < G.vexnum; i++) {
            if (!selected[i] && (v == -1 || minDist[v] > minDist[i])) {
                v = i;
            }
        }
        if (v == -1) break;  // 所有的节点被访问
        // 3. 添加节点到集合(add)
        selected[v] = true;
        sum += minDist[v];
    }
    return sum;
}

