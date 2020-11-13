// 拓扑排序：BFS
// 2020-11-13
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;

typedef int ElemType;
typedef struct {
    int number;  // 顶点的编号，这一项用户不能自己定义，是固定的从0开始的数字
    ElemType data;  // 顶点信息。这一项是从用户输入的vertex数组中写入的，并不要求非要int型，也可以是A，B，C这种
} VertexType;  // 上面这两项，在遍历的时候不会打印。但是真实存在，用于对结点信息进行补充描述

typedef struct {
    VertexType *vertex;
    int **edge;
    int vexnum, arcnum;
} Matrix, *MatrixGraph;

void outputEdge(MatrixGraph G) {
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++)
            cout << *(*(G->edge + i) + j) << " ";  // 虽然是二维数组，但是按照一维的方式遍历，只是需要解引用两层
        cout << endl;
    }
}

// 初始化邻接矩阵
void initMatrixGraph(MatrixGraph &G, int vexnum) {
    G->vexnum = vexnum;
    G->arcnum = 0;
    G->vertex = new VertexType[G->vexnum];
    for (int i = 0; i < G->vexnum; i++) {
        G->vertex[i].number = i;
        // G->vertex[i].info = NULL;  // 可选，因为在下面的函数中，会再次赋值
    }
    G->edge = new int *[G->vexnum];
    for (int i = 0; i < G->vexnum; i++) {
        G->edge[i] = new int[G->vexnum];
        memset(G->edge[i], 0, sizeof(int) * (G->vexnum));
    }
}

// 通过一个一维顶点数组和一个二维边数组得到一个邻接矩阵图
MatrixGraph createMatrix(ElemType *vertex, int vexnum, int *edge) {
    MatrixGraph G = new Matrix;
    initMatrixGraph(G, vexnum);
    for (int i = 0; i < vexnum; i++)
        G->vertex[i].data = vertex[i];
    for (int i = 0; i < vexnum; i++) {
        for (int j = 0; j < vexnum; j++) {
            if (edge[i * vexnum + j] != 0) {
                G->edge[i][j] = edge[i * vexnum + j];  // 将一维数组edge的值按照二维数组的方式输入到G->edge
                G->arcnum++;
            }
        }
    }
    return G;
}

// 返回的是二维数组的下标值。如果需要返回顶点，需要 + 1
int FirstNeighbor(MatrixGraph G, int v) {
    int i, flag = -1;
    for (i = 0; i < G->vexnum; i++) {
        if (*(*(G->edge + v) + i) != 0) {
            flag = 1;
            break;
        }
    }
    return (flag == -1) ? flag : i;
}

// 返回的是二维数组的下标值。如果需要返回顶点，需要 + 1
int NextNeighbor(MatrixGraph G, int v, int w) {
    int i, flag = -1;
    for (i = w + 1; i < G->vexnum; i++) {
        if (*(*(G->edge + v) + i) != 0) {
            flag = 1;
            break;
        }
    }
    return (flag == -1) ? flag : i;
}

int *getIndegreeArray(MatrixGraph G) {
    int *indegree = new int[G->vexnum];
    memset(indegree, 0, sizeof(int) * G->vexnum);
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++) {
            if (G->edge[i][j] == 1)
                indegree[j]++;
        }
    }
    return indegree;
}

int *output;

// 基于BFS的拓扑排序
bool topologicalSort(MatrixGraph G) {
    int *indegree = getIndegreeArray(G);
    output = new int[G->vexnum];
    memset(output, 0, sizeof(int) * G->vexnum);
    queue<int> q;  // 拓扑排序用栈或者队列都行
    for (int i = 0; i < G->vexnum; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    int count = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        output[count++] = G->vertex[v].data;
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
            indegree[w]--;
            if (indegree[w] == 0)
                q.push(w);
				// 这里不用考虑重复入队的问题。
				// 因为在indegree--的时候，如果之前结点已经访问过，那么入度必然会是负数
				// 而这里只有为0的时候，才会入队，因此之前访问过的结点不会再入队了
        }
    }
    return count == G->vexnum;
	// 如果count==顶点数，表示排序成功，返回true。否则返回false
}

void printTopologicalSortResult(int *a, int length) {
    for (int i = 0; i < length; i++)
        cout << a[i] << " ";
    cout << endl;
}

void test(ElemType *vertex, int vexnum, int *edge) {
    MatrixGraph G = createMatrix(vertex, vexnum, edge);

    if (topologicalSort(G) == true)
        printTopologicalSortResult(output, G->vexnum);
    else
        cout << "false" << endl;
}

