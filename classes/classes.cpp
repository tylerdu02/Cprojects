/*
 * Tyler Du
 * Classes program where you can add, search, and delete. Also have digital media such as videogames, music, and movies.
 * 12/1/2022
 */

#include <iostream>
#include <cstring>
#include <vector>
#include "Media.h"
#include "Videogames.h"
#include "Music.h"
#include "Movies.h"

using namespace std;

void addElement(vector<Media*> &mediaElements);
void searchElement(vector<Media*> &mediaElements);
void deleteElement(vector<Media*> &mediaElements);

int main () {
  vector<Media*> mediaElements;
  char input[7];
  bool running = true;

  while (running == true) {
    cout << "Would you like to add, search, delete, or quit?" << endl;

    cin.get(input, 7);
    cin.get();


    if (input[0] == 'A' || input[0] == 'a') {
      addElement(mediaElements);
    }
    else if (input[0] == 'S' || input[0] == 's') {
      searchElement(mediaElements);
    }
    else if (input[0] == 'D' || input[0] == 'd') {
      deleteElement(mediaElements);
    }
    else if (input[0] == 'Q' || input[0] == 'q') {
      running = false;
    }
    else {
      cout << "Invalid Input" << endl;
    }
  }
  return 0;
}

void addElement(vector<Media*> &mediaElements) {
  char mediaType[15];
  cout << "Would you like to add music, movie, or video game?" << endl;
  cin.get(mediaType, 15);
  cin.get();
  
  if (mediaType[1] == 'u') {
    Music* music = new Music();

    char title[80];
    cout << "Music Title:" << endl;
    cin.get(title, 80);
    cin.get();
    music->setTitle(title);

    
    int year;
    cout << "Year Released:" << endl;
    cin >> year;
    cin.ignore(1, '\n');
    music->setYear(year);

    char artist[80];
    cout << "Artist Name:" << endl;
    cin.get(artist, 80);
    cin.get();
    music->setArtist(artist);

    int duration;
    cout << "Music Duration (in total seconds):" << endl;
    cin >> duration;
    cin.ignore(1, '\n');
    music->setDuration(duration);

    char publisher[80];
    cout << "Publisher Name:" << endl;
    cin.get(publisher, 80);
    cin.ignore(1, '\n');
    music->setPublisher(publisher);

    mediaElements.push_back(music);
  }
  else if (mediaType[1] == 'o') {
    Movies* movie = new Movies();

    char title[80];
    cout << "Movie Title:" << endl;
    cin.get(title, 80);
    cin.get();
    movie->setTitle(title);


    int year;
    cout << "Year Released:" << endl;
    cin >> year;
    cin.ignore(1, '\n');
    movie->setYear(year);

    char director[80];
    cout << "Director Name:" << endl;
    cin.get(director, 80);
    cin.get();
    movie->setDirector(director);

    int duration;
    cout << "Movie Duration (in minutes):" << endl;
    cin >> duration;
    cin.ignore(1, '\n');
    movie->setDuration(duration);

    int rating;
    cout << "Rating 0-10:" << endl;
    cin >> rating;
    cin.ignore(1, '\n');
    if ((rating >= 0) && (rating <= 10)) {
      movie->setRating(rating);
    }
    mediaElements.push_back(movie);
  }
  else if (mediaType[1] == 'i') {
    Videogames* vg = new Videogames();

    char title[80];
    cout << "Video Game Title:" << endl;
    cin.get(title, 80);
    cin.get();
    vg->setTitle(title);

    int year;
    cout << "Year Released:" << endl;
    cin >> year;
    cin.ignore(1, '\n');
    vg->setYear(year);

    char publisher[80];
    cout << "Publisher Name:" << endl;
    cin.get(publisher, 80);
    cin.get();
    vg->setPublisher(publisher);

    int rating;
    cout << "Rating 0-10:" << endl;
    cin >> rating;
    cin.ignore(1, '\n');
    if ((rating >= 0) && (rating <= 10)) {
      vg->setRating(rating);
    }
    mediaElements.push_back(vg);
  }
  else {
    cout << "Invalid Input, Try Again" << endl;
  }
}

