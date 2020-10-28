#include <vector>
#include <iostream>
using namespace std;

vector<int> getNumberDevidedBySevenOrEleven(int target) {
    vector<int> result;
    for (int i = 7, j = 11; i <= target || j <= target; i += 7, j += 11) {
        if (i <= target)
            result.push_back(i);
        if (i != j && j <= target)
            result.push_back(j);
    }
    return result;
}

void test(int target) {
    vector<int> result = getNumberDevidedBySevenOrEleven(target);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}

int main() {
    int number1 = 30;

    test(number1);

    return 0;
}

// 输出结果：
// 7 11 14 22 21 28
