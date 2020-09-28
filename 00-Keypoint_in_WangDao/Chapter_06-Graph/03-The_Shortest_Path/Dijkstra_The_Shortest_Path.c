const int INFINITY = 9999;

void Dijkstra(MGraph g, int v0, int minDist[], int parent[]) {
// g.weight[u][v]表示边e=(u,v)的权值(不存在的情况下设为INF )
	// 初始化
    bool selected[g.vexnum];
    int v = v0;
    /*从这句开始对各数组进行初始化*/
    for(int i = 0; i < g.vexnum; i++) {
        minDist[i] = g.weight[v0][i];
        selected[i] = false;
        if(g.weight[v0][i] < INFINITY) {
            parent[i] = v0;
        } else {
            parent[i] = -1;
        }
    }
    selected[v0] = true;
    parent[v0] = -1;
    /*初始化结束*/
    /*关键操作开始*/
    // scan
    for(int i = 0; i < g.vexnum - 1; i++) {
        int min = INFINITY;
        /*这个循环每次从剩余顶点中选出一个顶点，通往这个顶点的路径在通往所有剩余顶点的路径中是长度最短的*/
        for(int j = 0; i < g.vexnum; j++) {
            if(selected[j] == false && minDist[j] < min) {
                v = j;
                min = minDist[j];
            }
        }
    }
    // add
    selected[v] = true; // 将选出的顶点并入最短路径中
    /*这个循环以刚并入的顶点作为中间点，对所有通往剩余顶点的路径进行检测*/
    // update
    for(int j = 0; j < g.vexnum; j++) {
        /*这个if语句判断顶点v的加入是否会出现通往顶点j的更短的路径，如果出现，则改变原来的路径及其长度，否则什么都不做*/
        if(selected[j] == false && minDist[v] + g.weight[v][j] < minDist[j]) {
            minDist[j] = minDist[v] + g.weight[v][j];
            parent[j] = v;
        }
    }
    /*关键操作结束*/
    /*函数结束时，minDist[]数组中存放了v0点到其余各点的最短路径长度，parent[]中存放v0点到其余各顶点的最短路径*/
}