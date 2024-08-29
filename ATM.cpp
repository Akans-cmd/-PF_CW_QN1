#include <iostream>
#include <map>
#include <string>

using namespace std;

// This is a function to display the main menu as a string
string getMainMenu() {
    return "d -> Deposit Money\n"
           "w -> Withdraw Money\n"
           "r -> Request Balance\n"
           "q -> Quit\n";
}

// This is a function to display the introduction menu as a string
string getIntroMenu() {
    return "l -> Login\n"
           "c -> Create New Account\n"
           "q -> Quit\n";
}

int main() {
    map<string, string> accounts; // It wil store user accounts: username & password
    map<string, double> balances;  // It will store account balances: username & balance
    char menuChoice;  // here am creating a variable menuChoice to store the user's menu choice (like 'l' for login)


/*
 *The code below is :
 *Main Loop and Introduction Menu
 *Am Starting a loop that will run forever,
 *or until I break out of it.
 */
    while (true) {
        cout << getIntroMenu();
        cout << "Enter your choice: ";
        cin >> menuChoice;

/*
 *NOW Code for handling User Choices
 *Main Loop and Introduction Menu
 *Am Starting a loop that will run forever,
 *or until I break out of it.
 */
        if (menuChoice == 'q') {
            cout << "Quitting the program. Goodbye!\n";
            break;
        } else if (menuChoice == 'c') {
            // Create new account
            cout << "Please enter your user id: ";
            cin >> userID;
            cout << "Please enter your password: ";
            cin >> password;
            accounts[userID] = password;
            balances[userID] = 0.0; // Initialize balance to 0
            cout << "Thank You! Your account has been created!\n";
        } else if (menuChoice == 'l') {
            // Login
            cout << "Please enter your user id: ";
            cin >> userID;
            cout << "Please enter your password: ";
            cin >> password;

            // Check if login is successful
            if (accounts.find(userID) != accounts.end() && accounts[userID] == password) {
                cout << "Access Granted!\n";

                while (true) {
                    cout << getMainMenu();
                    cout << "Enter your choice: ";
                    cin >> menuChoice;

                    if (menuChoice == 'q') {
                        cout << "Logging out. Goodbye!\n";
                        break;
                    } else if (menuChoice == 'd') {
                        // Deposit money
                        double depositAmount;
                        cout << "Amount of deposit: UGX";
                        cin >> depositAmount;
                        balances[userID] += depositAmount;
                    } else if (menuChoice == 'w') {
                        // Withdraw money
                        double withdrawAmount;
                        cout << "Amount of withdrawal: UGX";
                        cin >> withdrawAmount;

                        if (withdrawAmount <= balances[userID]) {
                            balances[userID] -= withdrawAmount;
                        } else {
                            cout << "Insufficient funds!\n";
                        }
                    } else if (menuChoice == 'r') {
                        // Request balance
                        cout << "Your balance is UGX" << balances[userID] << ".\n";
                    } else {
                        cout << "Invalid choice. Please try again.\n";
                    }
                }
            } else {
                cout << "*** LOGIN FAILED! ***\n";
            }
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
