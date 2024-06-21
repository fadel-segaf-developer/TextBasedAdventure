#pragma once
#include <string>
#include <vector>

using namespace std;
class Choice
{
public:
    Choice() {};
    ~Choice() {};

    /*Accessors*/
    string getText() const { return m_text; }
    string getTextResult() const { return m_text_result; }
    string getTextResultText() const { return m_text_result_text; }

    /*Mutators*/
    void setText(string val) { m_text = val; }
    void setTextResult(string val) { m_text_result = val; }
    void setTextResultText(string val) { m_text_result_text = val; }
private:
    string m_text;
    string m_text_result;
    string m_text_result_text;
};

