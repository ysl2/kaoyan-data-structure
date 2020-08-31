// 2020.08.30 第二次修订
void getCommon(LinkList &A, LinkList &B) {
    LinkNode *p = A->next;
    LinkNode *q = B->next;
    A->next = NULL;  // 初始化A
    LinkNode *r = A;  // A的尾指针
    while (p != NULL && q != NULL) {
        if (p->data == q->data) {
            // 把p添加到A中（尾插），p也向后移动
            r->next = p;
            r = r->next;
            p = p->next;
            // 删除当前的q，然后把q顺移
			// 因为元素递增排列，所以前驱肯定没有了，不用管前驱
            LinkNode *temp = q->next;
            free(q);
            q = temp;
			continue; // ★这个continue必须要加，否则下面的代码还会跑
        }
        // 下面这两个if，表示只要不是交集的结点，就全删掉
        if (P->data < q->data) {
            LinkNode *temp = p->next;
            free(p);
            p = temp;
        } else {
            LinkNode *temp = q->next;
            free(q);
            q = temp;
        }
    }
    r->next = NULL;  // 封住A的尾巴
    // 把剩下的全删干净
    while (p != NULL) {
        LinkNode *temp = p->next;
        free(p);
        p = temp;
    }
    while (q != NULL) {
        LinkNode *temp = q->next;
        free(q);
        q = temp;
    }
    free(B);
}
------------------------------------------------------------
LinkList myUnion(LinkList &A, LinkList &B) {
    LinkNode *p = A->next;
    LinkNode *q = B->next;
    LinkNode *r = A;
    LinkNode *temp;
    while (p != NULL && q != NULL) {
        if (p->data == q->data) {
            r->next = p;
            r = p;
            p = p->next;
            temp = q;
            q = q->next;
            free(temp);
        } else if (p->data < q->data) {
            temp = p;
            p = p->next;
            free(temp);
        } else {
            temp = q;
            q = q->next;
            free(temp);
        }
    }
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
    while (q != NULL) {
        temp = q;
        q = q->next;
        free(q);
    }
    r->next = NULL;
    free(B);
    return A;
}
时间复杂度: O(len(A) + len(B)) ; 空间复杂度: O(1)

