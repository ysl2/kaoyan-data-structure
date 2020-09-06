// 2020-09-06 第二次修订
typedef int ElemType;
typedef struct DCLinkNode {
    ElemType data;
    struct DCLinkNode *prior, *next;
} DCLinkNode, *DCLinkList;

DCLinkList L;

bool isSym(DCLinkList &L) {  // Double Circle LinkList
    DCLinkNode *p = L->next;
    DCLinkNode *q = L->prior;
    // L如果是奇数个结点，最终会判断p == q
    // L如果是偶数个结点，最终会判断p->next == q
    // 但上述两个情况不会同时发生，因此写在一起不会发生冲突
    for ( ; p->data == q->data && (p->next != q && p != q) ; p = p->next, q = q->prior);
    // 和上面一样，只要奇数或者偶数满足其中一种情况即可
    // 无论哪种情况，都必须保证整个链表遍历完整，而不是因为有不相等的元素导致退出循环
    // 但是一旦有不相等的元素，必然会导致链表遍历不完整，也就是两个指针没碰头
    // 除了一种情况，就是链表偶数的时候，
    // 遍历到最后的位置时，两个指针刚好碰头，但是不能保证这两个data一定相等
    // 所以需要在最终的判断里体现出来这一个信息：
    return (p->next == q && p->data == q->data) || p == q;
}
-------------------------------------------------------------------------
int symmetry(DCLinkList L) {
    DCLinkNode *p = L->next, *q = L->prior;
    while (p != q && p->next != q) {  // 分别对应奇数和偶数个结点
        if (p->data == q->data) {
            p = p->next;
            q = q->prior;
        } else {
            return 0;
        }
    }
    return 1;
}

