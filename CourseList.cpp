class CourseList {
  public:
    CourseList() {
      array = new Course[size];
    }
    add(Course course) {
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
      array[lastIndex] = course;
    }
    remove(Course course) {
      ;
    }
  private:
    Course* array;
    int size = 100;
    int lastIndex;
};
