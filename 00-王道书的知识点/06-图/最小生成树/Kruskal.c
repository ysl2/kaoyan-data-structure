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

