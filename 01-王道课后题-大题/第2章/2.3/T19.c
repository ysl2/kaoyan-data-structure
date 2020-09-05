// 2020.08.30 第二次修订
// 双指针：
void outPut(CLinkList &L) {
    // L是循环单链表，注意循环退出条件
    while (L->next != L) {
		// pre和minpre都是前驱结点。
		// 因为是单链表，不能直接拿当前结点。否则连不上了，只能拿前驱
        CLinkNode *pre = L;
        CLinkNode *minpre = L;
        while (pre->next != L) {
            if (pre->next->data < minpre->next->data) {
                minpre = pre;  // 捕获最小值
            }
            pre = pre->next;  //继续筛查
        }
        // 访问最小值结点
        visit(minpre->next);
        // 重连最小值结点的前驱和后继。目的是把最小值结点摘下来
        CLinkNode *temp = minpre->next;
        minpre->next = minpre->next->next;
        // 删除最小值结点
        free(temp);
    }
    // 删除L
    free(L);
}
----------------------------------------------
// 四指针：
void outPut(CLinkList &L) {
    while (L->next != L) {
        CLinkNode *pre = L, *p = L->next;
        CLinkNode *minpre = L, *minp = L->next;
        while (p != L) {
            if (p->data < minp->data) {
                minp = p;
                minpre = pre;
            }
            pre = p;
            p = p->next;
        }
        visit(minp);
        minpre->next = minp->next;
        free(minp);
    }
    free(L);
}

