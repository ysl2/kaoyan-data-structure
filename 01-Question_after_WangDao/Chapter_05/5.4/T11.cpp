// 关于union的用法
// http://c.biancheng.net/cpp/html/450.html

typedef struct {
    unsigned int ID, IP;
} LinkNode;

typedef struct {
    unsigned int Prefix, Mask;
} NetNode;

typedef struct Node {
    int Flag;
    union {
        LinkNode link;
        NetNode net;
    } LinkOrNet;
    unsigned int Matric;
    struct Node *next;
} ArcNode;

typedef struct HeadNode{
    unsigned int RouterID;
    ArcNode *LinkOrNet_Node;
    struct HeadNode *next;
} HeadNode;
