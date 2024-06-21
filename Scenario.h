#pragma once
#include <string>
#include <vector>
#include "Choice.h"

using namespace std;

class Scenario {
public:
    Scenario() {};
    ~Scenario() {};

    Scenario(int id, const std::string& type, const std::string& text);
 

    /*Accessors*/
    int getId() const { return m_id; }
    string getType() const { return m_type; }
    string getText() const { return m_text; }


    /*Mutators*/
    void setId(int val) { m_id = val; }
    void setType(string val) { m_type = val; }
    void setText(string val) { m_text = val; }


public:
    std::vector<Choice> choices;
private:
    int m_id;
    std::string m_type;
    std::string m_text;
    
};
