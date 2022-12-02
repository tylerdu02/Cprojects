#include <iostream>
#include "Media.h"
#include <cstring>

using namespace std;

void Media::setTitle(char* titletemp) {
  strncpy(title, titletemp, 79);
}

void Media::setYear(int yeartemp) {
  year = yeartemp;
}

char * Media::getTitle() {
  return title;
}

int Media::getYear() {
  return year;
}

void Media::print () {

}
