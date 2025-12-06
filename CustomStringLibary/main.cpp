#include <iostream>
#include "CustomString.h"
#define DEFAULTVAL 0
#define OPTION_SET_STRING1              1
#define OPTION_SET_STRING2              2
#define OPTION_DISPLAY_STRINGS          3
#define OPTION_COMPARE_STRINGS          4
#define OPTION_CONCAT_STRINGS           5
#define OPTION_APPEND_TO_STRING1        6
#define OPTION_TO_UPPER                 7
#define OPTION_TO_LOWER                 8
#define OPTION_STRING_LENGTH            9
#define OPTION_COPY_STRING              10
#define OPTION_EQUALITY_TEST            11
#define OPTION_RELATIONAL_TEST          12
#define OPTION_ARRAY_ACCESS             13
#define OPTION_REPEAT_STRING            14
#define OPTION_EXIT                     15

using namespace std;

void displayWelcome();
void displayMenu();
bool getUserInput(int &choice);
bool getUserInput(CustomString &str);
void pauseScreen();

int main(void) {
    displayWelcome();

    CustomString string1, string2, string3;
    int choice = DEFAULTVAL;
    int index = DEFAULTVAL, times = DEFAULTVAL;
    CustomString buffer;

    cout << "Let's start by setting up two strings for testing.\n" << endl;

    // Get first string
    cout << "Enter String 1:" << endl;
    cin>>string1;

    cout << "Enter String 2:" << endl;
    cin >> string2;

    cout << "\nStrings initialized successfully!" << endl;
    pauseScreen();

    while(choice != OPTION_EXIT) {
        displayMenu();
        while(!getUserInput(choice)) {
            cout << "Input Invalid, Please Try Again" << endl;
        }

        switch(choice) {
            case OPTION_SET_STRING1:
                cout << "Enter new value for String 1:" << endl;
                if(cin >> string1) {
                    cout << "String 1 updated successfully!" << endl;

                } else {
                    cout << "Failed to update String 1" << endl;
                    cin.clear();

                }
                break;

            case OPTION_SET_STRING2:
                cout << "Enter new value for String 2:" << endl;
                if(cin >> string2) {
                    cout << "String 2 updated successfully!" << endl;

                } else {
                    cout << "Failed to update String 2" << endl;
                    cin.clear();

                }
                break;

            case OPTION_DISPLAY_STRINGS:
                cout << "\n=== Current Strings ===" << endl;
                cout << "String 1: " << string1 << endl;
                cout << "String 2: " << string2 << endl;
                cout << "Size of String 1: " << string1.getSize() << " characters" << endl;
                cout << "Size of String 2: " << string2.getSize() << " characters" << endl;
                break;

            case OPTION_COMPARE_STRINGS:
                {
                    int result = string1.strCompare(string2);
                    cout << "\n=== Comparison Result ===" << endl;
                    if(result == 0) {
                        cout << "String 1 is EQUAL to String 2" << endl;
                    } else if(result > 0) {
                        cout << "String 1 is LESS THAN String 2" << endl;
                    } else {
                        cout << "String 1 is GREATER THAN String 2" << endl;
                    }
                }
                break;

            case OPTION_CONCAT_STRINGS:
                string3 = string1 + string2;
                cout << "\n=== Concatenation Result ===" << endl;
                cout << "String 1 + String 2 = " << string3 << endl;
                break;

            case OPTION_APPEND_TO_STRING1:
                cout << "Enter text to append to String 1:" << endl;
                cin>>buffer;
                if(string1.append(buffer)) {
                    cout << "Appended successfully!" << endl;
                    cout << "New String 1: " << string1 << endl;
                } else {
                    cout << "Failed to append" << endl;
                }
                break;

            case OPTION_TO_UPPER:
                cout << "\nWhich string to convert? (1 or 2): ";

                if(choice == 1) {
                    if(string1.toUpper()) {
                        cout << "Converted to uppercase: " << string1 << endl;
                    } else {
                        cout << "Conversion failed" << endl;
                    }
                } else if(choice == 2) {
                    if(string2.toUpper()) {
                        cout << "Converted to uppercase: " << string2 << endl;
                    } else {
                        cout << "Conversion failed" << endl;
                    }
                } else {
                    cout << "Invalid choice" << endl;
                }
                choice = DEFAULTVAL;
                break;

            case OPTION_TO_LOWER:
                cout << "\nWhich string to convert? (1 or 2): ";
                cin >> choice;

                if(choice == 1) {
                    if(string1.toLower()) {
                        cout << "Converted to lowercase: " << string1 << endl;
                    } else {
                        cout << "Conversion failed" << endl;
                    }
                } else if(choice == 2) {
                    if(string2.toLower()) {
                        cout << "Converted to lowercase: " << string2 << endl;
                    } else {
                        cout << "Conversion failed" << endl;
                    }
                } else {
                    cout << "Invalid choice" << endl;
                }
                choice = DEFAULTVAL;
                break;

            case OPTION_STRING_LENGTH:
                cout << "\n=== String Lengths ===" << endl;
                cout << "String 1 length: " << string1.getSize() << " characters" << endl;
                cout << "String 2 length: " << string2.getSize() << " characters" << endl;
                break;

            case OPTION_COPY_STRING:
                string3 = string1;
                cout << "\n=== Copy Result ===" << endl;
                cout << "String 1 copied to String 3" << endl;
                cout << "String 3: " << string3 << endl;
                break;

            case OPTION_EQUALITY_TEST:
                cout << "\n=== Equality Tests ===" << endl;
                cout << "String 1 == String 2: " << (string1 == string2 ? "TRUE" : "FALSE") << endl;
                cout << "String 1 != String 2: " << (string1 != string2 ? "TRUE" : "FALSE") << endl;
                break;

            case OPTION_RELATIONAL_TEST:
                cout << "\n=== Relational Tests ===" << endl;
                cout << "String 1 > String 2:  " << (string1 > string2 ? "TRUE" : "FALSE") << endl;
                cout << "String 1 < String 2:  " << (string1 < string2 ? "TRUE" : "FALSE") << endl;
                cout << "String 1 >= String 2: " << (string1 >= string2 ? "TRUE" : "FALSE") << endl;
                cout << "String 1 <= String 2: " << (string1 <= string2 ? "TRUE" : "FALSE") << endl;
                break;

            case OPTION_ARRAY_ACCESS:
                cout << "\nWhich string to access? (1 or 2): ";
                cin >> choice;
                if(choice == 1 || choice == 2) {
                    CustomString& targetStr = (choice == 1) ? string1 : string2;
                    cout << "Enter index to access (0 to " << targetStr.getSize() - 1 << "): ";
                    cin >> index;

                    if(index >= 0 && index < targetStr.getSize()) {
                        cout << "Character at index " << index << ": '" << targetStr[index] << "'" << endl;
                        cout << "Do you want to modify this character? (1=Yes, 0=No): ";
                        int modify;
                        cin >> modify;

                        if(modify == 1) {
                            cout << "Enter new character: ";
                            char newChar;
                            cin >> newChar;

                            targetStr[index] = newChar;
                            cout << "Character updated! New string: " << targetStr << endl;
                        }
                    } else {
                        cout << "Index out of bounds!" << endl;
                    }
                } else {
                    cout << "Invalid choice" << endl;
                }
                choice = DEFAULTVAL;
                break;

            case OPTION_REPEAT_STRING:
                cout << "\nWhich string to repeat? (1 or 2): ";
                cin >> choice;
                cout << "How many times to print: ";
                cin >> times;

                cout << "\n=== Repeated String ===" << endl;
                if(choice == 1) {
                    string1 * times;
                } else if(choice == 2) {
                    string2 * times;
                } else {
                    cout << "Invalid choice" << endl;
                }
                choice = DEFAULTVAL;
                break;



            case OPTION_EXIT:
                cout << "\nThank you for testing CustomString!" << endl;
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid option. Please try again." << endl;
        }

        if(choice != OPTION_EXIT) {
            pauseScreen();
        }
    }

    return 0;
}

