#pragma once

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

private:
    GameState currState = GameState::MAIN_MENU;
};
