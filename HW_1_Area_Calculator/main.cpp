#include<iostream>

using namespace std;

// A lot of the comments in this are notes to myself to help gain understanding of what I'm writing.

bool keepRunning = true;

// continuePrompt() is the function that determines whether keepRunning is set to "true" or "false", therefore, determining whether the loop continues or is stopped.

void continuePrompt() {
    char yesOrNo;
    do {
        cout << "Do you want to make another computation? (y/n)"<<endl;
        cin >> yesOrNo;
    }while (yesOrNo != 'Y' && yesOrNo != 'y' && yesOrNo != 'N' && yesOrNo != 'n');

    switch (yesOrNo) {
        case 'Y': {
            cout << "You selected 'Yes'.\n\n";
            keepRunning = true;
            break;
        }
        case 'y': {
            cout << "You selected 'Yes'.\n\n";
            keepRunning = true;
            break;
        }
        case 'N': {
            cout << "You selected 'No'. Exiting program...\n\n";
            keepRunning = false;
            break;
        }
        case 'n': {
            cout << "You selected 'No'. Exiting program...\n\n";
            keepRunning = false;
            break;
        }
        default: {
            cout << "Invalid choice."<<endl;
            break;
        }
    }
}

int main() {

do {
    // user == 1; // triangle
    // user == 2; // rectangle
    // user == 3; // square
    // user == 4; // circle
    // user == 5; // trapezoid
    // user == 6; // exit program

// endl; means "end line." "\n" can also do the same thing.
    cout << "Select the area you want to compute."<<endl;
    cout << "Insert 1 for triangle.\n";
    cout << "Insert 2 for rectangle."<<endl;
    cout << "Insert 3 for square."<<endl;
    cout << "Insert 4 for circle."<<endl;
    cout << "Insert 5 for trapezoid."<<endl;
    cout << "Insert 6 to exit the program."<<endl;

    int choice;

    cin>>choice;

    switch (choice) {
        case 1: {
            int base;
            int height;
            cout << "Enter the base and height of the triangle."<<endl;

// The code cin>>base>>height; is the same as the code below.
            cin>>base;
            cin>>height;

// float is used for numbers with decimals, int is used for whole numbers only.
// We use 2.0 instead of 2 so the code returns a decimal, and not a truncated number.
            float area = (base * height)/2.0;
            cout << area << endl;
            continuePrompt();
            break;
        }
        case 2: {
            int length;
            int width;
            cout << "Enter the length and width of the rectangle."<<endl;
            cin>>length>>width;
            float area = (length * width);
            cout << area << endl;
            continuePrompt();
            break;
        }

        case 3: {
        int base;
        cout << "Enter the side length of the square."<<endl;
        cin>>base;
        float area = (base * base);
        cout << area << endl;
            continuePrompt();
            break;
    }
        case 4: {
            int radius;
            cout << "Enter the radius of the circle."<<endl;
            cin>>radius;
            float area = (radius * radius) * 3.14159;
            cout << area << endl;
            continuePrompt();
            break;
        }

        case 5: {
            int b1;
            int b2;
            int height;

            cout << "Enter base 1, base 2, and height of the trapezoid."<<endl;
            cin>>b1>>b2>>height;
            float area = (b1 + b2)/2.0 * height;
            cout << area << endl;
            continuePrompt();
            break;
        }

        case 6: {
            cout << "Exiting program..."<<endl;
            keepRunning = false;
            break;
        }

        default: {
            cout << "Invalid choice.\n\n";
        }

    }

} while(keepRunning);

    // returning 0 means that the code was fully executed w/o error. Anything that isn't 0 means something went wrong.
    return 0;
}