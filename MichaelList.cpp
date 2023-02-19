#include "MichaelList.h"

MichaelList::MichaelList(string type) {
  if (type == "Student") {
    array = new Student[100];
  }
  else if (type == "Course") {
    array = new Course[100];
  }
  else {
    cout << "Error, invalid type" << endl;
  }
}

MichaelList::add() {
  
}

MichaelList::remove() {
  
}
