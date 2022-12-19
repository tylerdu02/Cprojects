#include <iostream>
#include <vector>
#include <cstring>
#include "Room.h"
#include "Item.h"

using namespace std;

void print(Room* toPrint, vector<Item*> inventory);
Room* moveRoom(Room* currentRoom);
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
  Room* tiltedtowers = new Room(roomName, roomDescription);

  strncpy(roomName, "Shifty Shafts", 79);
  strncpy(roomDescription, "A quite confusing place");
  Room* shiftyshafts = new Room(roomName, roomDescription);

  strncpy(roomName, "Flush Factory", 79);
  strncpy(roomDescription, "Nothings but toilets here");
  Room* flushfactory = new Room(roomName, roomDescription);

  strncpy(roomName, "Greasy Grove", 79);
  strncpy(roomDescription, "Has nothing to do with grease");
  Room* greasygrove = new Room(roomName, roomDescription);

  strncpy(itemName, "Slide", 19);
  Item* slide = new Item(itemName);
  strncpy(itemName, "Tomato", 19);
  Item* tomato = new Item(itemName);
  strncpy(itemName, "Toilet", 19);
  Item* toilet = new Item(itemName);
  strncpy(itemName, "SCAR", 19);
  Item* scar = new Item(itemName);
  strncpy(itemName, "Treasure Chest", 19);
  Item* treasurechest = new Item(itemName);

  pleasantpark->addItem(slide);
  tomatotown->addItem(tomato);
  flushfactory->addItem(toilet);
  tiltedtowers->addItem(scar);
  lootlake->addItem(treasurechest);

  anarchyacres->addNeighbor(east, riskyreels);
  anarchyacres->addNeighbor(west, pleasantpark);
  riskyreels->addNeighbor(west, anarchyacres);
  riskyreels->addNeighbor(south, tomatotown);
  tomatotown->addNeighbor(north, riskyreels);
  tomatotown->addNeighbor(south, retailrow);
  retailrow->addNeighbor(north, tomatotown);
  retailrow->addNeighbor(west, dustydivot);
  dustydivot->addNeighbor(east, retailrow);
  dustydivot->addNeighbor(south, saltysprings);
  dustydivot->addNeighbor(west, tiltedtowers);
  saltysprings->addNeighbor(north, dustydivot);
  saltysprings->addNeighbor(south, fatalfields);
  saltysprings->addNeighbor(west, shiftyshafts);
  fatalfields->addNeighbor(north, saltysprings);
  fatalfields->addNeighbor(west, flushfactory);
  fatalfields->addNeighbor(south, luckylanding);
  luckylanding->addNeighbor(north, fatalfields);
  junkjunction->addNeighbor(south, pleasantpark);
  pleasantpark->addNeighbor(north, junkjunction);
  pleasantpark->addNeighbor(east, anarchyacres);
  pleasantpark->addNeighbor(south, lootlake);
  lootlake->addNeighbor(north, pleasantpark);
  lootlake->addNeighbor(south, tiltedtowers);
  tiltedtowers->addNeighbor(north, lootlake);
  tiltedtowers->addNeighbor(east, dustydivot);
  tiltedtowers->addNeighbor(south, shiftyshafts);
  shiftyshafts->addNeighbor(north, tiltedtowers);
  shiftyshafts->addNeighbor(south, flushfactory);
  shiftyshafts->addNeighbor(east, saltysprings);
  shiftyshafts->addNeighbor(west, greasygrove);
  flushfactory->addNeighbor(north, shiftyshafts)
  flushfactory->addNeighbor(east, fatalfields);
  greasygrove->addNeighbor(east, shiftyshafts);

  