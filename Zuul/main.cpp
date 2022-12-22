/*
  * Tyler Du
  * 12/18/22
  * Zuul. Adventure game where the player goes to new locations with items. To win player must make it to Lucky Landing.
  */

#include <iostream>
#include <vector>
#include <cstring>
#include "Room.h"
#include "Item.h"

using namespace std;

//function prototypes
void printRoom(Room* toPrint, vector<Item*> inventoryy);
void addItem(Room* currentRoom, char* itemlistt, vector<Item*> &inventoryy);
void dropItem(char* item, Room* currentRoom, vector<Item*> &inventory);
void printInventory(vector<Item*> inventory);

int main(){
  //implementaing direction
  char SOUTH[10] =  "South";
  char NORTH[10] = "North";
  char WEST[10] = "West";
  char EAST[10] = "East";
  
  vector<Item*> inventory;
  vector<Room*> rooms;

  //creating rooms and items
  char item[20] = "";
  char label[20] = "Risky Reels";
  char description[150] = "Risky Reels. Features a movie theater, but it's quite risky here";
  Room *riskyreels = new Room(label, description);

  strcpy(label, "Tomato Town");
  strcpy(description, "Tomato Town. Tomato Tomatoe");
  Room *tomatotown = new Room(label, description);
  strcpy(item, "Tomato");
  Item* tomato = new Item(item);
  tomatotown->addItem(tomato);

  strcpy(label, "Retail Row");
  strcpy(description, "Retail Row. Where you can get all your shopping done");
  Room *retailrow = new Room(label, description);

  strcpy(label, "Anarchy Acres");
  strcpy(description, "Your current location: Anarchy Acres, Acres of lonely land");
  Room *anarchyacres = new Room(label, description);

  strcpy(label, "Dusty Divot");
  strcpy(description, "Dusty Divot. Recently hit by a meteor. Be careful!!");
  Room *dustydivot = new Room(label, description);

  strcpy(label, "Salty Springs");
  strcpy(description, "Salty Springs. Saltiness has nothing to do with this place");
  Room *saltysprings = new Room(label, description);

  strcpy(label, "Fatal Fields");
  strcpy(description, "Fatal Fields. Just a bunch of cows and chickens");
  Room *fatalfields = new Room(label, description);

  strcpy(label, "Lucky Landing");
  strcpy(description,"Lucky Landing. Aww man, looks like you beat my game. CONGRATS!!");
  Room *luckylanding = new Room(label, description);

  strcpy(label, "Junk Junction");
  strcpy(description, "Junk Junction. Filled with cars and old scrap");
  Room *junkjunction = new Room(label, description);

  strcpy(label, "Pleasant Park");
  strcpy(description, "Pleasant Park. Many pleasant things to do here");
  Room *pleasantpark = new Room(label, description);
  strcpy(item, "Slide");
  Item *slide = new Item(item);
  pleasantpark->addItem(slide);

  strcpy(label, "Loot Lake");
  strcpy(description, "Loot Lake. Can find many special things here");
  Room *lootlake = new Room(label, description);
  strcpy(item, "Chest");
  Item *chest = new Item(item);
  lootlake->addItem(chest);

  strcpy(label, "Tilted Towers");
  strcpy(description, "Tilted Towers. The kings of all places");
  Room *tiltedtowers = new Room(label, description);
  strcpy(item, "SCAR");
  Item *scar = new Item(item);
  tiltedtowers->addItem(scar);

  strcpy(label, "Shifty Shafts");
  strcpy(description, "Shifty Shafts. A quite confusing place");
  Room *shiftyshafts = new Room(label, description);

  strcpy(label, "Flush Factory");
  strcpy(description, "Flush Factory. Nothings but toilets here");
  Room *flushfactory = new Room(label, description);
  strcpy(item, "Toilet");
  Item *toilet = new Item(item);
  flushfactory->addItem(toilet);

  strcpy(label, "Greasy Grove");
  strcpy(description, "Greasy Grove. Has nothing to do with grease");
  Room *greasygrove = new Room(label, description);

  //map layout
  anarchyacres->addNeighbor(EAST, riskyreels);
  anarchyacres->addNeighbor(WEST, pleasantpark);
  riskyreels->addNeighbor(WEST, anarchyacres);
  riskyreels->addNeighbor(SOUTH, tomatotown);
  tomatotown->addNeighbor(NORTH, riskyreels);
  tomatotown->addNeighbor(SOUTH, retailrow);
  retailrow->addNeighbor(NORTH, tomatotown);
  retailrow->addNeighbor(WEST, dustydivot);
  dustydivot->addNeighbor(EAST, retailrow);
  dustydivot->addNeighbor(SOUTH, saltysprings);
  dustydivot->addNeighbor(WEST, tiltedtowers);
  saltysprings->addNeighbor(NORTH, dustydivot);
  saltysprings->addNeighbor(SOUTH, fatalfields);
  saltysprings->addNeighbor(WEST, shiftyshafts);
  fatalfields->addNeighbor(NORTH, saltysprings);
  fatalfields->addNeighbor(WEST, flushfactory);
  fatalfields->addNeighbor(SOUTH, luckylanding);
  luckylanding->addNeighbor(NORTH, fatalfields);
  junkjunction->addNeighbor(SOUTH, pleasantpark);
  pleasantpark->addNeighbor(NORTH, junkjunction);
  pleasantpark->addNeighbor(EAST, anarchyacres);
  pleasantpark->addNeighbor(SOUTH, lootlake);
  lootlake->addNeighbor(NORTH, pleasantpark);
  lootlake->addNeighbor(SOUTH, tiltedtowers);
  tiltedtowers->addNeighbor(NORTH, lootlake);
  tiltedtowers->addNeighbor(EAST, dustydivot);
  tiltedtowers->addNeighbor(SOUTH, shiftyshafts);
  shiftyshafts->addNeighbor(NORTH, tiltedtowers);
  shiftyshafts->addNeighbor(SOUTH, flushfactory);
  shiftyshafts->addNeighbor(EAST, saltysprings);
  shiftyshafts->addNeighbor(WEST, greasygrove);
  flushfactory->addNeighbor(NORTH, shiftyshafts);
  flushfactory->addNeighbor(EAST, fatalfields);
  greasygrove->addNeighbor(EAST, shiftyshafts);
  
  Room* currentRoom = anarchyacres;
  bool won = false;
  char input[10];
  cout << "Welcome to Fortnite Zuul. Try your best to make it out. You would be real 'lucky' if you did."<< endl;
  while(!won){
    cout << endl;
    printRoom(currentRoom,inventory);
    //win condition
    if(strcmp(currentRoom->getLabel(),"Lucky Landing")==0){
      break;
    }
    cout << "What would you like to do? Go, drop, pick up, or quit" << endl;
    cin.get(input,10);
    cin.get();
    if(input[0]=='q' || input[0]=='Q'){
      break;
    }
    //go
    else if(input[0]=='g' || input[0]=='G'){
      char exit[10];
      cout << "Type which exit you would like to go to" << endl;
      cin.get(exit,10);
      cin.get();
      if(currentRoom->getNextRoom(exit)!=NULL){
	currentRoom = currentRoom->getNextRoom(exit);
      }
      else{
	cout << "Exit not available" << endl;
      }
    }
    //pickup
    else if(input[0]=='p' || input[0]=='P'){
      char itemlabel[10];
      cout << "What item would you like to pick up" << endl;
      cin.get(itemlabel,10);
      cin.get();
      addItem(currentRoom, itemlabel,inventory);
    }
    //drop
    else if(input[0]=='d' || input[0]=='D'){
      char itemlabel[10];
      cout << "What item in your inventory would you like to drop" << endl;
      cin.get(itemlabel,10);
      cin.get();
      dropItem(itemlabel,currentRoom, inventory);
    }
  }
  
  return 0;

}

