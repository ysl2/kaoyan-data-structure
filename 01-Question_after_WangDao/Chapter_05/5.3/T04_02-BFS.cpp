#include <queue>
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

bool BFS(AdjacentGraph G, int a, int b) {
    queue<int> q;
    q.push(a);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        visited[v] = true;
        for (ArcNode *temp = (G->vertex[v]).first; temp != NULL; temp = temp->next) {
            int w = temp->index;
            if (w == b)
                return true;
            if (!visited[w])
                q.push(w);
        }
    }
    return false;
}

// 书上没有指定w的类型，但是根据他写的代码，应该是把w作为结点类型，而不是int类型
// 这样的话，需要用的时候还要提取结点的index值，不仅容易误导，还麻烦了一小步

// 我这里写的是把w作为int类型了，
// 也就是在FirstNeighbor和NextNeighbor内部，已经获取到了相应的index值
// 参考T04-00，“邻接表的结构体定义”
// 题目要求用i, j，但是i占了我的迭代器变量了，不舒服。所以我给改成a, b了

bool test(AdjacentGraph G, int a, int b) {
    // 初始化数组
    for (int i = 0; i < G->vexnum; i++)
        visited[i] = false;
    return BFS(G, a, b);  // 开始寻找边
}
