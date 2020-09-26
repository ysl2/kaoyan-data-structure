#include <iostream>
#define maxSize 100
using namespace std;

// 2020-09-01
// 邻接表定义
typedef char VexType;
typedef struct ArcNode {
    int index;  // 这里指向的是竖向的下标，所以是int类型
    struct ArcNode *next;
} ArcNode;
typedef struct VexNode {
    VexType data;  // 这里存的是竖向的结点信息，而不是下标值（与上面区分开）
    ArcNode *first;
} VexNode;
typedef struct {
    VexNode *vertex;  // 这里加了*号，因为将来会是一个数组（动态分配）
    int arcnum, vexnum;
} * AdjacentGraph;

bool visited[maxSize];  // 全局数组

bool DFS(AdjacentGraph G, int a, int b) {
    if (a == b)
        return true;
    visited[a] = true;
    for (ArcNode *temp = (G->vertex[a]).first; temp != 0; temp = temp->next) {
        int w = temp->index;
        if (!visited[w] && DFS(G, w, b))
            return true;
    }
    return false;
}

// 题目要求用i, j，但是i占了我的迭代器变量了，不舒服。所以我给改成a, b了
bool test(AdjacentGraph G, int a, int b) {
    // 初始化数组
    for (int i = 0; i < G->vexnum; i++)
        visited[i] = false;
    return DFS(G, a, b);  // 开始寻找边
}
