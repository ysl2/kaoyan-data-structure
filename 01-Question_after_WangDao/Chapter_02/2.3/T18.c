// 2020.08.30 第二次修订
void getLink(CLinkList &h1, CLinkList &h2) {
    // C表示Circle，指循环单链表
    CLinkNode *p = h1->next;
    while (p->next != h1) {
        p = p->next;
    }
    CLinkNode *q = h2->next;
    while (q->next != h2) {
        q = q->next;
    }
    p->next = h2;
    q->next = h1;
}


---------------------------------------------
LinkList Link(LinkList &A, LinkList &B) {
    LinkNode *p, *q;
    p = A;
    while (p->next != A) {
        p = p->next;
    }
    q = B;
    while (q->next != B) {
        q = q->next;
    }
    p->next = B;
    q->next = A;
    return A;
}

