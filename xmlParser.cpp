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
        std::cout << "File opened successfully, XML file: " << m_filePath << std::endl;
    }

    // Read XML data
    std::string xmlData((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    std::cout << xmlData;
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
    // Access XML elements
    xml_node<>* root = doc.first_node("scenarios");
    if (!root) {
        std::cerr << "No 'scenarios' root node found" << std::endl;
        return scenarios;
    }

    for (xml_node<>* rarityNode = root->first_node("rarity"); rarityNode; rarityNode = rarityNode->next_sibling("rarity")) {
        const char* rarityType = rarityNode->first_attribute("type")->value();

        for (xml_node<>* scenarioNode = rarityNode->first_node("scenario"); scenarioNode; scenarioNode = scenarioNode->next_sibling("scenario")) {
            Scenario scenario;

            // Extract scenario ID
            xml_attribute<>* idAttr = scenarioNode->first_attribute("id");
            if (idAttr) {
                scenario.m_id = std::stoi(idAttr->value());
            }

            // Extract scenario type
            xml_node<>* typeNode = scenarioNode->first_node("type");
            if (typeNode) {
                scenario.m_type = typeNode->value();
            }

            // Extract scenario text
            xml_node<>* textNode = scenarioNode->first_node("text");
            if (textNode) {
                scenario.m_type = textNode->value();
            }

            // Extract scenario choices
            xml_node<>* choicesNode = scenarioNode->first_node("choices");
            if (choicesNode) {
                for (xml_node<>* choiceNode = choicesNode->first_node("choice"); choiceNode; choiceNode = choiceNode->next_sibling("choice")) {
                    Choice choice;

                    xml_node<>* choiceTextNode = choiceNode->first_node("text");
                    if (choiceTextNode) {
                        choice.m_text = choiceTextNode->value();
                    }

                    xml_node<>* choiceResultNode = choiceNode->first_node("result");
                    if (choiceResultNode) {
                        choice.m_text_result = choiceResultNode->value();
                    }

                    xml_node<>* choiceResultTextNode = choiceNode->first_node("result_text");
                    if (choiceResultTextNode) {
                        choice.m_text_result_text = choiceResultTextNode->value();
                    }

                    scenario.choices.push_back(choice);
                }
            }

            scenarios.push_back(scenario);
        }
    }

    return scenarios;
}

void XmlParser::parseAndStoreScenarios() {
    m_preRandomizedVector = parseScenarios();
}
