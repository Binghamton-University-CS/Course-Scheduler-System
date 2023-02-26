#include <string>

using namespace std;

class StringList {
  public:
    StringList();
    ~StringList();
    bool add(string s);
    bool remove(string s);
    int find(string s);
    void printAll();
    int getSize();
  private:
    int size;
    int currentQuantity;
    string* array[];
};
