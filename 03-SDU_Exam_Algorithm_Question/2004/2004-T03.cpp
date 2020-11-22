#include <iostream>
#include <string.h>
using namespace std;

typedef int ElemType;

void outPut(ElemType *A, int length) {
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

void swap(ElemType *A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void sort(int ticket[], int ticketNumber, int peopleNumber) {
    int *people = new int[peopleNumber];
    memset(people, 0, sizeof(people) * peopleNumber);
    for (int i = 0; i < ticketNumber; i++)
        people[ticket[i]]++;
    for (int i = 0; i < peopleNumber; i++) {
        int maxIndex = 0;
        int maxValue = people[0];
        for (int j = 0; j < peopleNumber; j++) {
            if (people[j] >= 0 && people[j] >= maxValue) {
                maxValue = people[j];
                maxIndex = j;
            }
        }
        people[maxIndex] = -1;
        cout << maxIndex << " ";
    }
    delete[] people;
}

void test(int ticket[], int ticketNumber, int peopleNumber) {
    sort(ticket, ticketNumber, peopleNumber);
}

int main() {
    int ticket[] = {0, 0, 0, 1, 1, 1, 1, 2, 2, 2};
    int ticketNumber = sizeof(ticket) / sizeof(ticket[0]);

    int peopleNumber = 3;

    test(ticket, ticketNumber, peopleNumber);

    return 0;
}

// 输出结果：
// 1 2 0
