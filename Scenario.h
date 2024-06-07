#pragma once
#include <string>
#include <vector>
#include "Choice.h"

class Scenario {
public:

    int m_id;
    std::string m_type;
    std::string m_text;
    std::vector<Choice> choices;


    Scenario() {};
    ~Scenario() {};

    Scenario(int id, const std::string& type, const std::string& text);
    int getId() const;
    std::string getType() const;
    std::string getText() const;

private:
    /*int m_id;
    std::string m_type;
    std::string m_text;*/
};
