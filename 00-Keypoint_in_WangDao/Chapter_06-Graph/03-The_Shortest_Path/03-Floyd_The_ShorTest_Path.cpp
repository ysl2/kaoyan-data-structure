
// 2020-11-13
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

const int INFINITY = 9999;

typedef int ElemType;
typedef struct {
    int number;  // 顶点的编号，这一项用户不能自己定义，是固定的从1开始的数字
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
    for (int i = 0; i < G->vexnum; i++)
        G->vertex[i].number = i;
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

int **createArray(int m, int n) {  // 创建数组
    int **a = (int **)malloc(sizeof(int **) * m);
    for (int i = 0; i < m; i++) {
        *(a + i) = (int *) malloc(sizeof(int *) * n);
        memset(*(a + i), 0, sizeof(int) * n);
    }
    return a;
}

void printArray(int **a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << *(*(a + i) + j) << "\t";
        cout << endl;
    }
    cout << endl;
}

int **D;
int **S;

void Floyd(MatrixGraph G) {
    // 创建Distance Table和Sequence Table
    D = createArray(G->vexnum, G->vexnum);
    S = createArray(G->vexnum, G->vexnum);
    //图G的边矩阵中，用INFINITY来表示两点之间不存在边
    /*这个双循环对数组D[][]和S[][]进行了初始化*/
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++) {
            *(*(D + i) + j) =  G->edge[i][j];
            *(*(S + i) + j) = -1;
        }
    }
    /*下面这个三层循环是本算法的主要操作，
    完成了以k为中间点的所有的顶点对(i, j)进行检测和修改*/
    for (int k = 0; k < G->vexnum; k++) {
        for (int i = 0; i < G->vexnum; i++) {
            for (int j = 0; j < G->vexnum; j++) {
                if (*(*(D + i) + j) > *(*(D + i) + k) + *(*(D + k) + j)) {
                    *(*(D + i) + j) = *(*(D + i) + k) + *(*(D + k) + j);
                    *(*(S + i) + j) = k;
                }
            }
        }
    }
}

void test(ElemType *vertex, int vexnum, int *edge) {
    MatrixGraph G = createMatrix(vertex, vexnum, edge);
    Floyd(G);
    printArray(D, G->vexnum, G->vexnum);
    printArray(S, G->vexnum, G->vexnum);
}

int main() {
    ElemType vertex[] = {1, 2, 3, 4};
    int vexnum = sizeof(vertex) / sizeof(ElemType);
    int edge[] = {
        0, 1, INFINITY, 4,
        INFINITY, 0, 9, 2,
        3, 5, 0, 8,
        INFINITY, INFINITY, 6, 0};

    test(vertex, vexnum, edge);
    return 0;
}

// 输出结果：（测试用例为山大2002年真题）
// 0       1       9       3
// 11      0       8       2
// 3       4       0       6
// 9       10      6       0

// -1      -1      3       1
// 3       -1      3       -1
// -1      0       -1      1
// 2       2       -1      -1

