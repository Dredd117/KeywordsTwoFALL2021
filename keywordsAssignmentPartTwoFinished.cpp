#include <iostream>
#include <string>

#define ENDGAME 1

using namespace std;

// initializes the function endGame() when the game ends it will display the cout and return endgame.
int endGame() {

    cout << "You guessed correctly!" << endl;
    cout << "You are so smart!!" << endl;
    return ENDGAME;
}

//the function guessLetter() checks to see if the letter is correct by taking in what the user inputs,
//and tests letter with isIsNot and then returns the answer with the is or is not with the letter.
void guessLetter(string test) {
    char letter;
    string isIsNot;

    cout << "Please enter the letter you think is in the secret word" << endl;
    cin >> letter;
    cout << "you entered " << letter << endl;
    isIsNot = test.find(letter) != string::npos ? " IS" : " is NOT";
    cout << "The letter " << letter << isIsNot << " in the secret word!" << endl;
}

//guesWord function tests a string for guess, and checks if it is the same value as test.
int guesWord(string test) {
    string guess;

    cout << "Please enter what you think the secret word is" << endl;
    cin >> guess;
    cout << "you entered " << guess << endl;
    if (guess == test) {
        return endGame();
    }
    else {
        cout << "You guessed incorrectly!" << endl;
        return 0;
    }

}

int main()
{
    //the string test = WOOF
    string test = "WOOF";

    //initializes five trys.
    int trys = 5;

    char usrin_c;
    string usrin_s;

    //the while loop will continue as long as trys is true.
    while (trys--) {

        printf("Would you like to guess the word? \nenter y for yes\n");

        //the users answer is entered here.
        cin >> usrin_c;
        if (usrin_c == 'y') {
            if (guesWord(test)) {
                break;
            }
        }
        else {
            guessLetter(test);
        }
        //updates the player on how many trys they have left.
        printf("\nyou have %d guesses remaining\n", trys);


    }


    return 0;
}