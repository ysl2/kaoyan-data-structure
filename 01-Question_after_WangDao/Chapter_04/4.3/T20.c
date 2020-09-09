void BiTreeToExpression(BiTree T) {
    InOrder(T, 1);
}
void InOrder(BiTree T, int depth) {
    if (T == NULL) {
        return ;
    }
    if (T->lchlid == NULL && T->rchild == NULL) {
        visit(T);
        return ;  // 一定不要漏这个return，不然程序直接出错
    }
    if (depth > 1) {
        printf("(");
    }

    // 中序遍历模板
    InOrder(T->lchild, depth + 1);
    visit(T);
    InOrder(T->rchild, depth + 1);
    //
    
    if (depth > 1) {
        printf(")");
    }
}

void visit(BiTree T) {
    printf("%s", T->data);
}

