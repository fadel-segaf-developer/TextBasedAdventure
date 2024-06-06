#include <iostream>
#include <vector>
class World {
public:
    World(std::vector<int>& preRandomizedVector) : m_preRandomizedVector(preRandomizedVector) {
        // Seed the random number generator with the current time
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        // Randomize the scenarios during initialization
        randomizeScenarios();

        // Copy the first 5 elements from preRandomizedVector to finalizedVector
        finalizeScenarios();
    }

    void printScenarios() {
        std::cout << "Pre-Randomized Vector:" << std::endl;
        printVector(m_preRandomizedVector);

        std::cout << "\nFinalized Vector:" << std::endl;
        printVector(m_finalizedVector);
    }

private:
    void randomizeScenarios() {
        // Shuffle the vector using a basic randomization algorithm
        for (int i = m_preRandomizedVector.size() - 1; i > 0; --i) {
            // Generate a random index between 0 and i (inclusive)
            int j = std::rand() % (i + 1);

            // Swap the elements at indices i and j
            std::swap(m_preRandomizedVector[i], m_preRandomizedVector[j]);
        }
    }

    void finalizeScenarios() {
        // Copy the first 5 elements from preRandomizedVector to finalizedVector
        for (int i = 0; i < 5 && i < m_preRandomizedVector.size(); ++i) {
            m_finalizedVector.push_back(m_preRandomizedVector[i]);
        }
    }

    void printVector(const std::vector<int>& vec) {
        for (int i : vec) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    std::vector<int>& m_preRandomizedVector;
    std::vector<int> m_finalizedVector;
};
