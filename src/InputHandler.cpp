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

    else if(command == "type"){
        std::string keyword = tokens[0];
        if(!tokens.empty()) tokens.erase(tokens.begin());
        for(std::string  &word: shellBuiltIn){
            if (word == keyword){
                std::cout << keyword << " is a shell builtin" << std::endl;
                return 0;
            }
        }
        std::cout << keyword << ": not found" << std::endl;
    }

    else {
        std::cout << input << ": command not found" << std::endl;
        return 0;
    }

    return 0;
}


/*
 * Splits the input according to the delim.
 */
std::vector<std::string> InputHandler::splitInput(const std::string &input, char delim) {
    std::vector<std::string> tokens;
    std::string  token;
    std::istringstream tokenStream(input);

    while (std::getline(tokenStream, token, delim)){
        tokens.push_back(token);
    }

    return tokens;
}
