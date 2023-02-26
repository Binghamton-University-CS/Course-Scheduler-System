#include <string>

#ifndef STRINGLIST_H
#define STRINGLIST_H
#include "StringList.h"
#endif

StringList::StringList() {
      array = new string[size];
}

bool StringList::add(string s) {
      if (this->find(s) != -1) {
        return false;
      }
      
      if (lastIndex == size - 1) {
        T* temp = new T[size * 2];
        for (int i = 0; i < lastIndex; i++) {
          temp[i] = array[i];
        }
        delete array;
        array = temp;
        size *= 2;
      }
      lastIndex++;
      array[lastIndex] = s;
      true;
    }

bool StringList::remove(string s) {
      int index = this->find(s);
      if (index == -1) {
        return false;
      }
      for (int i = index; i < lastIndex - 1; i++) {
        array[i] = array[i + 1];
      }
      return true;
    }
    
int StringList::find(string s) {
      for (int i = 0; i < lastIndex; i++) {
        if (s == array[i]) {
          return i;
        }
      }
      return -1;
    }
void StringList::printAll() {
      for (int i = 0; i < size; i++) {
            cout << array[i] << endl;
      }
}

int StringList::getSize() {
      return size;
}