void displayWelcome() {
    cout << "\n";
    cout << "========================================" << endl;
    cout << "    CUSTOM STRING TESTER" << endl;
    cout << "========================================" << endl;
    cout << "\n";
    cout << "Welcome! This program tests all the" << endl;
    cout << "functionalities of the CustomString class." << endl;
    cout << "\n";
}

void displayMenu() {
    cout << "\n========================================" << endl;
    cout << "Select an operation:" << endl;
    cout << "----------------------------------------" << endl;
    cout << "  1.  Set String 1" << endl;
    cout << "  2.  Set String 2" << endl;
    cout << "  3.  Display Strings" << endl;
    cout << "  4.  Compare Strings" << endl;
    cout << "  5.  Concatenate Strings (String1 + String2)" << endl;
    cout << "  6.  Append to String 1" << endl;
    cout << "  7.  Convert to Uppercase" << endl;
    cout << "  8.  Convert to Lowercase" << endl;
    cout << "  9.  Get String Length" << endl;
    cout << "  10. Copy String (String1 to String3)" << endl;
    cout << "  11. Test Equality (== and !=)" << endl;
    cout << "  12. Test Relational Operators (<, >, <=, >=)" << endl;
    cout << "  13. Array Access Test ([])" << endl;
    cout << "  14. Repeat String (Print x times)" << endl;
    cout << "  15. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Your choice: ";
}

bool getUserInput(int &choice) {
    if(!(cin >> choice)) {
        cin.clear();

        return false;
    }
    return true;
}

bool getUserInput(CustomString &str) {
    if(!(cin >> str)) {
        cin.clear();
         return false;
    }
    return true;
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.get();
}
