// 2020-09-05 第二次修订
#define maxSize 100
#define INFINITY 9999

typedef struct {
    int a;  // 相连的顶点
    int b;  // 相连的顶点
    int weight;  // 边的权值
} Road;  // 表示一条边的信息

int getRoot(int a) {  // 并查集找根节点的算法
    while (a != v[a]) {
        a = v[a];
    }
    return a;
}

int kruskal(MatrixGraph G) {
// 这里默认用邻接矩阵存储图
    // 1. 辅助空间的创建与初始化
    Road road[G.arcnum];  // road[]中含有所有边的信息
    int v[G.vexnum];  // 创建并查集数组
    // 初始化road[]数组：遍历整个图，得到每条边的信息，存入road[]中
    // 顺便初始化并查集v[]
    int k = 0;  // road[]的迭代器变量
    for (int i = 0; i < G.vexnum; i++) {
        // 初始化并查集v[]
        v[i] = i;
        // 初始化road[]：把图的二维表示压缩成一维
        for (int j = 0; j < G.vexnum; j++) {
            // 如果边不存在，跳过这个，遍历下一个。如果存在，就加入road[]中
            if (G.edge[i][j] == INFINITY) continue;  
            road[k].a = i;
            road[k].b = j;
            road[k].weight = G.edge[i][j];
            k++;
        }
    }  // 初始化结束

    // 2. 开始kruskal
    sort(road, G.arcnum);  // 按边的权值从小到大排序
    // sort函数要根据题目对算法复杂度的要求选择合适的排序函数写出
    int sum = 0;
    for (int i = 0; i < G.arcnum; i++) {
        int a = getRoot(road[i].a);
        int b = getRoot(road[i].b);
        if (a != b) {  // 如果a和b的根不是同一个，说明a，b之间没有环
            sum += road[i].weight;  // 加入最小生成树
            // 上面这句话也可以加上一句输出，这样就能输出整个树
            v[a] = b;  // 在并查集中把a和b归到同一个根节点里
        }
    }
    return sum;
}
-----------------------------------------------------------
const int MAX_EDGE_NUM = 8;
const int MAX_VEX_NUM = 6;

typedef struct {
    int a, b;
    int weight; 
} Road; // 表示边e=(a, b), 权值为weight

Road road[MAX_EDGE_NUM];
int v[MAX_VEX_NUM]; // 定义并查集数组

int getRoot(int a) {  // 在并查集中查找根节点的函数
    while (a != v[a]) {
        a = v[a];
    }
    return a;
}

int kruskal(MatrixGraph G, Road road[]) {
    int a, b;
    int sum = 0;
    for (int i = 0; i < G.vexnum; i++) {
        v[i] = i;  //初始化并查集
    }
    sort(road, G.arcnum);  // 对road数组中的arcnum条边按其权值从小到大排序
    // sort函数要根据题目对算法复杂度的要求选择合适的排序函数写出
    for (int i = 0; i < G.arcnum; i++) {
        a = getRoot(road[i].a);
        b = getRoot(road[i].b);
        if (a != b) {
            v[a] = b;  // 并入并查集
            sum += road[i].weight;  // 求生成树的权值
            // 这句并不是固定写法，也可以改成其他的
            // 例如，将生成树的各边输出，或者存放在数组里
        }
    }
    return sum;
}

