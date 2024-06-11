#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class InvalidConfigurationException : public std::runtime_error {
public:
    InvalidConfigurationException(const std::string& param_name, int param_value)
        : std::runtime_error("Invalid " + param_name + " value " + std::to_string(param_value)) {}
};

class InvalidOptionException : public std::runtime_error {
public:
    InvalidOptionException()
        : std::runtime_error("Invalid option, please press C to continue next turn or E to end the game") {}
};

#endif // EXCEPTIONS_H
