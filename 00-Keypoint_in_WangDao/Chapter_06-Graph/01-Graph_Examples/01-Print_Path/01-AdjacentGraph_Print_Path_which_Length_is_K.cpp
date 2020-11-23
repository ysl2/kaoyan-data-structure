// 2020-10-17
#include <iostream>
#include <string.h>
#include <vector>
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
int FirstNeigbor(AdjacentGraph G, int v) {
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

int *visited;
vector<int> v;  // 这里用vector模拟栈。因为如果直接用栈，就不能遍历元素。因此选择vector

void outputPath() {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

void DFS(AdjacentGraph G, int a, int k) {
    // 下面这两句相当于visit
    visited[a] = 1;
    v.push_back(G->vertex[a].data);
    // 这里G->vertex[a].data的原因是需要输出顶点名称而不是顶点编号。
    // 而顶点名称和顶点编号的关系是：它们的数组下标相同，
    // 因此通过相同的数组下标可以构建数组编号和数组名称之间的联系
    if (v.size() == k)
        outputPath();
    for (ArcNode *temp = G->vertex[a].first; temp != NULL; temp = temp->next) {
        if (!visited[temp->adjvex])
            DFS(G, temp->adjvex, k);
    }
    visited[a] = 0;
    v.pop_back();
    // 恢复顶点，使顶点重新可用。
    // 通过上面这两条语句，可以输出所有从a到b的简单路径。如果不加这两条语句，将只能输出一条路径。
}

void DFSTraverse(AdjacentGraph G, int k) {
    visited = new int[G->vexnum];
    memset(visited, 0, sizeof(visited[0]) * G->vexnum);
    for (int i = 0; i < G->vexnum; i++) {
        if (!visited[i])
            DFS(G, i, k);
    }
}

void test(ElemType *vertex, int vexnum, int *edge, int k) {
    AdjacentGraph G = createAdjacent(vertex, vexnum, edge);
    outputEdge(G);

    cout << endl;

    DFSTraverse(G, k);
}

int main() {
    ElemType vertex[] = {1, 2, 3, 4, 5};
    int vexnum = sizeof(vertex) / sizeof(vertex[0]);
    int edge[] = {
        0, 1, 1, 0, 0,
        0, 0, 1, 0, 1,
        1, 0, 0, 1, 0,
        0, 0, 0, 0, 1,
        0, 1, 1, 0, 0};

    test(vertex, vexnum, edge, 3);
    return 0;
}

// 输出结果：
// 1|2 3
// 2|3 5
// 3|1 4
// 4|5
// 5|2 3

// 1 2 3
// 1 2 5
// 1 3 4
// 2 3 1
// 2 3 4
// 2 5 3
// 3 1 2
// 3 4 5
// 4 5 2
// 4 5 3
// 5 2 3
// 5 3 1
// 5 3 4
