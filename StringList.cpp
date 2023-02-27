#include <string>
#include <iostream>

#ifndef STRINGLIST_H
#define STRINGLIST_H
#include "StringList.h"
#endif

using namespace std;

StringList::StringList() {
      size = 1;
      currentQuantity = 0;
      array = new string*[size];
      for (int i = 0; i < size; i++) {
            array[i] = nullptr;
      }
}

StringList::~StringList() {
      for (int i = 0; i < currentQuantity; i++) {
            delete array[i];
      }
      delete[] array;
}

bool StringList::add(string s) {
      if (this->find(s) != -1) {
        return false;
      }
      
      if (currentQuantity == size) {
        string** temp = new string*[size * 2];
        for (int i_ = 0; i_ < size * 2; i_++) {
              temp[i_] = nullptr;
        }
        for (int i = 0; i < currentQuantity; i++) {
          temp[i] = array[i];
        }
        delete[] array;
        array = temp;
        size *= 2;
      }
      currentQuantity++;
      array[currentQuantity] = new string(s);
      return true;
    }

bool StringList::remove(string s) {
      int index = this->find(s);
      if (index == -1) {
        return false;
      }
      delete array[index];
      if (index == currentQuantity - 1) {
            return true;
      }
      for (int i = index; i < currentQuantity - 1; i++) {
        array[i] = array[i + 1];
      }
      return true;
    }
    
int StringList::find(string s) {
      for (int i = 0; i < currentQuantity; i++) {
        if (s == *(array[i])) {
          return i;
        }
      }
      return -1;
    }
void StringList::printAll() {
      for (int i = 0; i < currentQuantity; i++) {
            cout << *(array[i]) << endl;
      }
}

int StringList::getCurrentQuantity() {
      return currentQuantity;
}
