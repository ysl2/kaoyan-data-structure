#define MAX_VEX_NUM 10
#define MAX_EDGE_NUM 10
#define INFINITY 9999

typedef int VexType;
typedef int EdgeType;

typedef struct {
    VexType vertex[MAX_VEX_NUM];
    EdgeType edge[MAX_EDGE_NUM][MAX_EDGE_NUM];
    int vexnum, arcnum;
}MatrixGraph;

