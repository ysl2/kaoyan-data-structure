void searchExchangeInsert(SqList &L, ElemType x) {
    int low = 0, high = L.length - 1, mid;
    bool flag = search(L, low, high, x, mid);
    if (flag == true && mid != L.length - 1) {
        exchange(L, mid, mid + 1);
        return ;
    }
    insert(L, high, x);
}

bool search(SqList &L, int &low, int &high, ElemType x, int &mid) {
    bool flag = false;
    while (low <= high) {
        mid  = (low + high) / 2;
        if (L.data[mid] == x) {
            flag = true;
            break ;
        }
        if (L.data[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return flag;
}

void exchange(SqList &L, int i, int j) {
    int temp = L.data[i];
    L.data[i] = L.data[j];
    L.data[j] = temp;
}

void insert(SqList &L, int location, ElemType x) {
    int j;
    for (j = L.length; j > location; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[j] = x;
}

