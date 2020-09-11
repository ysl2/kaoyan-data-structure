#define MAX_VEX_NUM 10
#define MAX_EDGE_NUM 10
#define INFINITY 9999

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
