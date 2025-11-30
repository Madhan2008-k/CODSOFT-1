#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    int numberToGuess = rand() % 100 + 1;
    int guess;

    cout << "I'm thinking of a number between 1 and 100." << endl;

    while (true) {
        cout << "Take a guess: ";
        cin >> guess;

        if (guess < numberToGuess) {
            cout << "Too low! Try again." << endl;
        } else if (guess > numberToGuess) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number!" << endl;
            break;
        }
    }

    return 0;
}