#include <algorithm>
#include <iostream>
using namespace std;

// Project Title: Greatest Common Divisor (GCD) Finder

/* Description

Code starts by asking the user for two numbers.
Once the numbers are entered, the code will find the GCD by using the Euclidean algorithm.
Once it finds the GCD, it outputs it before asking the user if they want to make another computation.

*/

bool keepRunning = true; // bool used to exit program.

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
            break;
        }
        case 'Y': {
            cout << "You chose 'Yes'.\n";
            keepRunning = true;
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

void swap(int &a, int &b) {
    // Will only be implemented if num2 is greater than num1
    int temp = a;
    a = b;
    b = temp;
}

int gcdFinder(int &x, int &y) {
    // recursion used to find GCD of two numbers.
    if (x % y == 0) {
return y;
    }
    int gcd = x % y;
    x = y;
    y = gcd;
   return gcdFinder(x, y);
}

// "Start menu." Prompts user to enter two numbers to find the GCD.
// Has cin.fail() in case user makes mistake (ex: enter char) that would cause runtime error.

int main() {
    do {
        int num1;
        int num2;
        cout << "Enter two numbers to find the greatest common divisor (GCD) of the two.\n";
        cin >> num1 >> num2;

        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input(s). Please input whole numbers only.\n\n";
            cin >> num1 >> num2;
        }

// Resolves issues if user inputs negative numbers.
        
        while (num1 < 0 || num2 < 0) {
            cout << "Invalid input(s). Please positive whole numbers only.\n\n";
            cin >> num1 >> num2;
        }

// swaps numbers if num1 is smaller than num2. Euclidean algorithm must have num1 >= num2 to work properly.
        
        if (num1 < num2) {
            swap(num1, num2);
        }

        cout << "The GCD of " << num1 << " and " << num2 << " is " << gcdFinder(num1, num2) << ".\n";

        continuePrompt();

    } while (keepRunning);
    return 0;
}
