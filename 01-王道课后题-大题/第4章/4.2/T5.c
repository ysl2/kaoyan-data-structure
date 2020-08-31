ElemType common(SqTree T, int i, int j) {
    if (T[i] == '#' || T[j] == '#') {
        return NULL;
    }
    while (i != j) {
        if(i > j) {
            i /= 2;
        } else {
            j /= 2;
        }
    }
    return T[i];
}

