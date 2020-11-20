template <class T>
class String {
   public:
    String(int maxSize = 10);
    ~String() {
        delete[] data;
    }

   private:
    int length;
    int maxSize;
    T *data;
};
