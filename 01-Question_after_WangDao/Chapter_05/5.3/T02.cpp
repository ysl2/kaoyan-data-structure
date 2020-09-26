typedef int VexType;
typedef int EdgeType;

typedef struct {
    VexType *vertex;
    EdgeType **edge;
    int vexnum, arcnum;
} MatrixGraph;

int FirstNeighbor(MatrixGraph G, int v) {
    int i, flag = -1;
    for (i = 0; i < G.vexnum; i++) {
        if (*(*(G.edge + v) + i) == 1) {
            flag = 1;
            break;
        }
    }
    return (flag == -1) ? flag : i;
}

int NextNeighbor(MatrixGraph G, int v, int w) {
    int i, flag = -1;
    for (i = w + 1; i < G.vexnum; i++) {
        if (*(*(G.edge + v) + i) == 1) {
            flag = 1;
            break;
        }
    }
    return (flag == -1) ? flag : i;
}

void DFS(MatrixGraph &G, int v, int &Vnum, int &Enum, bool visited[]) {
    Vnum++;
    visited[v] = true;
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
        Enum++;
        if (!visited[w])
            DFS(G, w, Vnum, Enum, visited);
    }
}

bool isTree(MatrixGraph &G) {
    bool visited[G.vexnum];
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = false;
    int Vnum = 0, Enum = 0;
    DFS(G, 1, Vnum, Enum, visited);
    return Vnum == G.vexnum && Enum == 2 * (G.vexnum - 1);
}

