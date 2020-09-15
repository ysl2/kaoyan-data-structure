#define maxSize 10
typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *pre, *next;
} LinkNode;
typedef struct {
    LinkNode *top;
    int length;
} * LinkStack;
