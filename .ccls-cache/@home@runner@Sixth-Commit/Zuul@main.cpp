#include <iostream>
#include <vector>
#include <cstring>
#include "Room.h"
#include "Item.h"

using namespace std;

void print(Room* toPrint, vector<Item*> inventory);
void goNextRoom(Room* currentRoom);
void addItem(Room* currentRoom, vector<Item*> inventory);
void dropItem(char* item, Room* currentRoom, vector<Item*> inventory);
void printInventory(vector<Item*> inventory);

int main() {
  vector<Item*> inventory;

  char roomName[80];
  char roomDescription[200];
  char itemName[20];

  char* north = new char[10];
  char* south = new char[10];
  char* west = new char [10];
  char* east = new char [10];
  strncpy(north, "north", 9);
  strncpy(south, "south", 9);
  strncpy(west, "west",9);
  strncpy(east, "east", 9);

  strncpy(roomName, "Risky Reels", 79);
  strncpy(roomDescription, "Features a movie theater, but it's quite risky here");
  Room* riskyreels = new Room(roomName, roomDescription);

  strncpy(roomName, "Tomato Town", 79);
  strncpy(roomDescription, "Tomato Tomatoe");
  Room* tomatotown = new Room(roomName, roomDescription);

  strncpy(roomName, "Retail Row", 79);
  strncpy(roomDescription, "Where you can get all your shopping done");
  Room* retailrow = new Room(roomName, roomDescription);

  strncpy(roomName, "Anarchy Acres", 79);
  strncpy(roomDescription, "Acres of lonely land");
  Room* anarchyacres = new Room(roomName, roomDescription);

  strncpy(roomName, "Dusty Divot", 79);
  strncpy(roomDescription, "Recently hit by a meteor. Be careful!!");
  Room* dustydivot = new Room(roomName, roomDescription);

  strncpy(roomName, "Salty Springs", 79);
  strncpy(roomDescription, "Saltiness has nothing to do with this place");
  Room* saltysprings = new Room(roomName, roomDescription);

  strncpy(roomName, "Fatal Fields", 79);
  strncpy(roomDescription, "Just a bunch of cows and chickens");
  Room* fatalfields = new Room(roomName, roomDescription);

  strncpy(roomName, "Lucky Landing", 79);
  strncpy(roomDescription, "Better odds than Vegas");
  Room* luckylanding = new Room(roomName, roomDescription);

  strncpy(roomName, "Junk Juction", 79);
  strncpy(roomDescription, "Filled with cars and old scrap");
  Room* junkjunction = new Room(roomName, roomDescription);

  strncpy(roomName, "Pleasant Park", 79);
  strncpy(roomDescription, "Many pleasant things to do here");
  Room* pleasantpark = new Room(roomName, roomDescription);

  strncpy(roomName, "Loot Lake", 79);
  strncpy(roomDescription, "Can find many special things here");
  Room* lootlake = new Room(roomName, roomDescription);

  strncpy(roomName, "Tilted Towers", 79);
  strncpy(roomDescription, "The kings of all places");
  Room* tilted towers = new Room(roomName, roomDescription);

  strncpy(roomName, "Shifty Shafts", 79);
  strncpy(roomDescription, "A quite confusing place");
  Room* shiftyshafts = new Room(roomName, roomDescription);

  strncpy(roomName, "Flush Factory", 79);
  strncpy(roomDescription, "Nothings but toilets here");
  Room* tomatotown = new Room(roomName, roomDescription);

  strncpy(roomName, "Greasy Grove", 79);
  strncpy(roomDescription, "Has nothing to do with grease");
  Room* tomatotown = new Room(roomName, roomDescription);

 