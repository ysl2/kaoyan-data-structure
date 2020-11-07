#include <iostream>
#include <stack>
using namespace std;

void outPut(char *A, int length) {
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

// 目标：字符串里有S和H，把所有的S都调整到H之前
void Train_Arrange(char train[], int length) {  // 这里的length就是题中说的n
    stack<char> s;
    int i = 0;
    for (int j = 0; j < length; j++) {
        if (train[j] == 'H')
            s.push(train[j]);  // 把H放入栈中
        else
            train[i++] = train[j];  // 把S调到前部
    }
    while (!s.empty()) {
        char temp = s.top();
        s.pop();
        train[i++] = temp;  // 把H接在后部
    }
}

int main() {
    char arr[] = {'S', 'H', 'S', 'H', 'S', 'H', 'S', 'H', 'S'};
    int length = sizeof(arr) / sizeof(char);
    Train_Arrange(arr, length);
    outPut(arr, length);
}

// 输出结果：
// S S S S S H H H H
