#include <iostream>
#include <map>
#include <string>

using namespace std;

class PasswordManager {
private:
    map<string, string> passwords;

public:
    void storePassword(const string& account, const string& password) {
        passwords[account] = password;
        cout << "Password stored for account: " << account << endl;
    }

    string retrievePassword(const string& account) {
        if (passwords.find(account) != passwords.end()) {
            return passwords[account];
        } else {
            return "Account not found.";
        }
    }
};

int main() {
    PasswordManager manager;
    int choice;
    string account, password;

    do {
        cout << "Password Manager Menu" << endl;
        cout << "1. Store Password" << endl;
        cout << "2. Retrieve Password" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account name: ";
                cin >> account;
                cout << "Enter password: ";
                cin >> password;
                manager.storePassword(account, password);
                break;
            case 2:
                cout << "Enter account name: ";
                cin >> account;
                password = manager.retrievePassword(account);
                cout << "Password for " << account << ": " << password << endl;
                break;
            case 3:
                cout << "Exiting the password manager." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3);

    return 0;
}

