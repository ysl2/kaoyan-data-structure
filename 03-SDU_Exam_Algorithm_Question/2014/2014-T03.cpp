// 2020-10-24
#include <string.h>
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct {
    int number;  // 顶点的编号，这一项用户不能自己定义，是固定的从1开始的数字
    ElemType data;  // 顶点信息。这一项是从用户输入的vertex数组中写入的，并不要求非要int型，也可以是A，B，C这种
} VertexType;  // 上面这两项，在遍历的时候不会打印。但是真实存在，用于对结点信息进行补充描述

typedef struct {
    VertexType *vertex;
    int *edge;
    int vexnum, arcnum;
} Matrix, *MatrixGraph;

// 采用三角形遍历方式
void outputEdge(MatrixGraph G) {
    for (int i = 0; i < G->vexnum - 1; i++) {
        for (int j = 0; j <= i; j++)
            cout << G->edge[i * (i + 1) / 2 + j] << " ";
        cout << endl;
    }
    cout << endl;
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
    G->edge = new int[(G->vexnum - 1) * ((G->vexnum - 1) + 1) / 2];
    memset(G->edge, 0, sizeof(int) * ((G->vexnum - 1) * ((G->vexnum - 1) + 1) / 2));
}

// 通过一个一维顶点数组和一个二维边数组得到一个邻接矩阵图
MatrixGraph createMatrix(ElemType *vertex, int vexnum, int *edge) {
    MatrixGraph G = new Matrix;
    initMatrixGraph(G, vexnum);
    for (int i = 0; i < vexnum; i++)
        G->vertex[i].data = vertex[i];
    for (int i = 0; i < (vexnum - 1) * ((vexnum - 1) + 1) / 2; i++) {
        if (edge[i] != 0) {
            G->edge[i] = edge[i];
            G->arcnum++;
        }
    }
    return G;
}

// 将二维数组的坐标转换为实际下三角表示的一维数组的坐标
int converseMatrixToArray(MatrixGraph G, int i, int j) {
    return (i - 1) * ((i - 1) + 1) / 2 + j;  // 这里与答案不同。因为答案的下标是从(1,1)开始算的。而我这里是从0开始算
}

// 本算法与答案完全一致
int getDegree(MatrixGraph G, int v0) {
    int count = 0;
    // 横向加和
    for (int i = 0; i <= v0 - 1; i++)
        count += G->edge[converseMatrixToArray(G, v0, i)];
    // 竖向加和
    for (int i = v0 + 1; i <= G->vexnum - 1; i++)
        count += G->edge[converseMatrixToArray(G, i, v0)];
    return count;
}

void test(ElemType *vertex, int vexnum, int *edge, int V0) {
    int v0 = V0 - 1;
    MatrixGraph G = createMatrix(vertex, vexnum, edge);
    cout << getDegree(G, v0) << endl;
}

int main() {
    ElemType vertex[] = {1, 2, 3, 4, 5};
    int vexnum = sizeof(vertex) / sizeof(vertex[0]);
    /*
        注意下标的匹配关系 :

            0  1  2  3
           ------------
        0 | 1,
        1 | 0, 1,
        2 | 1, 0, 1,
        3 | 0, 1, 1, 0
    */
    int edge[] = {
        1,
        0, 1,
        1, 0, 1,
        0, 1, 1, 0};

    test(vertex, vexnum, edge, 1);
    test(vertex, vexnum, edge, 2);
    test(vertex, vexnum, edge, 3);
    test(vertex, vexnum, edge, 4);
    test(vertex, vexnum, edge, 5);

    return 0;
}

// 输出结果：
// 2
// 3
// 3
// 2
// 2
