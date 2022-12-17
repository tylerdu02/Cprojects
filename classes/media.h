#include <iostream>
#ifndef MEDIA
#define MEDIA

using namespace std;

class Media {
 public:
  void setTitle(char*);
  void setYear(int);
  char* getTitle();
  int getYear();
  virtual void print();
  char title[80];
  int year;
};

#endif
