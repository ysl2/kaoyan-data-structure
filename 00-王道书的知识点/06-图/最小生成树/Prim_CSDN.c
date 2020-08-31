//第二次修订：2020/08/19
const int MAX_VEX_NUM = 10;
const int INFINITY = 9999;

bool selected[MAX_VEX_NUM];  // 顶点i是否包含在集合中
int minDist[MAX_VEX_NUM];  // 保存连接两个区域的边的最小权值
int parent[MAX_VEX_NUM];  // 节点i的父节点

int Prim(MatrixGraph G, int v0) {  //v0取值范围：[0, G.vexnum - 1]
// cost[u][v]表示边e=(u,v)的权值(不存在的情况下设为INF )
    // 初始化
    for (int i = 0; i < MAX_VEX_NUM; i++) {
        minDist[i] = INFINITY;
        selected[i] = false;
    }
    minDist[v0] = 0;
    selected[v0] = true;
	parent[v0] = -1;
    int sum = 0;
    
    int v = v0;  // 表示新加入的结点，
	// 注意：后面导致mincost和parent更新的原因就是因为新节点v的加入
    while (true) {
        // 1. 更新连接两个区域边的信息(update)
        for (int i = 0; i < G.vexnum; i++) {
            if (!selected[i] && minDist[i] > G.edge[v][i]) {
                minDist[i] = G.edge[v][i];  // 更新连接两个区域的边的最小权值
                parent[i] = v;  // 更新父节点
            }
        }
        // 2. 找连接两个区域的最小权边上的没有访问的顶点(scan)
        v = -2;
        for (int i = 0; i < G.vexnum; i++) {
            if (!selected[i] && (v == -2 || minDist[v] > minDist[i])) {
                v = i;
            }
        }
        if (v == -2) break;  // 所有的节点被访问
        // 3. 添加节点到集合(add)
        selected[v] = true;
        sum += minDist[v];
    }
    return sum;
}

---------------------------------------------------------------------------------
//原先的：
const int MAX_VEX_NUM = 10;
const int INFINITY = 9999;

bool selected[MAX_VEX_NUM];  // 顶点i是否包含在集合中
int minDist[MAX_VEX_NUM];  // 保存连接两个区域的边的最小权值
int parent[MAX_VEX_NUM];  // 节点i的父节点

int Prim(MatrixGraph G, int v0) {
// cost[u][v]表示边e=(u,v)的权值(不存在的情况下设为INF )
    // 初始化
    for (int i = 0; i < MAX_VEX_NUM; i++) {
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

