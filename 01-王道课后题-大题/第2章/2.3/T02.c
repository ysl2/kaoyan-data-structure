void deletex(LinkList &L, ElemType x) {
    LinkNode *pre = L, *p = L->next;
    while (p != NULL) {
        if (p->data == x) {
            LinkNode *temp = p;
            p = p->next;
            pre->next = p;
            free(temp);
        } else {
            pre = p;
            p = p->next;
        }
    }
}



// 我自己写的代码：（采用kmp算法的思想）
typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

LinkList L;

void deleteALL(LinkList &L, ElemType x) {
    if (L == NULL || L->next == NULL) return ;
    LinkList record = L;
    while (record->next != NULL) {
        LinkNode *p;  // p是值为x的结点的前驱结点
        if (Locate(record, p, x)) delete(record, p);
        record = p;
    }
}

// p是前驱指针
bool Locate(LinkList &L, LinkNode *&p, ElemType x) {
    bool flag = false;
    p = L;
    while (p->next != NULL) {
        if (p->next->data == x) {
            flag = true;
            break;
        }
        p = p->next;
    }
    return flag;
}

// p是前驱指针
void delete(LinkList &L, LinkNode *&p) {
    LinkNode *temp = p->next;
    p->next = temp->next;
    free(temp);
}

