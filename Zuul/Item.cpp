#include <cstring>
#include "Item.h"

Item::Item(char* newLabel){
  label = new char[20];
  strcpy(label,newLabel);
}

char* Item::getLabel(){
  return label;
}