主元素：大于数组的一半的数
摩尔投票法：
建立统计变量，然后依次遍历，只要是，变量+1，只要不是，
如果统计变量大于0，就减1; 如果统计变量小于0，换别的元素继续统计。
然后再遍历一遍看看筛出来的这个数到底是不是主元素。
（如果变量小于等于0，说明压根没筛出来，就直接等着返回就行了，不需要再遍历）

int majority(int A[]) {
    int count = 1;
    int mainElement = A[0];
    int i;
    for (i = 1; i < n, i++) {
        if (A[i] == mainElement) {
            count++;
        } else {  // 如果不相等
            if (count > 0) {
                count--;
            } else {  //count此时等于0
                mainElement = A[i];
                count = 1;
            }
        }
    }
    if (count > 0) {
        for (i = 0, count = 0; i < n; i++) {
            if (A[i] == mainElement) {
                count++;
            }
        }
    }
    return count > n / 2? mainElement : -1;
}

