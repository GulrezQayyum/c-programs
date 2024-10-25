#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class register_system {
    string name, email, password;
    string searchname, searchemail, searchpass;
    fstream file;
public:
    void login();
    void signUp();
    void forgot();
};

void register_system::login() {
    cout << "Enter your name: " << endl;
    cin.ignore(); // Clear the input buffer
    getline(cin, searchname);
    cout << "Enter your password: " << endl;
    getline(cin, searchpass);

    file.open("data.txt", ios::in);
    if (!file) {
        cout << "No data found. Please sign up first." << endl;
        return;
    }

    bool found = false;
    while (getline(file, name, '*') && getline(file, email, '*') && getline(file, password)) {
        if (name == searchname) {
            if (password == searchpass) {
                cout << "Account login successful..." << endl;
                cout << "User name is " << name << endl;
                cout << "Email address is " << email << endl;
                found = true;
                break;
            } else {
                cout << "Wrong Password..." << endl;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "No matching account found." << endl;
    }
    file.close();
}

void register_system::signUp() {
    cout << "Enter your name: " << endl;
    cin.ignore(); // Clear the input buffer
    getline(cin, name);
    cout << "Enter your email address: " << endl;
    getline(cin, email);
    cout << "Enter your password: " << endl;
    getline(cin, password);

    file.open("data.txt", ios::out | ios::app);
    file << name << "*" << email << "*" << password << endl;
    file.close();
}

void register_system::forgot() {
    cout << "Enter your name: " << endl;
    cin.ignore(); // Clear the input buffer
    getline(cin, searchname);
    cout << "Enter your email address: " << endl;
    getline(cin, searchemail);

    file.open("data.txt", ios::in);
    if (!file) {
        cout << "No data found. Please sign up first." << endl;
        return;
    }

    bool found = false;
    while (getline(file, name, '*') && getline(file, email, '*') && getline(file, password)) {
        if (name == searchname && email == searchemail) {
            cout << "Account found..." << endl;
            cout << "User name is " << name << endl;
            cout << "Password is " << password << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No matching account found." << endl;
    }
    file.close();
}

int main() {
    register_system obj;
    int choice;
    while (true) {
        cout << "------------------------------" << endl;
        cout << "1 - Sign Up" << endl;
        cout << "2 - Log In" << endl;
        cout << "3 - Forgot Password" << endl;
        cout << "4 - Exit" << endl;
        cout << "-------------------------------" << endl;

        cin >> choice;
        cin.ignore(); // Discard leftover newline character
        switch (choice) {
            case 1:
                obj.signUp();
                break;
            case 2:
                obj.login();
                break;
            case 3:
                obj.forgot();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Wrong Input..." << endl;
        }
    }
    return 0;
}
