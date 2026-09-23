#include <algorithm>
#include <iostream>
using namespace std;

// Project Title: Exponent Calculator

/* Description

Code starts by prompting the user to choose a base and exponent.
From there, it can handle if the exponent =0, >0, or <0.
Finally, it asks the user if they want to make another computation.

*/

bool keepRunning = true; // bool used to exit program.
float answer = 1; // uses float to allow for decimal answers.

void continuePrompt() {
    // function used to loop back to original code based on user choice.
    char yesOrNo;
    do {
        cout << "Do you want to make another computation?(y/n)\n";
        cin >> yesOrNo;
    } while (yesOrNo != 'Y' && yesOrNo != 'y' && yesOrNo != 'N' && yesOrNo != 'n');
    switch (yesOrNo) {
        case 'y': {
            cout << "You chose 'Yes'.\n";
            keepRunning = true;
            answer = 1;
            break;
        }
        case 'Y': {
            cout << "You chose 'Yes'.\n";
            keepRunning = true;
            answer = 1;
            break;
        }
        case 'n': {
            cout << "You chose 'No'.\n";
            keepRunning = false;
            break;
        }
        case 'N': {
            cout << "You chose 'No'.\n";
            keepRunning = false;
            break;
        }
        default: {
            cout << "Please enter a valid option.(y/n)\n";
        }
    }
}

// "Start menu." Will prompt user to enter the base and exponent.
// Has cin.fail() in case user makes mistake that would cause runtime error.

int main() {
    do {
        float base;
        int exponent;
        cout << "Enter base:\n";
        cin >> base;

        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please input a number.\n\n";
            cin >> base;
        }

        cout << "Enter Exponent:\n";
        cin >> exponent;

        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please input a whole  number.\n\n";

            cin >> exponent;
        }

        if (base == 0 && exponent < 0) {
            // Returns undefined if 0^(negative exponent).
            cout << base << "^" << exponent << "=undefined" << "\n";
            continuePrompt();
        } else {
            if (exponent == 0) {
                // x^0 == 1
                answer = 1;
            } else if (exponent > 0) {
                // Exponential growth
                for (int i = 0; i < exponent; i++) {
                    answer = answer * base;
                }
            } else {
                for (int i = 0; i > exponent; i--) {
                    // Exponential decay
                    answer = answer / base;
                }
            }
            cout << base << "^" << exponent << "=" << answer << "\n";
            continuePrompt();
        }
    } while (keepRunning);
}
