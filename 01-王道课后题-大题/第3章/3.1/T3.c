#include <stdbool.h>
bool judge(char A[], int n) {
    int i = 0;
    int j = 0, k = 0;
    while (A[i] != '\0') {
        switch(A[i]) {
            case 'I':
                j++;
                break;
            case 'O':
                k++;
                if (k > j) {
                    return false;
                }
        }
        i++;
    }
    return j == k;
}

