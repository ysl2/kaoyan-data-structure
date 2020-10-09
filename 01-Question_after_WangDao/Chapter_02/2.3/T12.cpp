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

// 先把L从第二个结点摘下来，然后依次将摘下来的第一个结点与L的尾结点判断
// 如果二者值相同，删除摘下来的第一个结点，向后继续比较
// 如果二者值不同，将摘下来的第一个结点尾插到L中
void deleteList1(LinkList &L) {
    if (L == NULL || L->next == NULL)
        return;
    LinkNode *p = L->next->next;
    LinkNode *r = L->next;
    while (p != NULL) {
        if (p->data == r->data) {
            LinkNode *temp = p;
            p = p->next;
            delete temp;
        } else {
            LinkNode *temp = p->next;
            r->next = p;
            r = r->next;
            p = temp;
        }
    }
    r->next = NULL;
}

// 王道书上的解法：
void deleteList2(LinkList &L) {
    if (L == NULL || L->next == NULL)
        return;
    LinkNode *p = L->next;
    while (p->next != NULL) {
        if (p->data == p->next->data) {
            LinkNode *temp = p->next;
            p->next = temp->next;
            delete temp;
        } else
            p = p->next;
    }
}

void test(ElemType a[], int length) {
    LinkList L1 = rearInsertCreate(a, length);
    LinkList L2 = rearInsertCreate(a, length);

    deleteList1(L1);
    deleteList2(L2);

    outPut(L1);
    outPut(L2);
}

int main() {
    ElemType arr[] = {0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2};
    int length = sizeof(arr) / sizeof(int);

    test(arr, length);

    return 0;
}

// 输出结果：
// 0 1 2
// 0 1 2

//-----------------------------------------------------------------------
void delete(LinkList &L) {
    if (L == NULL || L->next == NULL) {
        return ;
    }
    LinkNode *p = L->next;
    while (p->next != NULL) {
		if (p->data == p->next->data) {
			LinkNode *temp = p->next;
			p->next = temp->next;
            free(temp);
        } else {
            p = p->next;
        }
    }
}



