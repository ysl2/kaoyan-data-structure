void func(int n) {  // time complexity: O(1)
    int x = 91;
    int y = 100;
    while (y > 0) {
        if (x > 100) {
            x = x - 10;
            y--;
        } else {
            x++;
        }
    }
}

int func1(int n) {  // time complexity: O(n!)
    if (n <= 1)
        return 1;
    return n * func1(n - 1);
}
