#pragma once
#include "Player.h"
#include "World.h"


class GameManager
{
public:
    enum class GameState {
        MAIN_MENU,
        EXPLORING,
        GAME_OVER
    };

    GameManager();
    ~GameManager();

    // Getter method (const-correctness)
    GameState GetGameState() const;

    // Setter method
    void SetGameState(GameState newState);

    void DisplayMainMenu() const;
    void HandleMainMenuInput();

    void StartGame();
    void LoadGame();
    void ExitGame();

private:
    GameState currState = GameState::MAIN_MENU;
};
