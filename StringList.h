#include <string>

using namespace std;

class StringList {
  public:
    StringList();
    bool add(string s);
    bool remove(string s);
    int find(string s);
  private:
    string* array;
    int size;
    int lastIndex;
};
