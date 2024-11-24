// RockPaperScissors_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// 1: Rock
// 2: Paper
// 3: Scissors

#include <iostream>
#include <random>
#include <string>

using namespace std;

// Function to generate computer's choice
int generateComputerChoice() {
    // Random number engine 
    random_device engine;
    // Distribution object 
    uniform_int_distribution<int> computerValue(1, 3);
    return computerValue(engine);
}

// Function to convert number to choice name 
string choiceName(int choice){
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
    cout << "Please enter one of the following as your choice then hit enter: rock, paper or scissors." << endl;
    cin >> input;

    if (input == "rock") return 1;
    if (input == "paper") return 2;
    if (input == "scissors") return 3;

    //Invalid choice
    return 0;
}

int main()
{
    int computerChoice;
    int userChoice;
    string playAgain;
    string result;

    while (true) {
        computerChoice = generateComputerChoice();
        userChoice = getUserChoice();

        //Check for invalid choice
        if (userChoice == 0) {
            cout << "Invalid choice, please try again." << endl; 
            continue;
        }
        cout << "Computer chose: " << choiceName(computerChoice) << endl;
        result = game(userChoice, computerChoice);
        if (result == "tie") {
            cout << "It's a tie! Play one more round to determine the winner." << endl;
            continue;
        }
        cout << result << endl;
        cout << "Do you want to play again? (yes/no): ";
        cin >> playAgain;
        if (playAgain != "yes") {
            break;
        }
    } 
    return 0;
}

  


