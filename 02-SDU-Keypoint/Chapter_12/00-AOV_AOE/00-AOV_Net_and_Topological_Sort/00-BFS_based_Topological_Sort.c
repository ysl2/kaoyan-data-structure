// 2020-09-04 第二次修订
#include <string.h>  // memset的库
#define maxSize 100

int output[maxSize];

// 基于BFS的拓扑排序
bool topologicalSort(Graph G) {
// 在此方法中，表示入度的数组indegree[]默认在G的结构体中定义了
// 因此当G传进来的时候，已经包含了所有的结点入度信息
// 如果不想包含在结构体中也可以，
// 但是需要遍历G，把所有结点的入度信息传到indegree[]数组里
    Queue Q;  // 拓扑排序用栈或者队列都行
    InitQueue(Q);
    memset(output, -1, sizeof(int) * maxSize);  // 初始化数组所有值为-1
    for (int i = 0; i < G.vexnum; i++) {
        if (G.indegree[i] == 0) {
            EnQueue(Q, i);
        }
    }
    int count = 0;
    while (!QueueEmpty(Q)) {
        int v;
        DeQueue(Q, v);
        output[count++] = v;
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
            G.indegree[w]--;
            if (G.indegree[w] == 0) {
                EnQueue(Q, w);
				// 这里不用考虑重复入队的问题。
				// 因为在indegree--的时候，如果之前结点已经访问过，那么入度必然会是负数
				// 而这里只有为0的时候，才会入队，因此之前访问过的结点不会再入队了
            }
        }
    }
    return count == G.vexnum;
}


// ------------------------------------------------------------
// 补充说明：下面这个版本是针对邻接表的拓扑排序。
// 上面第二次修订的是邻接矩阵和邻接表通用的
// 因为邻接矩阵和邻接表仅在FirstNeighbor和NextNeighbor的内部实现不同
// 而第二次修订的版本隐藏了内部实现

#define maxSize 100  // 图中顶点数目的最大值
#define DEFAULT 9999  // 存储结果的数组的元素默认值
typedef int VexType;
typedef struct ArcNode {  // 边表结点
    int index;  // 该弧所指向的顶点的位置
    struct ArcNode *next;  // 指向下一条弧的指针
    /*InfoType info*/ // 网的边权值
} ArcNode;
typedef struct VexNode {  // 顶点表结点
    VexType data;  // 顶点信息
    ArcNode *first;  // 指向第一条依附该顶点的弧的指针
} VexNode;
typedef struct {
    VexNode vertex[maxSize];  // 邻接表
    int vexnum, arcnum;  // 图的顶点数和弧数
    int indegree[maxSize];
} Graph;  // Graph是以邻接表存储的图的类型

int print[maxSize];  // 存放拓扑排序结果的数组（全局变量）

bool topologicalSort(Graph G) {
    Stack S;
    InitStack(S);  // 初始化栈，存储入度为0的顶点
    for (int i = 0; i < G.vexnum; i++) {
        print[i] = DEFAULT;
        if (G.indegree[i] == 0) {
            Push(S, i);  // 将所有入度为0的顶点进栈
        }
    }
    int count = 0;  // 计数，记录当前已经输出的顶点数
    while (!StackEmpty(S)) {  // 栈不空，则存在入度为0的顶点
        int v;
        Pop(S, v);  // 栈顶元素出栈
        print[count++] = v;  // 输出顶点v
        // 下面这个for是把FirstNeighbor和NextNeighbor的具体实现暴露在外面了
        // 如果嫌麻烦的话，这里照样可以写FirstNeighbor和NextNeighbor
        // 但是这时候w就是int类型了。
        for (ArcNode *w = G.vertex[v].first; w != NULL; w = w->next) {
            // 将所有v指向的顶点的入度减1，并且将入度减为0的顶点压入栈S
            G.indegree[w->index]--;
            if (G.indegree[w->index] == 0) {
                Push(S, w->index);  // 入度为0，则入栈
            }
        }
    }  // while
    return count >= G.vexnum;
	// 如果count>=顶点数，表示排序成功，返回true。否则返回false
    //实际上这里count不可能严格大于顶点数，只可能存在相等或者小于的情况
}

