#ifndef MICHAELIST_H
#define MICHAELIST_H
#include "MichaelList.h"
#endif

template <class T>
MichaelList::MichaelList() {
      array = new T[size];
    }

template <class T>
bool MichaelList::add(T val) {
      if (this->find(val) != -1) {
        return false;
      }
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

template <class T>
bool MichaelList::remove(T val) {
      int index = this->find(val);
      if (index == -1) {
        return false;
      }
      for (int i = index; i < lastIndex - 1; i++) {
        array[i] = array[i + 1];
      }
      return true;
    }

template <class T>
int MichaelList::find(T val) {
      for (int i = 0; i < lastIndex; i++) {
        if (val == array[i]) {
          return i;
        }
      }
      return -1;
    }
