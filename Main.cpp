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

// All non-main custom functions
// maybe better if move to XMLParser class?

void PopulateScenario()
{
    // Parse XML data and populate vectors
    XmlParser xmlParser(resourceFilePath);
    xmlParser.parseAndStoreScenarios();
}

void DebugXmlParser(XmlParser& xmlParser) {

    vector<Scenario> preRandomizedVector = xmlParser.getPreRandomizedScenario();
    int size = preRandomizedVector.size();

    for (const auto& obj : preRandomizedVector) {
        std::cout << " ID : " << obj.getId() << std::endl;
        std::cout << " Text : " << obj.getText() << std::endl;
        std::cout << " Type : " << obj.getType() << std::endl;

        std::cout << "Choices : \n";
        for (const auto& item : obj.choices) {
            std::cout << " " << item.getText() << "\n";
            std::cout << " " << item.getTextResult() << "\n";
            std::cout << " " << item.getTextResultText() << "\n";
        }
        std::cout << std::endl;
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

//Actual Main.cpp purpose

void Init() {
    // Initialization logic that must happen before the game starts
    std::cout << "Init called" << std::endl;
    gameManager = new GameManager();
}

void Start() {
    // Initialization logic that relies on other components being initialized

    //populateScenario
    PopulateScenario();
}

void FixedUpdate() {
    // This function will be called every millisecond
    std::cout << "FixedUpdate called" << std::endl;

    switch (gameManager->GetGameState()) {
    case GameManager::GameState::MAIN_MENU:
        gameManager->DisplayMainMenu();
        gameManager->HandleMainMenuInput();
        break;
    case GameManager::GameState::EXPLORING:
        break;
    case GameManager::GameState::GAME_OVER:
        break;
    }
}

void Update() {
    // This function will be called every frame
    std::cout << "Update called" << std::endl;
}

int main() {
    using namespace std::chrono;

    // Call Init and Start functions
    Init();
    Start();

    // Option to limit FPS or make it unlimited
    bool limitFPS = true; // Set this to false to make FPS unlimited
    const int desiredFPS = 60;
    milliseconds frameDuration(1000 / desiredFPS); // Calculate frame duration based on desired FPS
    milliseconds fixedUpdateInterval(1); // 1 millisecond interval for FixedUpdate

    steady_clock::time_point lastFixedUpdate = steady_clock::now();
    steady_clock::time_point lastFrame = steady_clock::now();

    while (true) {
        steady_clock::time_point now = steady_clock::now();

        // FixedUpdate logic
        if (duration_cast<milliseconds>(now - lastFixedUpdate) >= fixedUpdateInterval) {
            FixedUpdate();
            lastFixedUpdate = now;
        }

        // Update logic
        if (!limitFPS || duration_cast<milliseconds>(now - lastFrame) >= frameDuration) {
            Update();
            lastFrame = now;
        }

        // Sleep for a short duration to prevent 100% CPU usage when FPS is limited
        if (limitFPS) {
            std::this_thread::sleep_for(milliseconds(1));
        }
    }

    return 0;
}





