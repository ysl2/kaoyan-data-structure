void reverse(LinkList &L, int left, int right) {
    for (int i = left; i < (right - left + 1) / 2; i++) {
        int temp = L.data[left + i];
        L.data[left + i] = L.data[right - i];
        L.data[right - i] = temp;
    }
}

void func(LinkList &L) {
    reverse(L, 0, L.length - 1);
}

