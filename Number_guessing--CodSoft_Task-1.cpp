#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void showMainMenu();
void startGuessingGame();
void displayPreviousScore(int previousAttempts);
void exitGame();
int getNumberRange();
int getUserGuess();

int main() {
    int userChoice;
    int attempts = 0;

    while (true) {
        showMainMenu();
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                startGuessingGame();
                break;
            case 2:
                displayPreviousScore(attempts);
                break;
            case 3:
                exitGame();
                return 0; 
            default:
                cout << "Oops! That’s not a valid choice. Please select a valid option." << endl;
        }
    }
}

void showMainMenu() {
    cout << "----------------------------------------------------------------------" << endl;
    cout << "----------------------- WELCOME TO THE GUESSING GAME -----------------------" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Please choose an option below:" << endl;
    cout << "1. Play the Game" << endl;
    cout << "2. View Previous Score" << endl;
    cout << "3. Exit" << endl;
    cout << "Your choice: ";
}

void startGuessingGame() {
    int range = getNumberRange();
    int secretNumber, userGuess, attemptCount = 0;
    srand(static_cast<unsigned int>(time(nullptr))); 
    secretNumber = rand() % (range + 1);

    cout << "-------------------- GUESS THE NUMBER GAME --------------------" << endl;

    do {
        userGuess = getUserGuess();
        attemptCount++;

        if (userGuess > secretNumber) {
            cout << "The number is smaller than your guess." << endl;
        } else if (userGuess < secretNumber) {
            cout << "The number is larger than your guess." << endl;
        } else {
            cout << "Congratulations! You've found the number!" << endl;
            if (attemptCount == 1) {
                cout << "You guessed the number in just " << attemptCount << " attempt!" << endl;
            } else {
                cout << "It took you " << attemptCount << " attempts to guess the number." << endl;
            }
        }
    } while (userGuess != secretNumber);
}

void displayPreviousScore(int previousAttempts) {
    if (previousAttempts == 0) {
        cout << "You haven’t played any games yet." << endl;
    } else if (previousAttempts == 1) {
        cout << "In your last game, you guessed the number in " << previousAttempts << " attempt." << endl;
    } else {
        cout << "In your last game, you guessed the number in " << previousAttempts << " attempts." << endl;
    }
}

void exitGame() {
    cout << "Thank you for playing! Have a great day!" << endl;
}

int getNumberRange() {
    int range;
    cout << "Specify the range for the numbers: ";
    while (!(cin >> range) || range < 1) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid range. Please enter a positive integer: ";
    }
    return range;
}

int getUserGuess() {
    int guess;
    cout << "Enter your guess: ";
    while (!(cin >> guess)) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid input. Please enter a number: ";
    }
    return guess;
}
