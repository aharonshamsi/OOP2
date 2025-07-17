#pragma once
#include <exception>
#include <string>

class GameException : public std::exception {
public:
    explicit GameException(const std::string& messageError)
        : m_messageError(messageError) {}

    const char* what() const override { return m_messageError.c_str(); }

private:
    std::string m_messageError;
};
