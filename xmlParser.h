#pragma once
#include "Scenario.h"
#include <string>
#include <vector>

class XmlParser {
public:
    XmlParser(const std::string& resourceFilePath);
    std::vector<Scenario> parseScenarios() const;
    void parseAndStoreScenarios(); // Modified function to parse and store scenarios
private:
    std::string m_filePath;
    std::vector<Scenario> m_preRandomizedVector; // Vector to store parsed scenarios
};
