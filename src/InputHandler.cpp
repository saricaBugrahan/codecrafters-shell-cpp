//
// Created by bugra on 09.06.2024.
//
#include <vector>
#include "InputHandler.h"
#include <iostream>
#include <sstream>
#include <filesystem>
#include <cstdlib>


InputHandler::InputHandler(const std::string &path,const std::string &home) {
    this->path = path;
    this->home= home;
}

int InputHandler::handleUserInput(const std::string &input) {
    std::vector<std::string> tokens = splitElement(input, ' ');
    std::string command = tokens[0];
    if(!tokens.empty()) tokens.erase(tokens.begin());

    if(command == "exit"){
        return EXIT;
    }

    else if(command == "echo"){
        handleEchoCommand(tokens);
    }

    else if(command == "type"){
        handleTypeCommand(tokens);
    }

    else if (command == "pwd"){
        handlePwdCommand();
    }

    else if (command == "cd"){
        handleCdCommand(tokens);
    }

    else {
        handleCustomCommand(tokens,command);
    }

    return 0;
}


/*
 * Splits the input according to the delim.
 */
std::vector<std::string> InputHandler::splitElement(const std::string &input, char delim) {
    std::vector<std::string> tokens;
    std::string  token;
    std::istringstream tokenStream(input);

    while (std::getline(tokenStream, token, delim)){
        tokens.push_back(token);
    }

    return tokens;
}

void InputHandler::handleEchoCommand(std::vector<std::string> &tokens) {
    for (size_t i = 0; i < tokens.size(); ++i) {
        std::cout << tokens[i];
        if (i < tokens.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout<<std::endl;
}
void InputHandler::handlePwdCommand() {
    std::cout<< this->currentDirectory << std::endl;
}

void InputHandler::handleCdCommand(std::vector<std::string> &tokens) {
    std::vector<std::string> paths = splitElement(tokens[0],'/');
    std::string tmpDirectory(currentDirectory);
    bool isDoubleDotEntered = false;
    for(std::string &pt : paths){
        if (pt == "."){
            tokens[0] = tmpDirectory.append(tokens[0].substr(1));
        }
        else if(pt == ".."){
            tmpDirectory = tmpDirectory.substr(0,tmpDirectory.find_last_of('/'));
            isDoubleDotEntered = true;
        }
        else if(pt == "~"){
            tokens[0] = home;
        }
        else if(isDoubleDotEntered){
            tmpDirectory += pt;
        }
    }
    if (isDoubleDotEntered){
         tokens[0] = tmpDirectory;
    }
    bool isDirectoryIn = std::filesystem::exists(tokens[0]);
    if (!isDirectoryIn){
        std::cout << "cd: " <<tokens[0] << ": No such file or directory" << std::endl;
        return;
    }
    this->currentDirectory = tokens[0];

}


void InputHandler::handleTypeCommand(std::vector<std::string> &tokens) {
    std::string keyword = tokens[0];
    if(!tokens.empty()) tokens.erase(tokens.begin());
    std::string commandPath = getPathCommand(keyword);
    if (isShellBuiltIn(keyword)){
        std::cout << keyword << " is a shell builtin" << std::endl;
    }
    else if (!commandPath.empty()){
        std::cout << keyword << " is " << commandPath << std::endl;
    }
    else{
        std::cout << keyword << ": not found" << std::endl;
    }

}

void InputHandler::handleUnknownCommand(std::string &command) {
    std::cout << command << ": command not found" << std::endl;
}


void InputHandler::handleCustomCommand(std::vector<std::string> &tokens,std::string &command) {
    std::string customCommandChecker = getPathCommand(command);
    if (customCommandChecker.empty()){
        handleUnknownCommand(command);
        return;
    }
    customCommandChecker.append(" ").append(tokens[0]);
    std::system(customCommandChecker.c_str());
}

std::string InputHandler::getPathCommand(const std::string &command) {
    std::vector<std::string> paths = splitElement(this->path, ':');
    for(std::string &pt: paths){
        std::string checkedPathCommand = pt.append("/").append(command);
        if (std::filesystem::exists(checkedPathCommand)){
            return checkedPathCommand;
        }
    }
    return "";
}

bool InputHandler::isShellBuiltIn(const std::string &command) {
    for(std::string  &word: shellBuiltIn){
        if (word == command){
            return true;
        }
    }
    return false;
}

