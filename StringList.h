#include <string>

using namespace std;

class StringList {
  public:
    StringList();
    bool add(string s);
    bool remove(string s);
    int find(string s);
    void printAll();
  private:
    string* array;
    int size;
    int lastIndex;
};
