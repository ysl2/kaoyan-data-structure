ElemType getCommonAncestor(BiTree T, int i, int j) {
    if (T.data[i] == "#" || T.data[j] == "#")
        return NULL;
    while (i != j) {
        if (i > j)
            i /= 2;
        else
            j /= 2;
    }
    return T.data[i];
}
