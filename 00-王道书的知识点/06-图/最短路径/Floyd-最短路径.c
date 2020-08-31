const int INFINITY = 9999;

void createArray(int **a, int m, int n) {  // 创建数组
    for (int i = 0; i < m; i++) {
        *(a + i) = (int *) malloc(sizeof(int *) * n);
        memset(*(a + i), 0, sizeof(int) * n);
    }
}

void Floyd(MatrixGraph G, int **D, int **S) {
    // 创建Distance Table和Sequence Table
    createArray(D, G.vexnum, G.vexnum);
    createArray(S, G.vexnum, G.vexnum);
	
    //图G的边矩阵中，用INFINITY来表示两点之间不存在边
    /*这个双循环对数组D[][]和S[][]进行了初始化*/
    for (int i = 0; i < G.vexnum; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            D[i][j] = G.weight[i][j];
            S[i][j] = -1;
        }
    }
    /*下面这个三层循环是本算法的主要操作，
    完成了以k为中间点的所有的顶点对(i, j)进行检测和修改*/
    for (int k = 0; k < G.vexnum; k++) {
        for (int i = 0; i < G.vexnum; i++) {
            for (int j = 0; j < G.vexnum; j++) {
                if (D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    S[i][j] = k;
                }
            }
        }
    }
}




