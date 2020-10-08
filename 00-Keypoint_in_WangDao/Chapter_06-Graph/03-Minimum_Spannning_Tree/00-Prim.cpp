void Prim(MGraph g, int v0, int &sum) {
	int lowcost[maxSize], vset[maxSize], v;
	int i, j, k, min;
	v = v0;
	for(i = 0; i < g.n; ++i) {
		lowcost[i] = g.edges[v0][i];
		vset[i] = 0;
	}
	vset[v0] = 1; //将v0并入树中
	sum = 0; //sum清零用来累计树的权值
	for(i = 0; i < g.n-1; ++i) {
		min = INF; //INF是一个已经定义的比图中所有边权值都大的常量
		/*下面这个循环用于选出候选边中的最小者*/
		for(j = 0; j < g.n; ++j) {
			if(vset[j] == 0 && lowcost[j] < min) { 
				//选出当前生成树到其余顶点最短边中的一条（注意这里两个最短的含义）
				min = lowcost[j];
				k = j;
			}
		}
		vset[k] = 1;
		v = k;
		sum += min; //这里用sum记录了最小生成树的权值
		/*下面这个循环以刚并入的顶点v为媒介更新侯选边*/
		for(j = 0; j < g.n; ++j) {
			if(vset[j] == 0 && g.edges[v][j] < lowcost[j]) { //此处对应算法执行过程中的第（2）步
				lowcost[j] = g.edges[v][j];
			}
		}
	}
}


