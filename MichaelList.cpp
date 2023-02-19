template <class T>
class MichaelList {
  public:
    MichaelList() {
      array = new T[size];
    }
    add(T val) {
      if (lastIndex == size - 1) {
        T* temp = new T[size * 2];
        for (int i = 0; i < size; i++) {
          temp[i] = array[i];
        }
        delete array;
        array = temp;
        size *= 2;
      }
      lastIndex++;
      array[lastIndex] = val;
    }
    remove(T val) {
      
    }
  private:
    T* array;
    int size = 100;
    int lastIndex;
};
