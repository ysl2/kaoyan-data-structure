// 2020-10-10
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct CLinkNode {  // Circle
    ElemType data;
    struct CLinkNode *next;
} CLinkNode, *CLinkList;

void outPut(CLinkList L) {
    CLinkNode *p = L->next;
    while (p != L) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

CLinkList rearInsertCreateCircleList(ElemType arr[], int length) {
    CLinkList L = new CLinkNode;
    CLinkNode *r = L;
    for (int i = 0; i < length; i++) {
        CLinkNode *s = new CLinkNode;
        s->data = arr[i];
        r->next = s;
        r = s;
    }
    r->next = L;
    return L;
}

// 注意审题：
//      1. 循环单链表
//      2. 值全都是正整数
void printMinValueAndDeleteList(CLinkList &L) {
    if (L == NULL)
        return;
    while (L->next != L) {
        CLinkNode *minpre = L;
        CLinkNode *pre = L;
        while (pre->next != L) {
            if (pre->next->data < minpre->next->data)
                minpre = pre;
            pre = pre->next;
        }
        CLinkNode *temp = minpre->next;
        minpre->next = temp->next;
        cout << temp->data << " ";
        delete temp;
    }
    delete L;
}

void test(int arr[], int length) {
    CLinkList A = rearInsertCreateCircleList(arr, length);

    printMinValueAndDeleteList(A);
    cout << endl;
}

int main() {
    ElemType arr1[] = {1, 2, 3, 4};
    int length1 = sizeof(arr1) / sizeof(int);
    ElemType arr2[] = {4, 3, 2, 1};
    int length2 = sizeof(arr2) / sizeof(int);
    ElemType arr3[] = {};
    int length3 = sizeof(arr3) / sizeof(int);
    ElemType arr4[] = {1, 3, 5, 7, 9, 2, 4, 6, 8};
    int length4 = sizeof(arr4) / sizeof(int);

    test(arr1, length1);
    test(arr2, length2);
    test(arr3, length3);
    test(arr4, length4);

    return 0;
}

// 输出结果：
// 1 2 3 4
// 1 2 3 4
//
// 1 2 3 4 5 6 7 8 9


// --------------------------------------------------------------------
// 2020.08.30 第二次修订
// 双指针：
void outPut(CLinkList &L) {
    // L是循环单链表，注意循环退出条件
    while (L->next != L) {
		// pre和minpre都是前驱结点。
		// 因为是单链表，不能直接拿当前结点。否则连不上了，只能拿前驱
        CLinkNode *pre = L;
        CLinkNode *minpre = L;
        while (pre->next != L) {
            if (pre->next->data < minpre->next->data) {
                minpre = pre;  // 捕获最小值
            }
            pre = pre->next;  //继续筛查
        }
        // 访问最小值结点
        visit(minpre->next);
        // 重连最小值结点的前驱和后继。目的是把最小值结点摘下来
        CLinkNode *temp = minpre->next;
        minpre->next = minpre->next->next;
        // 删除最小值结点
        free(temp);
    }
    // 删除L
    free(L);
}
// --------------------------------------------------------------------
// 四指针：
void outPut(CLinkList &L) {
    while (L->next != L) {
        CLinkNode *pre = L, *p = L->next;
        CLinkNode *minpre = L, *minp = L->next;
        while (p != L) {
            if (p->data < minp->data) {
                minp = p;
                minpre = pre;
            }
            pre = p;
            p = p->next;
        }
        visit(minp);
        minpre->next = minp->next;
        free(minp);
    }
    free(L);
}

