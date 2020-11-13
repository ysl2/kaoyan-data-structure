// 拓扑排序：DFS
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

struct Time {
    int vertexData;
    int finishtime;
};

int *visited;
Time *finishTime;  // 由于祖先的结束时间大于子孙的结束时间，因此将经过DFS后的finishTime数组中的值从大到小排序，就是拓扑序列
int time;

// 基于DFS的拓扑排序
void DFS(MatrixGraph G, int v0) {
    visited[v0] = 1;
    for (int w = FirstNeighbor(G, v0); w >= 0; w = NextNeighbor(G, v0, w)) {
        if (!visited[w])
            DFS(G, w);
    }
    time++;
    finishTime[v0].vertexData = v0 + 1;
    finishTime[v0].finishtime = time;
}

void DFSTraverse(MatrixGraph G) {
    visited = new int[G->vexnum];
    memset(visited, 0, sizeof(int) * G->vexnum);
    finishTime = new Time[G->vexnum];
    time = 0;
    for (int i = 0; i < G->vexnum; i++) {
        if (!visited[i])
            DFS(G, i);
    }
}

Time *B;

void merge(Time a[], int low, int mid, int high) {
    for (int i = low; i <= high; i++) {
        B[i].vertexData = a[i].vertexData;
        B[i].finishtime = a[i].finishtime;
    }
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (B[i].finishtime >= B[j].finishtime) {
            a[k].vertexData = B[i].vertexData;
            a[k].finishtime = B[i].finishtime;
            i++;
            k++;
        } else {
            a[k].vertexData = B[j].vertexData;
            a[k].finishtime = B[j].finishtime;
            j++;
            k++;
        }
    }
    while (i <= mid) {
        a[k].vertexData = B[i].vertexData;
        a[k].finishtime = B[i].finishtime;
        i++;
        k++;
    }
    while (j <= high) {
        a[k].vertexData = B[j].vertexData;
        a[k].finishtime = B[j].finishtime;
        j++;
        k++;
    }
}

void mergeSort(Time a[], int low, int high) {
    if (low >= high)
        return;
    if (!B)
        B = new Time[high - low + 1];
    int mid = low + (high - low) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
}

void printTopologicalSortResult(Time *a, int length) {
    mergeSort(a, 0, length - 1);
    for (int i = 0; i < length; i++)
        cout << a[i].vertexData << " ";
    cout << endl;
}

void test(ElemType *vertex, int vexnum, int *edge) {
    MatrixGraph G = createMatrix(vertex, vexnum, edge);
    DFSTraverse(G);
    printTopologicalSortResult(finishTime, G->vexnum);
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


// //------------------------------------------------------------------------
// #define maxSize 100
// #define INFINITY 9999

// bool visited[maxSize];
// int time;
// int finishTime[maxSize];
// // 将经过DFS后的finishTime数组中的值从大到小排序，就是拓扑序列

// void DFSTraverse(Graph G) {
//     for (int i = 0; i < maxSize; i++) {
//         visited[i] = false;
//         finishTime = INFINITY;  // 将初值置为无穷大
//         // INFINITY为无穷大，这里假设INFINITY表示顶点不存在
//         // 当输出结果遍历到INFINITY时，
//         // 说明从这个结点开始（包括此结点）往后已经不存在了，就停止输出
//     }
//     time = 0;
//     for (int i = 0; i < G.vexnum; i++) {
//         if (!visited[i]) {
//             DFS(G, i);
//         }
//     }
// }

// void DFS(Graph G, int v0) {
//     visit(v0);
//     visited[v0] = true;
//     for (int w = FirstNeighbor(G, v0); w >= 0; w = NextNeighbor(G, v0, w)) {
//         if (!visited[w]) {
//             DFS(G, w);
//         }
//     }
//     time++;
//     finishTime[v0] = time;
// }

