// 2020-10-11
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

// 在知识点文件夹里有这个题
bool getReverseKthNode(LinkList L, int k, LinkNode *&result) {
    if (k <= 0 || L == NULL || L->next == NULL)
        return false;
    LinkNode *p = L->next;
    int i = 0;
    for (; i < k && p != NULL; i++)  // 这里其实也可以直接让k--，但是这样不容易计算边界。因此保险起见还是用最传统的for正向遍历方式。
        p = p->next;
    if (p == NULL && i < k)  // 需要注意的是对于第一个结点（也就是倒数最后一个结点）的判断。
        return false;
    result = L->next;  // result的初始位置应该与p的初始位置相同，这样可以保证二者的相对距离是k
    while (p != NULL) {
        p = p->next;
        result = result->next;
    }
    return result != NULL;
}

void test(ElemType a[], int length, int k) {
    LinkList L = rearInsertCreate(a, length);
    LinkNode *result;
    if (getReverseKthNode(L, k, result) == true)
        cout << result->data << endl;
    else
        cout << "false" << endl;
}

int main() {
    ElemType arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(arr) / sizeof(int);

    test(arr, length, 3);
    test(arr, length, 10);
    test(arr, length, 9);
    test(arr, length, 0);
    test(arr, length, 1);

    return 0;
}

// 输出结果：
// 7
// false
// 1
// false
// 9


// ----------------------------------------------------------------------------
// 2020-09-07 第三次修订
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

LinkList L;

LinkNode *get(LinkList &L, int k) {  // 返回指针的函数
    if (k < 1 || L == NULL) return NULL;
    LinkNode *p = L;
    LinkNode *pre = L;
    for ( ; p != NULL && k > 0; p = p->next, k--);
    if (p == NULL && k > 0) return NULL;  // 如果中途由于空结点被打断，返回NULL
    for ( ; p != NULL; pre = pre->next, p = p->next);
    return pre;
}

// // leetcode执行通过
// // https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/submissions/

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
//  */


// struct ListNode* getKthFromEnd(struct ListNode* head, int k){
//     if (k < 1 || head == NULL) return NULL;
//     struct ListNode *p = head;
//     struct ListNode *pre = head;
//     for ( ; p != NULL && k > 0; p = p->next, k--);
//     if (p == NULL && k > 0) return NULL;
//     for ( ; p != NULL; pre = pre->next, p = p->next);
//     return pre;
// }

// ----------------------------------------------------------------------------

// 2020-09-02 第二次修订
typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

LinkList L;

// 定义2个指针，quick，slow
// 先让quick往后跑k次
// quick 和 slow一起跑，直到quick跑到结尾
// slow位置，即为倒数第k个数
ElemType getK(LinkList &L, int k) {
// 快慢指针，pre是慢指针，p是快指针
    if (L == NULL || L->next == NULL) return NULL;
    LinkNode *pre = L->next, *p = L->next;
    while(k > 0 && p != NULL) {
        p = p->next;
        k--;
    }
	if (k > 0) return NULL;  // 链表长度不够k个，不能继续查找
    // if (p == NULL) return L->next->data; 这一句可以不用写，下面的情况包括了
    while (p != NULL) {
        p = p->next;
        pre = pre->next;
    }
    return pre->data;
}

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* getKthFromEnd(ListNode* head, int k) {
//         if(head == NULL)    return NULL;
//         ListNode* quick = head;
//         ListNode* slow = head;
//         while(k-- && quick)
//         {
//             quick = quick->next;
//         }
//         if(quick == NULL)   return head;

//         while(quick)
//         {
//             quick = quick->next;
//             slow = slow->next;
//         }
//         return slow;
//     }
// };

// 作者：qingconglaixueit
// 链接：https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/solution/c-shuang-zhi-zhen-by-qingconglaixueit/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// --------------------------------------------------------
typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *link;
} LinkNode, *LinkList;

int search(LinkList list, int k) {
    LinkNode *p = list->link, *q = list->link;
    int count = 0;
    while (p != NULL) {
        if (count < k) {
            count++;
        } else {
            q = q->link;
        }
        p = p->link;
    }
    if (count < k) {
        return 0;
    }
    printf("%d", q->data);
    return 1;
}
