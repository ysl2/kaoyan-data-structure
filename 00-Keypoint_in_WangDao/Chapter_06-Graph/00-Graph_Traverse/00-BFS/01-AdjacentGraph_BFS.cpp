// 2020-10-30
#include <iostream>
#include <queue>
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
// 这里为了代码简洁，没有采用结点传递方式，而是采用了值传递方式。值传递方式的弊端在于执行效率低。
// 实际上，采用结点传递方式只需要改一下返回值即可。
int FirstNeighbor(AdjacentGraph G, int v) {
    return G->vertex[v].first != NULL ? G->vertex[v].first->adjvex : -1;
}

// 这里的v是数组下标，而不是顶点
// 这里为了代码简洁，没有采用结点传递方式，而是采用了值传递方式。值传递方式的弊端在于执行效率低。
// 实际上，采用结点传递方式只需要改一下返回值即可。
int NextNeighbor(AdjacentGraph G, int v, int w) {
    ArcNode *temp = G->vertex[v].first;
    for (; temp != NULL && temp->adjvex != w; temp = temp->next)
        ;
    return temp->next != NULL ? temp->next->adjvex : -1;
}

ArcNode *FirstNeighborNode(AdjacentGraph G, int v) {
    return G->vertex[v].first;  //无论是不是NULL都无所谓
}

ArcNode *NextNeighborNode(AdjacentGraph G, ArcNode *w) {
    return w->next;  // 无论是不是NULL都无所谓
}

int *visited;

void visit(AdjacentGraph G, int v) {
    cout << G->vertex[v].data << " ";
}

void BFS(AdjacentGraph G, int v0) {
    queue<int> q;
    visit(G, v0);
    visited[v0] = 1;
    q.push(v0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (ArcNode *temp = G->vertex[v].first; temp != NULL; temp = temp->next) {
            if (!visited[temp->adjvex]) {
                visit(G, temp->adjvex);
                visited[temp->adjvex] = 1;
                q.push(temp->adjvex);
            }
        }
    }
}

void BFSTraverse(AdjacentGraph G) {
    visited = new int[G->vexnum];
    memset(visited, 0, sizeof(int) * G->vexnum);
    for (int i = 0; i < G->vexnum; i++) {
        if (!visited[i])
            BFS(G, i);
    }
}

void test(ElemType *vertex, int vexnum, int *edge) {
    AdjacentGraph G = createAdjacent(vertex, vexnum, edge);
    outputEdge(G);
    cout << endl;
    BFSTraverse(G);
    cout << endl;
}

int main() {
    ElemType vertex[] = {1, 2, 3, 4, 5};
    int vexnum = sizeof(vertex) / sizeof(ElemType);
    int edge[] = {
        0, 1, 1, 0, 0,
        0, 0, 1, 0, 1,
        1, 0, 0, 1, 0,
        0, 0, 0, 0, 1,
        0, 1, 1, 0, 0};

    test(vertex, vexnum, edge);
    return 0;
}

// 输出结果：
// 1|2 3
// 2|3 5
// 3|1 4
// 4|5
// 5|2 3

// 1 2 3 5 4
