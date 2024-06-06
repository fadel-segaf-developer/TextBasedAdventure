#pragma once
#include "Scenario.h"
#include <vector>

class World {
public:
    World(const std::vector<Scenario>& preRandomizedVector); // Constructor taking pre-randomized vector
    void randomizeScenarios(); // Function to randomize scenarios
    void printScnearios();
private:
    const std::vector<Scenario>& m_preRandomizedVector; // Reference to pre-randomized vector
};
