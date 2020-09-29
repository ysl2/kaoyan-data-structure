// 在王道知识点里的堆排序中，有更详细的说明
bool is_heap(int tree[], int n) {
    if (n % 2 == 0) {
        if (tree[n / 2] > tree[n])
            return false;
        for (int i = n / 2 - 1; i >= 1; i--) {
            if (tree[i] > tree[2 * i] || tree[i] > tree[2 * i + 1])
                return false;
        }
    } else {
        for (int i = n / 2; i >= 1; i--) {
            if (tree[i] > tree[2 * i] || tree[i] > tree[2 * i + 1])
                return false;
        }
    }
    return true;
}
