#include <iostream>
#include "Media.h"

using namespace std;

class Videogames:public Media{
 public:
  void setPublisher(char*);
  void setRating(int);
  char* getPublisher();
  int getRating();

  char publisher[80];
  int rating;
  void print();
};
