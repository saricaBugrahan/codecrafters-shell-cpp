//
// Created by bugra on 09.06.2024.
//

#ifndef SHELL_STARTER_CPP_INPUTHANDLER_H
#define SHELL_STARTER_CPP_INPUTHANDLER_H


#include <string>
#include <vector>
enum COMMAND {EXIT=1,ECHO,UNDEFINED};


class InputHandler {
    std::vector<std::string> shellBuiltIn = {"echo","exit","type"};
    public:
         int handleUserInput(const std::string &input);
         InputHandler() = default;
    private:
        std::vector<std::string> splitInput(const std::string &input, char delim);
};


#endif //SHELL_STARTER_CPP_INPUTHANDLER_H
