#include "GameManager.h"
#include <iostream>

using namespace std;

GameManager::GameManager() {
    cout << "GameManager created." << endl;
}

GameManager::~GameManager() {
    cout << "GameManager destroyed." << endl;
}

void GameManager::SetGameState(GameState newState) {
    currState = newState;
}

GameManager::GameState GameManager::GetGameState() const {
    return currState;
}

void GameManager::DisplayMainMenu() const {
    cout << "=== Main Menu ===" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Load Game" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose an option: ";
}

void GameManager::HandleMainMenuInput() {
    int choice;
    cin >> choice;
    // Handle player input here
    cin >> choice;
    switch (choice) {
    case 1:
        StartGame();
        break;
    case 2:
        LoadGame();
        break;
    case 3:
        ExitGame();
        break;
    default:
        cout << "Invalid choice. Please choose again." << endl;
        DisplayMainMenu();
        HandleMainMenuInput(); // Recursive call to handle input again
        break;
    }
}

void GameManager::StartGame()
{
    cout << "Starting new game..." << endl;

    // Initialize player character(s)
    Player player("PlayerName", 100); // Example: Create a player with 100 health points

    // Initialize game world
    //World world;
    //world.GenerateMap(); // Example: Generate a random map for the game world

    // Initialize game state
    // For example, set initial game state variables
    bool isGameOver = false;
    int currentLevel = 1;

    // Display introductory messages or story elements
    cout << "Welcome to the game! Get ready to embark on an adventure." << endl;

    // Setup everything for player first

    // Set game state to EXPLORING
    SetGameState(GameState::EXPLORING);

    // Additional setup logic can be added here as needed
}

void GameManager::LoadGame()
{

}

void GameManager::ExitGame()
{
    cout << "Exiting game..." << endl;
    exit(0); // Exit the program
}
