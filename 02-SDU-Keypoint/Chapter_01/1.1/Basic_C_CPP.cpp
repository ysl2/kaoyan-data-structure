#include <stdio.h>
void func(int &k) {
    int *p, j = 5;
    p = &j;

    delete new int[5];  // dynamic allocate

    int a[10] = {0, 1, 2};
    int *p1 = a;

    int i = 0;
    while (i < 10) {
        printf("%d", *p1);
        p++;
        i++;
    }
}
