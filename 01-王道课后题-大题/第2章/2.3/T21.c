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
