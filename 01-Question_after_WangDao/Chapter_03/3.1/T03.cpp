// 2020-09-11 第二次修订
#include <stack>
#include <iostream>
using namespace std;

bool isLegal(char *A, int length) {
    stack<char> s;
    for (int i = 0; i < length; i++) {
        if (A[i] == 'I')
            s.push(A[i]);
        else {
            if (s.empty())
                return false;
            char temp = s.top();
            s.pop();
            if (temp != 'I')
                return false;
        }
    }
    return s.empty();
}

void test(char *c, int length) {
    if (isLegal(c, length))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

int main() {
    char c1[] = {'I', 'O', 'I', 'I', 'O', 'I', 'O', 'O'};
    char c2[] = {'I', 'O', 'O', 'I', 'O', 'I', 'I', 'O'};
    char c3[] = {'I', 'I', 'I', 'O', 'I', 'O', 'I', 'O'};
    char c4[] = {'I', 'I', 'I', 'O', 'O', 'I', 'O', 'O'};

    test(c1, sizeof(c1) / sizeof(char));
    test(c2, sizeof(c2) / sizeof(char));
    test(c3, sizeof(c3) / sizeof(char));
    test(c4, sizeof(c4) / sizeof(char));

    return 0;
}

// 输出结果：
// true
// false
// false
// true


//----------------------------------------------------------------
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

