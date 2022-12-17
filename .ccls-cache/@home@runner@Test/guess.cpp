/* 
 * Tyler Du
 * 9/16/2022
 * Guessing Game. Guess a number 0-100. The computer auto generates a number.

 * 3 rules of C++
 * 1. No global variables. (Global constants are all right.)
 * 2. No strings. Not ever. (You can use cstrings/character arrays, and the cstring and cctype libraries are okay. In fact, I recommend using strcmp and strlen in your projects.)
 * 3. You should include <iostream>, not stdio. (This applies more to C programmers.)

 */

#include <iostream>
#include <cstring>

using namespace std;

int main ()
 {
   srand(time(NULL));

     while(true) {
       int num = rand() % 101;
       bool stillPlaying = true;
       int guessNum = 0;
       int guesses = 0;
       char playAgain;
       cout << "Guess a number from 0-100" << endl;
       while (stillPlaying == true) {
	 cin >> guessNum;
	 if (guessNum > num) {
	   cout << "Guess too high" << endl;
	   guesses++;
	 }
	 if (guessNum < num) {
	   cout << "Guess too low" << endl;
	   guesses++;
	 }
	 if (guessNum == num) {
	   cout << "Guess correct!!" << endl;
	   cout << guesses;
	   cout << " times guessed" << endl;
	   stillPlaying = false;
	 }
       }
       cout << "To play again type y, to exit type n" << endl;
       cin >> playAgain;
       if (playAgain == 'y') {
	 cout << "Welcome back" << endl;
       }
       if (playAgain == 'n') {
	 cout << "Goodbye" << endl;
	 break;
       }
     }
   return 0;
 }
