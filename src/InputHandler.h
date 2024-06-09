//
// Created by bugra on 09.06.2024.
//

#ifndef SHELL_STARTER_CPP_INPUTHANDLER_H
#define SHELL_STARTER_CPP_INPUTHANDLER_H


#include <string>
#include <vector>

#define EXIT 1

class InputHandler {
    std::vector<std::string> shellBuiltIn = {"echo","exit","type"};
    public:
         InputHandler() = default;
         explicit InputHandler(const std::string &path);
         std::string  path;
         std::string currentDirectory = "/app";
         int handleUserInput(const std::string &input);

    private:
        std::vector<std::string> splitInput(const std::string &input, char delim);
        std::string getPathCommand(const std::string &command);
        void handleEchoCommand(std::vector<std::string> &tokens);
        void handleTypeCommand(std::vector<std::string> &tokens);
        void handleCustomCommand(std::vector<std::string> &tokens,std::string &command);
        void handleUnknownCommand(std::string &command);
        void handlePwdCommand();
        void handleCdCommand(std::vector<std::string> &tokens);
        bool isShellBuiltIn(const std::string &command);
};


#endif //SHELL_STARTER_CPP_INPUTHANDLER_H
