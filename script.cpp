/*1. No global variables. (Global constants are all right.)

2. No strings. Not ever. (You can use cstrings/character arrays, and the cstring and cctype libraries are okay. In fact, I recommend using strcmp and strlen in your projects.)

3. You should include <iostream>, not stdio. (This applies more to C programmers.)

Xander Siruno-Nebel
C++/Data Structures, Galbraith
Sept 9. 2022
Guessing Game - Find some random number chosen by the computer
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
  bool found = false;
  int random = 0;
  srand(time(NULL));
  random = rand() % 100;
  int input = 0;
  int guesses = 0;
  char answer = 'a';

  cout << "Your guess: ";
  cin >> input;
  //only runs while the number is unfound
  while(!found){
    guesses++;
    //tells player if they need to increase or decrease their guess
    if(input > random){
      cout << "Lower.";
      cin >> input;
    }else if(input < random){
      cout << "Higher.";
      cin >> input;
    }else if(input == random){
      //win condition
      cout << "Yay! You found the number in " << guesses << " guesses! Play again (Y/N)?";
      found = true;
      cin >> answer;
    }
  }
  //continue condition
  if(answer == 'Y'){
    cout << "Starting game again!";
    main();
  }else{
    cout << "Bye!";
  }
  return 0;
}