void searchElement(vector<Media*> &mediaElements) {
  char mediaType[15];
  char elementTitle[80];

  cout << "What are you trying to search" << endl;
  
  cin.get(mediaType, 15);
  cin.get();
  
  if (mediaType[1] == 'u') {
    cout << "What is the title of the song you would like to search?" << endl;

    cin.get(elementTitle, 80);
    cin.get();

    for (int i = 0; i < mediaElements.size(); i++) {
      if (strcmp((mediaElements.at(i)->title), elementTitle) == 0) {
	      cout << "---------------------------------------------------------" << endl;  
        mediaElements.at(i)->print();
      }
      else if (strcmp((mediaElements.at(i)->title), elementTitle) != 0) {
	cout << "Song not found" << endl;
      }
    }  
  }
  
  else if (mediaType[1] == 'o') { 
    cout << "What is the title of the movie you would like to search?" << endl;

    cin.get(elementTitle, 80);
    cin.get();

    for (int i = 0; i < mediaElements.size(); i++) {
      if (strcmp((mediaElements.at(i)->title), elementTitle) == 0) { 
      	cout << "---------------------------------------------------------" << endl;
        mediaElements.at(i)->print();
      }
      else if (strcmp((mediaElements.at(i)->title), elementTitle) != 0) { 
      	cout << "Movie not found" << endl;
      }
    }
  }

  else if (mediaType[1] == 'i') { 
    cout << "What is the title of the video game you would like to search?" << endl;

    cin.get(elementTitle, 80);
    cin.get();
    
    for (int i = 0; i < mediaElements.size(); i++) {
      if (strcmp((mediaElements.at(i)->title), elementTitle) == 0) { 
        cout << "---------------------------------------------------------" << endl;
      	mediaElements.at(i)->print();
      }
      else if (strcmp((mediaElements.at(i)->title), elementTitle) != 0) { 
	cout << "Video game not found" << endl;
      }
    }
  }
}

void deleteElement(vector<Media*> &mediaElements) {
  char mediaType[15];
  char elementTitle[80];

  cout << "What Media Type Are You Trying To Delete? (Music, Movie, Video Game)" << endl;
  
  cin.get(mediaType, 15);
  cin.get();
  
  if (mediaType[1] == 'u') { // deletes music
    cout << "What Is The Title Of The Song You'd Like To Delete?" << endl;

    cin.get(elementTitle, 80);
    cin.get();

    // goes through mediaElements vector looking for inputted title
    for (int i = 0; i < mediaElements.size(); i++) {
      if (strcmp((mediaElements.at(i)->title), elementTitle) == 0) { // if finds music
        delete &(mediaElements.at(i));
	mediaElements.pop_back();
        cout << elementTitle << " Has Been Deleted" << endl;
      }
      else { // if cant find music
	      cout << "This Song Was Never Inputted!" << endl;
      }
    }  
  }
  
  else if (mediaType[1] == 'o') { // deletes movie
    cout << "What is the title of the movie you would like to delete?" << endl;

    cin.get(elementTitle, 80);
    cin.get();

    // goes through mediaElements vector looking for inputted title
    for (int i = 0; i < mediaElements.size(); i++) {
      if (strcmp((mediaElements.at(i)->title), elementTitle) == 0) { // if finds movie
        delete &(mediaElements.at(i));
	mediaElements.pop_back();
        cout << elementTitle << " Has been deleted" << endl;
      }
      else { // if cant find movie
	      cout << "Movie not found!" << endl;
      }
    }
  }

  else if (mediaType[1] == 'i') { // video game
    cout << "What is the title of the video game you would like to delete?" << endl;

    cin.get(elementTitle, 80);
    cin.get();

    // goes through mediaElements vector looking for inputted title
    for (int i = 0; i < mediaElements.size(); i++) {
      if (strcmp((mediaElements.at(i)->title), elementTitle) == 0) { // if finds video game
	delete &(mediaElements.at(i));
	mediaElements.pop_back();
        cout << elementTitle << " Has been deleted" << endl;
      }
      else { // if cant find video game
	      cout << "Video game not found" << endl;
      }
    }
  }
}
