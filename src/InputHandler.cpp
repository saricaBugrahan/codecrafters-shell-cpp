//
// Created by bugra on 09.06.2024.
//
#include <vector>
#include "InputHandler.h"
#include <iostream>
#include <sstream>


int InputHandler::handleUserInput(const std::string &input) {
    std::vector<std::string> tokens = splitInput(input,' ');
    std::string command = tokens[0];
    if(!tokens.empty()) tokens.erase(tokens.begin());

    if(command == "exit"){
        return EXIT;
    }

    else if(command == "echo"){
        for (size_t i = 0; i < tokens.size(); ++i) {
            std::cout << tokens[i];
            if (i < tokens.size() - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    else {
        std::cout << input << ": command not found" << std::endl;
        return 0;
    }

    return 0;
}

std::vector<std::string> InputHandler::splitInput(const std::string &input, char delimeter) {
    std::vector<std::string> tokens;
    std::string  token;
    std::istringstream tokenStream(input);

    while (std::getline(tokenStream,token,delimeter)){
        tokens.push_back(token);
    }

    return tokens;
}
