#pragma once
#include <vector>
#include <map>
#include "Item.h"

using namespace std;
class Room{
 
 public:
  Room(char*,char*);
  char* getDescription();
  char* getLabel();
  void addItem(Item*);
  void printItems();
  void printExits();
  void addNeighbor(char*,Room*);
  Room* getNextRoom(char*);
  Item* getItem(char*);
  void removeItem(char*);
 private:
  char* description;
  char* label;
  vector<Item*> items;
  map<char*,Room*> neighbors;
};