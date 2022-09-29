/*
 * Tyler Du
 * 9/29/2022
 * Palindrome. Input characters and checks if it is a palindrome
*/

#include <iostream>
#include <cstring>

using namespace std;

int main () {
  char str[80];
  char str2[80];
  char str3[80];

  cout << "Enter your input" << endl;
  cin.get(str, 80);
  cin.get();
  
  int count = 0;
  for (int i = 0; i < strlen(str); i++) {
    if (isalpha(str[i])) {
      str2[count] = tolower(str[i]);
      count++;
    }
  }
  str2[count] = 0;

  int count2 = 0;
  for (int i = 0; i < strlen(str2); i++) {
  str3[count2] = str2[strlen(str2) - 1 -i];
  count2++;
  }
  str3[count2] = 0;

  int result = strcmp(str2, str3);
  if (result == 0) {
    cout << "Input is a Palindrome" << endl;
  }
  else {
    cout << "Input is NOT a Palindrome" << endl;
  }

}