void addItem(Room* currentRoom, char* itemlabell, vector<Item*> &inventoryy){
  if(currentRoom->getItem(itemlabell)!=NULL){
    inventoryy.push_back(currentRoom->getItem(itemlabell));
    currentRoom->removeItem(itemlabell);
  }
  else{
    cout << "Can't find any items in this room" << endl;
  }
}

void printRoom(Room* toPrint, vector<Item*> inventoryy){

  char print[150];
  strcpy(print,(toPrint->getDescription()));
  cout << endl;
  cout << endl;
  cout << print << endl;
  toPrint->printItems();
  cout << "Exits:" << endl;
  toPrint->printExits();
  cout << endl;
  cout << "Inventory:" << endl;
  printInventory(inventoryy);
  cout << endl;
  cout << endl;
}

void printInventory(vector<Item*> inventory){
  for(vector<Item*>::iterator it=inventory.begin(); it!=inventory.end(); it++){
    cout << (*it)->getLabel() << "  ";
  }
}

void dropItem(char* item, Room* currentRoom, vector<Item*> &inventory){
  for(vector<Item*>::iterator it=inventory.begin(); it!=inventory.end(); it++){
    char* currentLabel = (*it)->getLabel();
    if(strcmp(item,currentLabel)==0){
      currentRoom->addItem(*it);
      break;
    }
  }
  for(vector<Item*>::iterator it=inventory.begin(); it!=inventory.end(); it++){
    char* currentLabel = (*it)->getLabel();
    if(strcmp(item,currentLabel)==0){
      inventory.erase(it);
      break;
    }
  }
}