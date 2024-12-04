#include <iostream>
#include <random>
#include <string>
#include <fstream>

using namespace std;

// Function prototypes
int generateComputerChoice();
string choiceName(int choice);
string game(int userChoice, int computerChoice);
int getUserChoice();
bool playRound(string playerName, int& playerWins);
void startNewSession(string playerName);
void displayPreviousSessions();

int main() {
    string playerName;
    int choice;

    // Main menu
    while (true) {
        cout << "Rock-Paper-Scissors Game\n";
        cout << "1. Start New Session\n";
        cout << "2. Display Previous Sessions\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter your name: ";
            cin >> playerName;
            startNewSession(playerName);
        }
        else if (choice == 2) {
            displayPreviousSessions();
        }
        else if (choice == 3) {
            cout << "Exiting the game. Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

// Function to generate computer's choice
int generateComputerChoice() {
    random_device engine;
    uniform_int_distribution<int> computerValue(1, 3);
    return computerValue(engine);
}

// Function to convert number to choice name
string choiceName(int choice) {
    switch (choice) {
    case 1: return "rock";
    case 2: return "paper";
    case 3: return "scissors";
    default: return "";
    }
}

// Function to determine the winner
string game(int userChoice, int computerChoice) {
    if (userChoice == computerChoice) {
        return "tie";
    }
    else if ((userChoice == 1 && computerChoice == 3) ||
        (userChoice == 2 && computerChoice == 1) ||
        (userChoice == 3 && computerChoice == 2)) {
        return "You win!";
    }
    else {
        return "Computer wins!";
    }
}

// Function to get user's choice
int getUserChoice() {
    string input;
    cout << "Please enter one of the following as your choice then hit enter: rock, paper or scissors.\n";
    cin >> input;
    if (input == "rock") return 1;
    if (input == "paper") return 2;
    if (input == "scissors") return 3;
    return 0;
}

// Function to play one round of the game
bool playRound(string playerName, int& playerWins, ofstream& outFile) {
    int computerChoice = generateComputerChoice();
    int userChoice = getUserChoice();

    if (userChoice == 0) {
        cout << "Invalid choice, please try again.\n";
        return true;
    }

    cout << "Computer chose: " << choiceName(computerChoice) << endl;
    string result = game(userChoice, computerChoice);

    if (result == "tie") {
        cout << "It's a tie! Play one more round to determine the winner.\n";
        return true;
    }

    cout << result << endl;
    outFile << playerName << ": " << result << endl;

    if (result == "You win!") {
        playerWins++;
    }
    return false;
}

// Function to start a new session
void startNewSession(string playerName) {
    int playerWins = 0;
    string playAgain;
    ofstream outFile("game_results.txt", ios::app);

    while (true) {
        bool isTieOrInvalid = playRound(playerName, playerWins, outFile);
        if (isTieOrInvalid) {
            continue;
        }

        cout << playerName << ", you have won " << playerWins << " times.\n";
        cout << "Do you want to play again? (yes/no): ";
        cin >> playAgain;

        if (playAgain != "yes") {
            break;
        }
    }

    outFile.close();
    cout << "Thank you for playing, " << playerName << "! You won " << playerWins << " times.\n";
}

// Function to display previous sessions
void displayPreviousSessions() {
    ifstream inFile("game_results.txt");
    string line;
    cout << "Previous Sessions:\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}
