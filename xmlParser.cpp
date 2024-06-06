#include "XmlParser.h"
#include "rapidxml/rapidxml.hpp"
#include <fstream>
#include <iostream>

using namespace rapidxml;

XmlParser::XmlParser(const std::string& resourceFilePath) : m_filePath(resourceFilePath) {}

std::vector<Scenario> XmlParser::parseScenarios() const {
    std::vector<Scenario> scenarios;

    // Load XML file
    std::ifstream file(m_filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open XML file: " << m_filePath << std::endl;
        return scenarios; // Return empty vector on failure
    }
    else
    {
        std::cout << " file can be opened";
    }

    // Read XML data
    std::string xmlData((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close(); // Close file after reading

    // Parse XML data
    xml_document<> doc;
    try {
        doc.parse<0>(&xmlData[0]);
    }
    catch (const parse_error& e) {
        std::cerr << "XML parsing error: " << e.what() << std::endl;
        return scenarios; // Return empty vector on parsing error
    }

    // Access XML elements and parse scenarios
    // Code for parsing scenarios...

    return scenarios;
}

void XmlParser::parseAndStoreScenarios() {
    m_preRandomizedVector = parseScenarios();
}
