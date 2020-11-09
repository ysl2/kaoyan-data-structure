#include <cstdlib>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef char ElemType;  // 把char强制转换成int。这样我可以使用上面写的测试用例，不然我还得重新写
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTNode *construct(ElemType *preOrder, ElemType *midOrder, int len) {
    if (preOrder == NULL || midOrder == NULL || len <= 0)
        return NULL;

    //先根遍历（前序遍历）的第一个值就是根节点的键值
    ElemType rootKey = preOrder[0];
    BiTree T = new BiTNode;
    T->data = rootKey;
    T->lchild = T->rchild = NULL;
    if (len == 1 && *preOrder == *midOrder)  //只有一个节点
        return T;

    //在中根遍历（中序遍历）中找到根节点的值
    ElemType *rootMidOrder = midOrder;
    int leftLen = 0;  //左子树节点数
    while (*rootMidOrder != rootKey && rootMidOrder <= (midOrder + len - 1)) {
        ++rootMidOrder;
        ++leftLen;
    }
    if (*rootMidOrder != rootKey)  //在中根序列未找到根节点,输入错误
        return NULL;

    if (leftLen > 0) {  //构建左子树
        T->lchild = construct(preOrder + 1, midOrder, leftLen);
    }
    if (len - leftLen - 1 > 0) {  //构建右子树
        T->rchild = construct(preOrder + leftLen + 1, rootMidOrder + 1, len - leftLen - 1);
    }
    return T;
}

void visit(BiTree T) {
    std::cout << T->data << " ";
}

void PostOrder(BiTree T) {
    if (T == NULL)
        return;
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    visit(T);
}

void InOrder(BiTree T) {
    if (T == NULL)
        return;
    InOrder(T->lchild);
    visit(T);
    InOrder(T->rchild);
}

void PreOrder(BiTree T) {
    if (T == NULL)
        return;
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}

int getMaxDepth(BiTree T) {
    if (T == NULL)
        return 0;
    int left = getMaxDepth(T->lchild);
    int right = getMaxDepth(T->rchild);
    return left > right ? left + 1 : right + 1;
}

// 以下是本文件的主代码，同时也是一个万能的模板代码。
// 把这段代码和2018 T02放在一起看，会发现它们思路完全一致
int top = -1;
ElemType pathStack[20];
void printPathUnderConditions1(BiTree T, int maxDepth) {
    if (T == NULL)
        return;
    pathStack[++top] = T->data;
    if (T->lchild == NULL && T->rchild == NULL) {
        if (top + 1 == maxDepth - 1) {  // 注意top是从-1开始算的，而栈的下标是从0开始。因此实际上的depth应该在top的基础上+1
            for (int i = 0; i <= top; i++)
                cout << pathStack[i] << " ";
            cout << endl;
            // 这里不加return，就可以打印出所有的路径
            // 如果题目要求只打印一条，就在这里加一个return即可
        }
    }
    printPathUnderConditions1(T->lchild, maxDepth);
    printPathUnderConditions1(T->rchild, maxDepth);
    top--;
}

// 下面这个是2018年真题T02
// 这里用vector模拟栈。不能直接用stack，因为无法对stack进行遍历，但却可以对vector进行遍历
// 实际考试的时候，vector就不要用了，直接用普通数组，弄个size变量记录数组里面的元素个数，再弄个top变量当作栈顶
vector<BiTNode *> v;

// 只要稍微改一下对于depth和maxDepth的判断条件，就可以变成“打印任意深度的路径”
// 甚至可以改成“从根节点到指定结点p之间的路径”，只要改一下if的条件即可（2017年第二题）
void printPathUnderConditions2(BiTree T, int maxDepth) {
    if (T == NULL)
        return;
    v.push_back(T);
    if (T->lchild == NULL && T->rchild == NULL) {
        if (v.size() == maxDepth - 1) {
            for (int i = 0; i < v.size(); i++)
                cout << v[i]->data << " ";  // 注意：这里仅仅是遍历栈，但并没有出栈。因此不能直接定义一个常规的栈，否则有可能导致栈下溢
            cout << endl;
            return;  // 如果这里不加return，就可以打印出所有的路径
        }
    }
    printPathUnderConditions2(T->lchild, maxDepth);
    printPathUnderConditions2(T->rchild, maxDepth);
    v.pop_back();  // 自下向上走，结点出栈
}
/*
    // 求从根节点到指定结点之间的路径（2017年第二题）
    void printPathUnderConditions2(BiTree T, BiTNode *p) {
        if (T == NULL)
            return;
        v.push_back(T);
        if (T == p) {
            for (int i = 0; i < v.size(); i++)
                cout << v[i]->data << " ";  // 注意：这里仅仅是遍历栈，但并没有出栈。因此不能直接定义一个常规的栈，否则有可能导致栈下溢
            cout << endl;
            return;  // 如果这里不加return，就可以打印出所有的路径
        }
        printPath(T->lchild, p);
        printPath(T->rchild, p);
        v.pop_back();  // 自下向上走，结点出栈
    }
*/

