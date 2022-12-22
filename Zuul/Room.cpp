#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#include "Room.h"

using namespace std;

Room::Room(char* newLabel, char* newDescription){
 label = new char[20];
  strcpy(label,newLabel);
  description = new char[150];
  strcpy(description, newDescription);
}

void Room::printItems(){
  cout << "Items here: " << endl;
  for(vector<Item*>::iterator it = items.begin(); it!=items.end(); it++){
    cout << (*it)->getLabel() << "  ";
  }
  cout << endl;
}

void Room::printExits(){
  map<char*,Room*>::iterator it;
  for(it = neighbors.begin(); it != neighbors.end(); it++){
    cout << it->first << "  ";
  }
}

Room* Room::getNextRoom(char* direction){
  map<char*,Room*>::iterator it;
  for(it = neighbors.begin(); it != neighbors.end(); it++){
    if(strcmp((it->first),direction)==0){
      return it->second;
    }
  }
  return NULL;
}

Item* Room::getItem(char* label){
  for(vector<Item*>::iterator it = items.begin(); it!=items.end(); it++){
    char* itemlabel = (*it)->getLabel();
    if(strcmp(itemlabel,label)==0){
      return (*it);
    }
  }
  return NULL;
}

void Room::removeItem(char* label){
  for(vector<Item*>::iterator it = items.begin(); it!=items.end(); it++){
    char* itemlabel = (*it)->getLabel();
    if(strcmp(itemlabel,label)==0){
      items.erase(it);
      break;
    }
  }
}


void Room::addItem(Item* i){
  items.push_back(i);
}


char* Room::getDescription(){
  return description;
}


char* Room::getLabel(){
  return label;
}


void Room::addNeighbor(char* direction, Room* neighbor){
  neighbors.insert({direction,neighbor});
}