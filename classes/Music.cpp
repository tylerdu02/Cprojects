#include <iostream>
#include <cstring>
#include "Music.h"

using namespace std;

void Music::setArtist(char* artistTemp) {
  strncpy(artist, artistTemp, 79);
}

void Music::setDuration(int durationTemp) {
  duration = durationTemp;
}

void Music::setPublisher(char* publisherTemp) {
  strncpy(publisher, publisherTemp, 79);
}

char* Music::getArtist() {
  return artist;
}

int Music::getDuration() {
  return duration;
}

char* Music::getPublisher() {
  return publisher;
}

void Music::print() { // prints out the inputs for music when called
  cout << "Title: " << title << endl;
  cout << "Artist: " << artist << endl;
  cout << "Year: " << year << endl;
  cout << "Duration (in seconds): " << duration << endl;
  cout << "Publisher: " << publisher << endl;

}
