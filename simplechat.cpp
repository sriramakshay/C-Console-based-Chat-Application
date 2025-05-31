// Simple Console-based Chat Simulation in C++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void writeMessage(const string& username) {
    ofstream chatFile("chat.txt", ios::app);
    if (!chatFile) {
        cerr << "Error opening chat file!\n";
        return;
    }
    string message;
    cin.ignore();
    cout << "Enter your message: ";
    getline(cin, message);
    chatFile << username << ": " << message << endl;
    chatFile.close();
    cout << "Message sent!\n";
}

void readMessages() {
    ifstream chatFile("chat.txt");
    if (!chatFile) {
        cerr << "Error opening chat file!\n";
        return;
    }
    string line;
    cout << "\n--- Chat History ---\n";
    while (getline(chatFile, line)) {
        cout << line << endl;
    }
    chatFile.close();
    cout << "--------------------\n";
}

int main() {
    string username;
    cout << "Enter your username: ";
    cin >> username;
    int choice;
    do {
        cout << "\n--- Chat Menu ---\n";
        cout << "1. Write Message\n2. Read Messages\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                writeMessage(username);
                break;
            case 2:
                readMessages();
                break;
            case 3:
                cout << "Exiting chat...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
