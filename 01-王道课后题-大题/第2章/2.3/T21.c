// 2020-09-02 第二次修订
typedef int ElemType;
typedef struct LinkNode{
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
    while(k >= 0 && p != NULL) {
        p = p->next;
        k--;
    }
    // if (p == NULL) return L->next->data; 这一句可以不用写
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
--------------------------------------------------------
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