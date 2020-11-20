// 本题是链表排序，属于常规知识点
// 在排序文件夹内的链表排序内，已经实现了几种排序，任选一种即可
// 以下是类声明

template <class T>
class ChainNode {
    // friend Chain<T>;  // 山大有这句，但是加上之后报错，不知道什么原因。所以暂时注释掉

   private:
    T data;
    ChainNode<T> *link;
};
template <class T>
class Chain {
   public:
    Chain() {
        first = 0;
    }
    ~Chain();

   private:
    ChainNode<T> *first;
};
