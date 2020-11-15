#include <vector>
#include <iostream>
using namespace std;

// 这个是我自己写的
vector<int> getNumberDevidedBySevenOrEleven1(int target, int dividend1, int dividend2) {
    vector<int> result;
    for (int i = dividend1, j = dividend2; i <= target || j <= target; i += dividend1, j += dividend2) {
        if (i <= target)
            result.push_back(i);
        if (i != j && j <= target)
            result.push_back(j);
    }
    return result;
}

// 这个是山大资料里给的答案，相比我自己写的，这个更简单，而且这个的答案是从小到大排序的
vector<int> getNumberDevidedBySevenOrEleven2(int target, int dividend1, int dividend2) {
    vector<int> result;
    for (int i = 1; i <= target; i++) {
        if (i % dividend1 == 0 || i % dividend2 == 0)
            result.push_back(i);
    }
    return result;
}

void test(int target, int dividend1, int dividend2, int index) {
    vector<int> result;
    if (index == 1)
        result = getNumberDevidedBySevenOrEleven1(target, dividend1, dividend2);
    if (index == 2)
        result = getNumberDevidedBySevenOrEleven2(target, dividend1, dividend2);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
}

int main() {
    int number1 = 30;

    test(number1, 7, 11, 1);
    test(number1, 7, 11, 2);

    return 0;
}

// 输出结果：
// 7 11 14 22 21 28
// 7 11 14 21 22 28
