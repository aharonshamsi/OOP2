#pragma once
#include <exception>
#include <string>


class MatrixException : public std::exception {

public:
	MatrixException(const std::string& message) : m_errorMessage(message) {}

	const char* what() const override { return m_errorMessage.c_str(); }; 


protected:
	std::string m_errorMessage;
};