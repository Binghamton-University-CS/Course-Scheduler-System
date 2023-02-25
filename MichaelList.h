template <class T>
class MichaelList {
  public:
    MichaelList();
    add(T val);
    bool remove(T val);
    int find(T val);
  private:
    T* array;
    int size;
    int lastIndex;
};
