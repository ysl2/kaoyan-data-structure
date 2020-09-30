#include <iostream>
#include <stack>
using namespace std;

// 2020-09-01
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

// 2020-09-26
void DFS(AdjacentGraph G, int v0) {
    // 初始化
    stack<int> s;
    bool visited[G->vexnum];
    for (int i = 0; i < G->vexnum; i++)
        visited[i] = false;
    s.push(v0);
    visited[v0] = true;

    // 循环
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        cout << v << " ";
        for (ArcNode *temp = (G->vertex[v]).first; temp != NULL; temp = temp->next) {
            int w = temp->index;
            if (!visited[w]) {
                s.push(w);
                visited[w] = true;
            }
        }
    }
}

// #define maxSize 100
// void DFS(AdjacentList &G, int v0) {
//     // 初始化
//     Stack S;
//     InitStack(S);
//     bool visited[G.vexnum];
//     for (int i = 0; i < G.vexnum; i++) {
//         visited[i] = false;
//     }
//     Push(S, v0);
//     visited[v0] = true;
//     // 循环
//     while (!StackEmpty(S)) {
//         int v;
//         Pop(S, v);
//         visit(v);
//         for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
//             if (!visited[w]) {
//                 Push(S, w);
//                 visited[w] = true;
//             }
//         }
//     }
// }