
// 2020-10-16
#include <iostream>
#include <string.h>
using namespace std;

typedef int ElemType;
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *next;
    ElemType info;  // 对当前结点的补充信息，这一项不是必须要填写的。
} ArcNode;

typedef struct VexNode {
    ElemType data;
    ArcNode *first;
    ElemType info;  // 对当前顶点的补充信息，这一项不是必须要填写的。
} VexNode;

typedef struct {
    VexNode *vertex;
    int arcnum, vexnum;
} Adjacent, *AdjacentGraph;

void outputEdge(AdjacentGraph G) {
    for (int i = 0; i < G->vexnum; i++) {
        cout << G->vertex[i].data << "|";
        for (ArcNode *temp = G->vertex[i].first; temp != NULL; temp = temp->next)
            cout << G->vertex[temp->adjvex].data << " ";
        cout << endl;
    }
}

// 初始化邻接表
void initAdjacentGraph(AdjacentGraph &G, int vexnum) {
    G->vexnum = vexnum;
    G->arcnum = 0;
    G->vertex = new VexNode[G->vexnum];
    for (int i = 0; i < G->vexnum; i++) {
        G->vertex[i].data = 0;
        G->vertex[i].first = NULL;
    }
}

// 通过一个一维顶点数组和一个二维边数组得到邻接表图
AdjacentGraph createAdjacent(ElemType *vertex, int vexnum, int *edge) {
    AdjacentGraph G = new Adjacent;
    initAdjacentGraph(G, vexnum);
    for (int i = 0; i < vexnum; i++)
        G->vertex[i].data = vertex[i];
    for (int i = 0; i < vexnum; i++) {
        // 由于在这里采用头插法插入结点，因此为了保证顺序和顶点顺序一致，采用从后向前遍历，这样头插结束后，链表结点顺序不会相反
        for (int j = vexnum - 1; j >= 0; j--) {
            if (edge[i * vexnum + j] == 1) {
                ArcNode *temp = new ArcNode;
                temp->adjvex = j;
                temp->next = G->vertex[i].first;
                G->vertex[i].first = temp;
                G->arcnum++;
            }
        }
    }
    return G;
}

// 这里的v是数组下标，而不是顶点
int FirstNeigbor(AdjacentGraph G, int v) {
    return G->vertex[v].first != NULL ? G->vertex[v].first->adjvex : -1;
}

// 这里的v是数组下标，而不是顶点
int NextNeighbor(AdjacentGraph G, int v, int w) {
    ArcNode *temp = G->vertex[v].first;
    for (; temp != NULL && temp->adjvex != w; temp = temp->next)
        ;
    return temp->next != NULL ? temp->next->adjvex : -1;
}

int *visited;

bool DFS(AdjacentGraph G, int a, int b) {
    // 下面两行相当于visit
    if (a == b)
        return true;
    visited[a] = 1;
    for (int w = FirstNeigbor(G, a); w >= 0; w = NextNeighbor(G, a, w)) {
        if (!visited[w] && DFS(G, w, b))
            return true;
    }
    return false;
}

bool DFSTraverse(AdjacentGraph G, int A, int B) {
    int a = A - 1, b = B - 1;  // 将顶点转化成下标
    visited = new int[G->vexnum];
    memset(visited, 0, sizeof(int) * G->vexnum);

    return DFS(G, a, b);
}

/*
    // 或者采用全局变量的方式

    int *visited;
    bool flag = false;

    void DFS(AdjacentGraph G, int a, int b) {
        // 下面这两个if相当于visit
        if (flag == true)
            return;
        if (a == b) {
            flag = true;
            return;
        }
        visited[a] = 1;
        for (ArcNode *temp = G->vertex[a].first; temp != NULL; temp = temp->next) {
            if (!visited[temp->adjvex])
                DFS(G, temp->adjvex, b);
        }
    }

    bool DFSTraverse(AdjacentGraph G, int A, int B) {
        int a = A - 1, b = B - 1;
        visited = new int[G->vexnum];
        memset(visited, 0, sizeof(int) * G->vexnum);
        flag = false;

        DFS(G, a, b);
        return flag;
    }
*/

void test(ElemType *vertex, int vexnum, int *edge, int A, int B) {
    AdjacentGraph G = createAdjacent(vertex, vexnum, edge);

    if (DFSTraverse(G, A, B) == true)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

int main() {
    ElemType vertex[] = {1, 2, 3, 4, 5};
    int vexnum = sizeof(vertex) / sizeof(ElemType);
    int edge[] = {
        0, 1, 1, 0, 0,
        0, 0, 1, 0, 0,
        1, 0, 0, 1, 0,
        0, 0, 0, 0, 0,
        0, 1, 1, 0, 0};

    test(vertex, vexnum, edge, 1, 3);
    test(vertex, vexnum, edge, 1, 5);
    return 0;
}

// 输出结果：
// true
// false

