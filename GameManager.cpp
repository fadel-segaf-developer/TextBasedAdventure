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
}
