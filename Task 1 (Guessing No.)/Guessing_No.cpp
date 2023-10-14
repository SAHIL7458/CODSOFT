#include<bits/stdc++.h>

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr))); 

    int secretNumber = (rand() % 100) + 1;

    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game! Made By SAHIL" << endl;
    cout << "I have  selected a random number between 1 and 100. Try to guess it." << endl; 

    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the number (" << secretNumber << ") in " << attempts << " attempts!" << endl;
            break;
        }
    }

    return 0;
}
