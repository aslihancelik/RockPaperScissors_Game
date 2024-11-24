// RockPaperScissors_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// This is a rock paper scissors game played with the computer. User enters their choice and the computer randomly 
// generates an integer between 1 and 3. The numbers corresponds to the choices as follows:
//
// 1: Rock
// 2: Paper
// 3: Scissors
//
// A winner is selected according to the following rules:
//      If one player chooses rock and the computer chooses scissors, then rock wins. (The rock smashes the scissors.)
//      If one player chooses scissors and the computer chooses paper, then scissors wins. (Scissors cuts paper.)
//      If one player chooses paper and the computer chooses rock, then paper wins. (Paper wraps rock.)
//      If both the player and the computer make the same choice, the game must be played again to determine the winner.
//
// The program displays the winner and asks the user if they would like to play again.
//
//
// Programmer: Aslihan Aria Celik
// Date: 11/23/2024


#include <iostream>
#include <random>
#include <string>

using namespace std;

// Function to generate computer's choice
int generateComputerChoice() {
    // Random number engine 
    random_device engine;
    // Distribution object for numbers 1 to 3
    uniform_int_distribution<int> computerValue(1, 3);
    // Generate and return a random number between 1 and 3
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

    // Check if it is a tie
    if (userChoice == computerChoice) {
        return "tie";
    }
    // Check conditions for user win 
    else if ((userChoice == 1 && computerChoice == 3) ||
        (userChoice == 2 && computerChoice == 1) ||
        (userChoice == 3 && computerChoice == 2)) {
        return "You win!";
    }
    // therwise, computer wins
    else {
        return "Computer wins!";
    }
}

// Function to get user's choice
int getUserChoice() {
    string input;
    cout << "Please enter one of the following as your choice then hit enter: rock, paper or scissors." << endl;
    cin >> input;

    // Return corresponding number based on user input
    if (input == "rock") return 1;
    if (input == "paper") return 2;
    if (input == "scissors") return 3;

    // Return 0 if the user enters an invalid choice
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
        //Display computer's choice
        cout << "Computer chose: " << choiceName(computerChoice) << endl;

        // Determine and display the game result
        result = game(userChoice, computerChoice);

        //If it is a tie, prompt to play again
        if (result == "tie") {
            cout << "It's a tie! Play one more round to determine the winner." << endl;
            continue;
        }
        // Display the result of the game
        cout << result << endl;

        // Prompt the user to play again or not
        cout << "Do you want to play again? (yes/no): ";
        cin >> playAgain;

        // Exit the loop if the user does not want to play again
        if (playAgain != "yes") {
            break;
        }
    } 
    return 0;
}

  


