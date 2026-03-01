#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// User registration ki function
void registerUser() {
    string username, password;
    cout << "\n--- Registration Page ---" << endl;
    cout << "Naya Username likhein: ";
    cin >> username;
    cout << "Naya Password likhein: ";
    cin >> password;

    // File mein data save karna (One file per user) 
    ofstream outFile(username + ".txt");
    if (outFile.is_open()) {
        outFile << username << endl;
        outFile << password << endl;
        outFile.close();
        cout << "\nRegistration Successful! [cite: 35]" << endl;
    } else {
        cout << "\nError: File nahi ban saki!" << endl;
    }
}

// Login verification ki function [cite: 34]
bool loginUser() {
    string username, password, storedUser, storedPass;
    cout << "\n--- Login Page ---" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    // File se data read karna [cite: 34]
    ifstream inFile(username + ".txt");
    if (inFile.is_open()) {
        getline(inFile, storedUser);
        getline(inFile, storedPass);
        inFile.close();

        // Credentials verify karna [cite: 34]
        if (username == storedUser && password == storedPass) {
            return true;
        }
    }
    return false;
}

int main() {
    int choice;
    while (true) {
        cout << "\n1. Register\n2. Login\n3. Exit\nSelect Option: ";
        cin >> choice;

        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            if (loginUser()) {
                cout << "\nLogin Successful! Welcome to the system. [cite: 35]" << endl;
                break; // Login ke baad program khatam ya agla menu
            } else {
                cout << "\nInvalid Username or Password! [cite: 35]" << endl;
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "\nGalat option! Dobara koshish karein." << endl;
        }
    }
    return 0;
}