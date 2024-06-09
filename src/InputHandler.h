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
         std::string  path;
         int handleUserInput(const std::string &input);
         InputHandler() = default;
         explicit InputHandler(const std::string &path);
    private:
        std::vector<std::string> splitInput(const std::string &input, char delim);
        void handleEchoCommand(std::vector<std::string> tokens);
        void handleTypeCommand(std::vector<std::string> tokens);
        std::string getPathCommand(const std::string &command);
        bool isShellBuiltIn(const std::string &command);
};


#endif //SHELL_STARTER_CPP_INPUTHANDLER_H
