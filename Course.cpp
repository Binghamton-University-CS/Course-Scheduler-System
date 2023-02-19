#include <string>
#include "Course.h"

Course::Course(string CRN, string department, string number, string name) {
  this->CRN = CRN;
  this->department = department;
  this->number = number;
  this->name = name;
}