int main() {
    ElemType vertex[] = {1, 2, 3, 4, 5};
    int vexnum = sizeof(vertex) / sizeof(ElemType);
    int edge[] = {
        0, 1, 0, 1, 0,
        0, 0, 1, 1, 0,
        0, 0, 0, 0, 1,
        0, 0, 1, 0, 1,
        0, 0, 0, 0, 0};

    test(vertex, vexnum, edge);

    return 0;
}

// 输出结果：
// 1 2 4 3 5


// //-------------------------------------------------------------------------------
// // 2020-09-04 第二次修订
// #include <string.h>  // memset的库
// #define maxSize 100

// int output[maxSize];

// // 基于BFS的拓扑排序
// bool topologicalSort(Graph G) {
// // 在此方法中，表示入度的数组indegree[]默认在G的结构体中定义了
// // 因此当G传进来的时候，已经包含了所有的结点入度信息
// // 如果不想包含在结构体中也可以，
// // 但是需要遍历G，把所有结点的入度信息传到indegree[]数组里
//     Queue Q;  // 拓扑排序用栈或者队列都行
//     InitQueue(Q);
//     memset(output, -1, sizeof(int) * maxSize);  // 初始化数组所有值为-1
//     for (int i = 0; i < G.vexnum; i++) {
//         if (G.indegree[i] == 0) {
//             EnQueue(Q, i);
//         }
//     }
//     int count = 0;
//     while (!QueueEmpty(Q)) {
//         int v;
//         DeQueue(Q, v);
//         output[count++] = v;
//         for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
//             G.indegree[w]--;
//             if (G.indegree[w] == 0) {
//                 EnQueue(Q, w);
// 				// 这里不用考虑重复入队的问题。
// 				// 因为在indegree--的时候，如果之前结点已经访问过，那么入度必然会是负数
// 				// 而这里只有为0的时候，才会入队，因此之前访问过的结点不会再入队了
//             }
//         }
//     }
//     return count == G.vexnum;
// }


// ------------------------------------------------------------
// // 补充说明：下面这个版本是针对邻接表的拓扑排序。
// // 上面第二次修订的是邻接矩阵和邻接表通用的
// // 因为邻接矩阵和邻接表仅在FirstNeighbor和NextNeighbor的内部实现不同
// // 而第二次修订的版本隐藏了内部实现

// #define maxSize 100  // 图中顶点数目的最大值
// #define DEFAULT 9999  // 存储结果的数组的元素默认值
// typedef int VexType;
// typedef struct ArcNode {  // 边表结点
//     int index;  // 该弧所指向的顶点的位置
//     struct ArcNode *next;  // 指向下一条弧的指针
//     /*InfoType info*/ // 网的边权值
// } ArcNode;
// typedef struct VexNode {  // 顶点表结点
//     VexType data;  // 顶点信息
//     ArcNode *first;  // 指向第一条依附该顶点的弧的指针
// } VexNode;
// typedef struct {
//     VexNode vertex[maxSize];  // 邻接表
//     int vexnum, arcnum;  // 图的顶点数和弧数
//     int indegree[maxSize];
// } Graph;  // Graph是以邻接表存储的图的类型

// int print[maxSize];  // 存放拓扑排序结果的数组（全局变量）

// bool topologicalSort(Graph G) {
//     Stack S;
//     InitStack(S);  // 初始化栈，存储入度为0的顶点
//     for (int i = 0; i < G.vexnum; i++) {
//         print[i] = DEFAULT;
//         if (G.indegree[i] == 0) {
//             Push(S, i);  // 将所有入度为0的顶点进栈
//         }
//     }
//     int count = 0;  // 计数，记录当前已经输出的顶点数
//     while (!StackEmpty(S)) {  // 栈不空，则存在入度为0的顶点
//         int v;
//         Pop(S, v);  // 栈顶元素出栈
//         print[count++] = v;  // 输出顶点v
//         // 下面这个for是把FirstNeighbor和NextNeighbor的具体实现暴露在外面了
//         // 如果嫌麻烦的话，这里照样可以写FirstNeighbor和NextNeighbor
//         // 但是这时候w就是int类型了。
//         for (ArcNode *w = G.vertex[v].first; w != NULL; w = w->next) {
//             // 将所有v指向的顶点的入度减1，并且将入度减为0的顶点压入栈S
//             G.indegree[w->index]--;
//             if (G.indegree[w->index] == 0) {
//                 Push(S, w->index);  // 入度为0，则入栈
//             }
//         }
//     }  // while
//     return count >= G.vexnum;
// 	// 如果count>=顶点数，表示排序成功，返回true。否则返回false
//     //实际上这里count不可能严格大于顶点数，只可能存在相等或者小于的情况
// }

