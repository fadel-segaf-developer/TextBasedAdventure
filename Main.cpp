#include <iostream>
#include <thread>
#include "GameManager.h"

using namespace std;

int main() {
    // Create GameManager instance using dynamic memory allocation
    GameManager* gameManager = new GameManager();

    // Main loop
    while (true) {
        switch (gameManager->GetGameState()) {
        case GameManager::GameState::MAIN_MENU:
            gameManager->DisplayMainMenu();
            gameManager->HandleMainMenuInput();
            break;
        case GameManager::GameState::EXPLORING:
            // Implement exploring logic
            break;
        case GameManager::GameState::GAME_OVER:
            // Implement game over logic
            break;
        }
        // Optional: Sleep for a short duration to prevent maxing out the CPU
        this_thread::sleep_for(chrono::milliseconds(1));
    }

    // Destroy GameManager instance and release memory
    delete gameManager;

    return 0;
}
