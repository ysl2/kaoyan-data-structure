typedef struct Node {
    int data;
    struct Node *link;
} LinkNode, *LinkList;

void func(LinkNode *L, int n) {
    LinkNode *p = L, *r;
    int *B, m;
    B = (int *) malloc(sizeof(int) * (n + 1));
    memset(B, 0, sizeof(int) * (n + 1));
    while (p->link != NULL) {
        m = (p->link->data > 0)? (p->link->data) : (-1) * (p->link->data);
        if (*(B + m) == 0) {
            *(B + m) = 1;
            p = p->link;
        } else {
            r = p->link;
            p->link = r->link;
            free(r);
        }
    }
    free(B);
}
