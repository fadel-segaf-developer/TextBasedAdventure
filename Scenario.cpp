#include "Scenario.h"

Scenario::Scenario(int id, const std::string& type, const std::string& text)
    : m_id(id), m_type(type), m_text(text) {}

int Scenario::getId() const {
    return m_id;
}

std::string Scenario::getType() const {
    return m_type;
}

std::string Scenario::getText() const {
    return m_text;
}