// 下面这个是我自己重写的2018 T02的代码，效果一样
// 应该说本文件的这三个代码，作用完全一致，只是形式上有不同
// 如果直接打印，实际顺序是逆序的（从叶子节点到根节点）。因此为了保证顺序不变，用栈做一个缓冲，先输出到栈里，然后通过栈打印
// 但是这种方法只能打印出一条路径。如果需要打印所有路径，依然应该选择第一种和第二种
stack<BiTNode *> s;

bool printPathUnderConditions3(BiTree T, int depth, int maxDepth) {
    if (T == NULL)
        return false;
    if (T->lchild == NULL && T->rchild == NULL && depth == maxDepth - 1) {
        s.push(T);
        return true;
    }
    if (printPathUnderConditions3(T->lchild, depth + 1, maxDepth) || printPathUnderConditions3(T->rchild, depth + 1, maxDepth)) {
        s.push(T);
        return true;
    }
    return false;
}

/*
    // 求从根节点到指定结点之间的路径（2017年第二题）
    bool printPathUnderConditions3(BiTree T, ElemType x) {
        if (T == NULL)
            return false;
        if (T->data == x)
            return true;
        if (printAllAncestor(T->lchild, x) || printAllAncestor(T->rchild, x)) {
            s.push(T);
            return true;
        }
        return false;
    }
*/

void visitStack(stack<BiTNode *> &s) {
    while (!s.empty()) {
        cout << s.top()->data << " ";
        s.pop();
    }
    cout << endl;
}

// 补充：完全非递归方法，打印结点x的所有祖先
bool check(stack<BiTNode *> s1, BiTree p, ElemType x) {
    if (p->data != x)
        return false;
    while (!s1.empty()) {
        BiTNode *temp = s1.top();
        s1.pop();
        cout << temp->data << " ";
    }
    return true;
}

void printAllAncestor(BiTree T, ElemType x) {
    stack<BiTNode *> s1;
    BiTNode *p = T;
    BiTNode *r = NULL;
    while (p != NULL || !s1.empty()) {
        if (p != NULL) {
            s1.push(p);
            p = p->lchild;
        } else {
            p = s1.top();
            if (p->rchild != NULL && p->rchild != r)
                p = p->rchild;
            else {
                s1.pop();
                if (check(s1, p, x) == true)
                    return;
                r = p;
                p = NULL;
            }
        }
    }
}

void test(ElemType *preOrder, ElemType *inOrder, int length, ElemType value) {
    BiTree T = construct(preOrder, inOrder, length);

    PreOrder(T);
    cout << endl;

    InOrder(T);
    cout << endl;

    PostOrder(T);
    cout << endl;

    cout << endl;

    // 1
    printPathUnderConditions1(T, getMaxDepth(T));
    cout << endl;
    // 2
    printPathUnderConditions2(T, getMaxDepth(T));
    cout << endl;
    // 3
    printPathUnderConditions3(T, 1, getMaxDepth(T));
    visitStack(s);
    cout << endl;
    // 4
    printAllAncestor(T, value);
    cout << endl;
    cout << "------------------------------" << endl;
}

int main() {
    ElemType preOrder1[] = {'B', 'E', 'F', 'C', 'G', 'D', 'H'};
    ElemType inOrder1[] = {'F', 'E', 'B', 'G', 'C', 'H', 'D'};
    int length1 = sizeof(preOrder1) / sizeof(ElemType);
    ElemType preOrder2[] = {'B', 'E', 'F', 'H', 'C', 'G', 'D'};
    ElemType inOrder2[] = {'F', 'E', 'H', 'B', 'G', 'C', 'D'};
    int length2 = sizeof(preOrder2) / sizeof(ElemType);

    test(preOrder1, inOrder1, length1, 'H');

    test(preOrder2, inOrder2, length2, 'H');

    return 0;
}

// 运行结果：
// B E F C G D H
// F E B G C H D
// F E G H D C B
//
// B E F
// B C G
//
// B E F
//
// B E F
//
// D C B
// ------------------------------
// B E F H C G D
// F E H B G C D
// F H E G D C B
//
//
//
//
//
// E B
// ------------------------------
