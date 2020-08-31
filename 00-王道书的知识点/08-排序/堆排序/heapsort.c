#define N 1086
void swap(int a[], int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}
void heapify(int tree[], int n, int i) {  // 从第 i 个 开始做 heapify 
    if (i >= n)
        return;
    int c1 = 2 * i + 1;
    int c2 = 2 * i + 2;
 
    int max = i;
    if (c1 < n && tree[c1] > tree[max])
        max = c1;
    if (c2 < n && tree[c2] > tree[max])
        max = c2;
    if (max != i) {
        swap(tree, max, i);
        heapify(tree, n, max);
    }
}
void build_heap(int tree[], int n) {
    int last_node = n - 1;
    int parent = (last_node - 1) / 2;
 
    for (int i = parent; i >= 0; i--)
        heapify(tree, n, i);
}
void heap_sort(int tree[], int n) {
    build_heap(tree, n);
    
    for (int i = n - 1; i >= 0; i--) {
        swap(tree, i, 0);
        heapify(tree, i, 0);
    }
}
int main(void) {
    int a[N] = { 0 };
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
 
    heap_sort(a, n);
 
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    puts("");
    system("pause");
    return 0;
}