bool delete(SqList &L)  {
    if (L == NULL || L.length == 0) {
        return false;
    }
    int i, j;
    for (i = 0, j = 1; j < L.length; j++) {
        if (L.data[i] != L.data[j]) {
            L.data[++i] = L.data[j];
        }
    }
    L.length = i + 1;
    return true;
}

