//
// Created by bugra on 09.06.2024.
//

#ifndef SHELL_STARTER_CPP_INPUTHANDLER_H
#define SHELL_STARTER_CPP_INPUTHANDLER_H


#include <string>
#include <vector>
enum COMMAND {EXIT=1,ECHO,UNDEFINED};


class InputHandler {
    public:
         int handleUserInput(const std::string &input);
         std::vector<std::string> splitInput(const std::string &input, char delimeter);
        InputHandler() = default;
};


#endif //SHELL_STARTER_CPP_INPUTHANDLER_H
