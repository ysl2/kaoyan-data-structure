// 2020-10-19
#include <iostream>
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
        cout << G->vertex[i].data << "|";  // 无论是边结点还是顶点，都是从顶点数组里面取值。按照索引取对应的值。比如，索引是0，那么取出的值就是1
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

// 本质上是”不含头结点的单链表的删除“问题，对于first结点需要单独考虑
bool deleteNode(AdjacentGraph G, int i, int j) {
    // 如果first是NULL
    if (G->vertex[i].first == NULL)
        return false;
    // 如果正好要删除的就是first结点
    if (G->vertex[i].first->adjvex == j) {
        ArcNode *temp = G->vertex[i].first->next;
        delete G->vertex[i].first;
        G->vertex[i].first = temp;
        return true;
    }
    // 其他情况
    ArcNode *pre = G->vertex[i].first;
    ArcNode *p = G->vertex[i].first->next;
    while (p != NULL && p->adjvex != j) {
        p = p->next;
        pre = pre->next;
    }
    if (p == NULL)
        return false;
    pre->next = p->next;
    delete p;
    return true;
}

void test(ElemType *vertex, int vexnum, int *edge, int I, int J) {
    int i = I - 1, j = J - 1;
    AdjacentGraph G = createAdjacent(vertex, vexnum, edge);

    cout << endl;

    outputEdge(G);

    cout << endl;

    if (deleteNode(G, i, j))
        cout << "true" << endl << endl;
    else
        cout << "false" << endl << endl;

    outputEdge(G);

    cout << endl;

    cout << "---------------------" << endl;
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

    test(vertex, vexnum, edge, 1, 3);
    test(vertex, vexnum, edge, 5, 2);

    return 0;
}

// 输出结果：

// 1|2 3
// 2|3 5
// 3|1 4
// 4|5
// 5|2 3

// true

// 1|2
// 2|3 5
// 3|1 4
// 4|5
// 5|2 3

// ---------------------

// 1|2 3
// 2|3 5
// 3|1 4
// 4|5
// 5|2 3

// true

// 1|2 3
// 2|3 5
// 3|1 4
// 4|5
// 5|3

// ---------------------

