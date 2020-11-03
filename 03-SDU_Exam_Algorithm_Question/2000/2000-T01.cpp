/*
    传递闭包：https://blog.csdn.net/qq_41280600/article/details/104128144

    void floyd() {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    //i-->k有边 且 k-->j有边 那么i-->j有边
                    if (g[i][k] && g[k][j])
                        g[i][j] = 1;
                }
            }
        }
    }
*/
