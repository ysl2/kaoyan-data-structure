#define maxSize 100
typedef char ElemType;
struct Node {
    int index;  // 指向孩子结点在box数组中的位置，所以必须int型
    struct Node *next;
};
typedef struct {
    ElemType data;  // 存储结点的信息，可以是任何类型
    Node *first;
} Box;
typedef struct {
    Box box[maxSize];
    int root, nodenum;
} Tree;

