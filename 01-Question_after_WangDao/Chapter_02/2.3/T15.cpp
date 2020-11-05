// 2020-10-09
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

void outPut(LinkList L) {
    LinkNode *p = L->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void rearInsert(LinkList &L, ElemType x) {
    LinkNode *s = new LinkNode;
    s->data = x;
    L->next = s;
    L = s;
}

LinkList rearInsertCreate(ElemType arr[], int length) {
    LinkList L = new LinkNode;
    LinkNode *p = L;
    for (int i = 0; i < length; i++)
        rearInsert(p, arr[i]);
    p->next = NULL;
    return L;
}

// 注：本题还需要删除所有多余的结点和空间
void getCommon(LinkList &A, LinkList &B) {
    if (A == NULL || B == NULL) {
        A = NULL;
        return;
    }
    LinkNode *p = A->next;
    A->next = NULL;
    LinkNode *r = A;
    LinkNode *q = B->next;
    B->next = NULL;
    delete B;
    while (p != NULL && q != NULL) {
        if (p->data == q->data) {
            r->next = p;
            r = r->next;
            p = p->next;
            LinkNode *temp = q->next;
            delete q;
            q = temp;
        } else if (p->data < q->data) {
            LinkNode *temp = p->next;
            delete p;
            p = temp;
        } else {
            LinkNode *temp = q->next;
            delete q;
            q = temp;
        }
    }
    r->next = NULL;
    while (p != NULL) {
        LinkNode *temp = p->next;
        delete p;
        p = temp;
    }
    while (q != NULL) {
        LinkNode *temp = q->next;
        delete q;
        q = temp;
    }
}

void test(ElemType a1[], int length1, ElemType a2[], int length2) {
    LinkList L1 = rearInsertCreate(a1, length1);
    LinkList L2 = rearInsertCreate(a2, length2);

    getCommon(L1, L2);

    outPut(L1);
}

int main() {
    ElemType arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length1 = sizeof(arr1) / sizeof(int);
    ElemType arr2[] = {2, 4, 6, 8};
    int length2 = sizeof(arr2) / sizeof(int);
    ElemType arr3[] = {};
    int length3 = sizeof(arr3) / sizeof(int);

    test(arr1, length1, arr2, length2);
    test(arr2, length2, arr3, length3);

    return 0;
}

// 输出结果：
// 2 4 6 8
//

// //--------------------------------------------------------------------
// // 2020.08.30 第二次修订
// void getCommon(LinkList &A, LinkList &B) {
//     LinkNode *p = A->next;
//     LinkNode *q = B->next;
//     A->next = NULL;  // 初始化A
//     LinkNode *r = A;  // A的尾指针
//     while (p != NULL && q != NULL) {
//         if (p->data == q->data) {
//             // 把p添加到A中（尾插），p也向后移动
//             r->next = p;
//             r = r->next;
//             p = p->next;
//             // 删除当前的q，然后把q顺移
// 			// 因为元素递增排列，所以前驱肯定没有了，不用管前驱
//             LinkNode *temp = q->next;
//             free(q);
//             q = temp;
//         } else if (P->data < q->data) { // 下面这两个if，表示只要不是交集的结点，就全删掉
//             LinkNode *temp = p->next;
//             free(p);
//             p = temp;
//         } else {
//             LinkNode *temp = q->next;
//             free(q);
//             q = temp;
//         }
//     }
//     r->next = NULL;  // 封住A的尾巴
//     // 把剩下的全删干净
//     while (p != NULL) {
//         LinkNode *temp = p->next;
//         free(p);
//         p = temp;
//     }
//     while (q != NULL) {
//         LinkNode *temp = q->next;
//         free(q);
//         q = temp;
//     }
//     free(B);
// }
// ------------------------------------------------------------
// LinkList myUnion(LinkList &A, LinkList &B) {
//     LinkNode *p = A->next;
//     LinkNode *q = B->next;
//     LinkNode *r = A;
//     LinkNode *temp;
//     while (p != NULL && q != NULL) {
//         if (p->data == q->data) {
//             r->next = p;
//             r = p;
//             p = p->next;
//             temp = q;
//             q = q->next;
//             free(temp);
//         } else if (p->data < q->data) {
//             temp = p;
//             p = p->next;
//             free(temp);
//         } else {
//             temp = q;
//             q = q->next;
//             free(temp);
//         }
//     }
//     while (p != NULL) {
//         temp = p;
//         p = p->next;
//         free(temp);
//     }
//     while (q != NULL) {
//         temp = q;
//         q = q->next;
//         free(q);
//     }
//     r->next = NULL;
//     free(B);
//     return A;
// }
// 时间复杂度: O(len(A) + len(B)) ; 空间复杂度: O(1)

