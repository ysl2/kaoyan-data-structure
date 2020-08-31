bool delete(SqList &L, ElemType s, ElemType t) {
    if (L.length == 0 || s >= t) {
        return false;
    }
    int k;
    for (int i = 0; i < L.length; i++) {
        if (A[i] >= s && A[i] <= t) {
            k++;
        } else {
            L.data[i - k] = L.data[i];
        }
    }
    L.length -= k;
    return true;
}

