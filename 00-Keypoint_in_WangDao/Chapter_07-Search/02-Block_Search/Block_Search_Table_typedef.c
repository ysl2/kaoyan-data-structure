#define maxIndexSize;  // 最大索引量
#define maxElemSize;  // 最大实际元素个数

// 分块查找的特点：块内有序，块间无序
typedef int ElemType;
typedef struct {
    ElemType maxValue;
    int left, right;
} Index;  // 每个索引中，都包含当前索引块里的最大值，和索引块的起止下标
typedef struct {
    Index index[maxIndexSize];  // 索引表
    ElemType List[maxElemSize];  // 实际存储元素的顺序表
} IndexList;  // 分块查找索引表

