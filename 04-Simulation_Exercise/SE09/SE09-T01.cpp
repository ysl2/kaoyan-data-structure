#include <iostream>
using namespace std;

// 本题是数组插入排序，但是题目要求用C++的面向对象方式表述

// 基于公式化表述的类LinearList的声明
template <class T>
class LinearList {
   public:
    void insertionSort();
    void printList();
    LinearList(int);  // 构造函数
    ~LinearList();  // 析构函数

   private:
    int length;
    T *element;  // 一维动态数组
};

// 构造函数
template <class T>
LinearList<T>::LinearList(int length) {
    LinearList::length = length;
    element = new T[LinearList::length];
    for (int i = 0; i < LinearList::length; i++)
        LinearList::element[i] = length - i;
}

// 析构函数
template <class T>
LinearList<T>::~LinearList() {
    cout << "The class has been deleted." << endl;
    delete[] element;
}

// 成员函数
template <class T>
void LinearList<T>::insertionSort() {
    for (int i = 1; i < LinearList::length; i++) {
        int temp = LinearList::element[i];
        int j;
        for (j = i - 1; j >= 0 && LinearList::element[j] > temp; j--)
            LinearList::element[j + 1] = LinearList::element[j];
        LinearList::element[j + 1] = temp;
    }
}

// 成员函数
template <class T>
void LinearList<T>::printList() {
    for (int i = 0; i < LinearList::length; i++)
        cout << LinearList::element[i] << " ";
    cout << endl;
}

int main() {
    LinearList<int> list(10);
    list.insertionSort();
    list.printList();
    return 0;
}

//运行结果
// 1 2 3 4 5 6 7 8 9 10
// The class has been deleted.
