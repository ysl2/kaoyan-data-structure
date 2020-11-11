#include <iostream>
using namespace std;

typedef char ElemType;  // 把char强制转换成int。这样我可以使用上面写的测试用例，不然我还得重新写

typedef struct CSTNode {
    ElemType data;
    struct CSTNode *lchild, *rbro;
} CSTNode, *CSTree;

// 根据树的层次序列和每个结点的度，构造此树的孩子-兄弟链表
void createCSTree_Degree(CSTNode *&T, ElemType data[], int degree[], int length) {
    // data[]是层序序列，degree[]是每个结点的度，n是树结点个数
    CSTNode **temp = (CSTNode **)malloc(sizeof(CSTNode) * length);  // 创建临时数组
    for (int i = 0; i < length; i++) {                              // 把每一个节点放进临时数组
        temp[i] = (CSTNode *)malloc(sizeof(CSTNode));
        temp[i]->data = data[i];
        temp[i]->lchild = temp[i]->rbro = NULL;  // 初始化兄弟与孩子结点
    }
    // 构造完临时数组之后我们得到了层序序列的结点数组
    // 接下来我们根据结点的度来确定每一个结点的儿子与儿子的兄弟结点
    int index = 0;  // 指向数组还未操作的结点
    for (int i = 0; i < length; i++) {
        // 找当前结点i的第一个儿子与它的儿子兄弟
        // 首先要知道叶子结点的是没有兄弟和孩子的所以先进行一个判断
        // 注:叶子结点的度数为0
        if (degree[i] == 0)
            continue;  // 如果是叶子节点，什么都不做，进入下一次循环
        // 若不是叶子结点 开始找儿子：
        ++index;
        temp[i]->lchild = temp[index];  // 首先找到第一个儿子结点
        // 然后给第一个儿子结点找兄弟结点
        // 注意 j=2 表示的是 从第二个孩子开始 一共有 degree[i]孩子 degree[i]是度数
        for (int j = 2; j <= degree[i]; j++) {
            temp[index]->rbro = temp[index + 1];
            // index + 1 为下一个孩子结点
            // 剩下的孩子结点依次是上一个孩子的右兄弟
            ++index;  // 由于index指向数组还未操作的结点，因此index自增
        }
    }
    // 找完所有孩子结点与孩子的兄弟结点后就返回头指针
    T = *temp;  // 注意这里是函数参数返回的
    free(temp);
}

void visit(CSTree T) {
    std::cout << T->data << " ";
}

void PostOrder(CSTree T) {
    if (T == NULL)
        return;
    PostOrder(T->lchild);
    PostOrder(T->rbro);
    visit(T);
}

void InOrder(CSTree T) {
    if (T == NULL)
        return;
    InOrder(T->lchild);
    visit(T);
    InOrder(T->rbro);
}

void PreOrder(CSTree T) {
    if (T == NULL)
        return;
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rbro);
}

void test(ElemType *levelOrder, int *degree, int length) {
    CSTree T;
    createCSTree_Degree(T, levelOrder, degree, length);

    PreOrder(T);
    cout << endl;

    InOrder(T);
    cout << endl;

    PostOrder(T);
    cout << endl;
}

int main() {
    // 非满二叉树、非完全二叉树
    ElemType levelOrder[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int degree1[] = {3, 2, 0, 1, 0, 0, 0};
    int length1 = sizeof(levelOrder) / sizeof(levelOrder[0]);

    test(levelOrder, degree1, length1);

    return 0;
}

// 运行结果：
// A B E F C D G
// E F B C G D A
// F E G D C B A
