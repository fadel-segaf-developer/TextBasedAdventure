#include <iostream>
#include <thread>
#include "GameManager.h"
#include "xmlParser.h"
#include <fstream>

using namespace std;


//Variable inits

// Create GameManager instance using dynamic memory allocation 
GameManager* gameManager;
string resourceFilePath = "Scenarios.xml";

void init() 
{
    gameManager = new GameManager();

    // Parse XML data and populate vectors
    XmlParser xmlParser(resourceFilePath);
    std::vector<Scenario> preRandomizedVector = xmlParser.parseScenarios();

    int size = preRandomizedVector.size();

    std::cout << preRandomizedVector.size() << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << preRandomizedVector[i].getId() << "\n";
        std::cout << preRandomizedVector[i].getType() << "\n";
        std::cout << preRandomizedVector[i].getText() << "\n";
    }

    // Create World object with pre-populated vectors
    //World world(preRandomizedVector);

    // Print scenarios
    //world.printScnearios();

    
}
void Update() 
{
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
}

void CheckIfFileReadable()
{
    // Construct the file path relative to the project directory
    std::string resourceFilePath = "Scenarios.xml";

    // Print the file path for debugging
    std::cout << "File Path: " << resourceFilePath << std::endl;

    // Attempt to open the file
    std::ifstream file(resourceFilePath);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
    }

    // Read and print the contents of the file (optional)
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    // Close the file
    file.close();
}


int main() {

    init();

    // Main loop
    while (true) {
        Update();
        // Optional: Sleep for a short duration to prevent maxing out the CPU
        this_thread::sleep_for(chrono::milliseconds(1));
    }

    // Destroy GameManager instance and release memory
    delete gameManager;


   

    // Other code...


    return 0;
}
