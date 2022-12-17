/*
 * Tyler Du
 * 11/7/2022
 * Student List. Create a student list consisting of the student's first and last name, id, and GPA.
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <cmath>

using namespace std;

// creating student struct
struct Student {
  char firstName[30];
  char lastName[30];
  int studentID;
  float gpa;
};

void addStudent(vector<Student*> &studentList);
void printStudent(vector<Student*> &studentList);
void deleteStudent(vector<Student*> &studentList);

int main () {
  char input[7];
  bool running = true;
  vector<Student*> studentList;

  while (running == true) {
    cout << "Add, Print, Delete, Quit" << endl;
    cin >> input;
    if (strcmp(input, "Add") == 0) {
      addStudent(studentList);
    }
    else if (strcmp(input, "Print") == 0) {
      printStudent(studentList);
    }
    else if (strcmp(input, "Delete") == 0) {
      deleteStudent(studentList);
    }
    else if (strcmp(input, "Quit") == 0) {
      running = false;
    }
    else { 
      cout << "Invalid Input" << endl;
    }
  }
  return 0;
}

// adds new student
void addStudent(vector<Student*> &studentList) {
  Student* addS = new Student();
  char firstNamen[30];
  char lastNamen[30];
  int studentIDI;
  float gpag;

  cout << "Enter student's first name" << endl;
  cin >> firstNamen;
  cout << "Enter student's last name" << endl;
  cin >> lastNamen;
  cout << "Enter student's ID number" << endl;
  cin >> studentIDI;
  cout << "Enter student's GPA" << endl;
  cin >> gpag;

  strcpy(addS->firstName,firstNamen);
  strcpy(addS->lastName,lastNamen);
  addS->studentID = studentIDI;
  addS->gpa = gpag;

  studentList.push_back(addS);
}

// prints out all students and their inputs
void printStudent(vector<Student*> &studentList) {
  cout << "Your Student List" << endl;
  char buffer[10];

  for (int i = 0; i < studentList.size(); i++) {
    sprintf(buffer, "%.2f", studentList.at(i)->gpa);

    cout << studentList.at(i)->firstName << " "
	 << studentList.at(i)->lastName << ", "
	 << studentList.at(i)->studentID << ", "
	 << buffer << endl;
  }
}

// deletes the student using their ID
void deleteStudent(vector<Student*> &studentList) {
  int studentIDI;
  cout << "Enter student's ID you want to delete" << endl;

  cin >> studentIDI;

  for (int i = 0; i < studentList.size(); i++) {
    if ((studentList.at(i)->studentID) == studentIDI) {
      studentList.erase(studentList.begin() + i);
      cout << studentIDI << " has been deleted" << endl;
    }
    else {
      cout << "This student is not in the list" << endl;
    }
  }
}
