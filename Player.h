#pragma once
#include <string>

class Player {
public:
    Player(const std::string& name, int health);

    // Other member functions and variables...

private:
    std::string name;
    int health;
    // Other player attributes...
};
