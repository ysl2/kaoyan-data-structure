// 2020-09-04 第三次修订
#define maxSize 100
#define INFINITY 9999

bool selected[maxSize];
int minDist[maxSize];
int parent[maxSize];
Queue(Q);

void BFS(Graph G, int v0) {
    InitQueue(Q);
    for (int i = 0; i < maxSize; i++) {
        selected[i] = false;
        minDist[i] = INFINITY;
    }
    selected[v0] = true;
    minDist[v0] = 0;
    parent[v0] = -1;
    EnQueue (Q, v0);

    while (!QueueEmpty(Q)) {
        int v;
        DeQueue(Q, v);
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
            if (!selected[w]) {
                minDist[w] = minDist[v] + 1;
                parent[w] = v;
                selected[w] = true;
                EnQueue(w);
            }
        }
    }
}


-----------------------------------------------------
//第二次修订：2020/08/19
---
const int INFINITY = 9999;
const int MAX_VEX_NUM = 10;

bool selected[MAX_VEX_NUM];
int minDist[MAX_VEX_NUM];
int parent[MAX_VEX_NUM];
Queue Q;

void BFS_MIN_Distance(Graph G, int v0) {
    InitQueue(Q);
    for (int i = 0; i < MAX_VEX_NUM; i++) {
        selected[i] = false;
        minDist[i] = INFINITY;
    }
    minDist[v0] = 0;
    parent[v0] = -1;
    selected[v0] = true;
    EnQueue(Q, v0);
    int v;
    while (!IsEmpty(Q)) {
        DeQueue(Q, v);
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
            if (!selected[w]) {
                minDist[w] = minDist[v] + 1;
                parent[w] = v;
                selected[w] = true;
                EnQueue(Q, w);
            }
        }
    }
}
-------------------------------------------------------------------------
//原先的：
---
const int INFINITY = 9999;

//求顶点v到其他顶点的最短路径
void BFS_MIN_Distance(Graph g, int v) {
    bool selected[g.vexnum];
    int minDist[g.vexnum]; // minDist[i]表示从v到i的最短路径
    int parent[g.vexnum];
    Queue Q;
    InitQueue(Q);

    for(int i = 0; i < g.vexnum; i++) {
		selected[i] = false;
        minDist[i] = INFINITY; // 初始化路径长度
        parent[i] = -1; // 最短路径从哪个顶点过来
    }
    selected[v] = true;
    minDist[v] = 0;
    EnQueue(Q, v);
    while(!isEmpty(Q)) { // BFS算法主过程
        DeQueue(Q, v); // 队头元素v出队
        for(int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
            if(!selected[w]) { // w为v的尚未访问的邻接顶点
                minDist[w] = minDist[v] + 1; // 路径长度加1
                parent[w] = v; // 最短路径应从v到w
                selected[w] = true; // 设已访问标记
                EnQueue(Q, w); // 顶点w入队
            }
        } // if
    } // while
}
