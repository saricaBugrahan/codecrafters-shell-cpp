#include <iostream>
#include <string>
#include <cstring>
#include "InputHandler.h"
int main() {
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;
    std::string path(getenv("PATH"));
    std::string home(getenv("HOME"));
    InputHandler inputHandler(path,home);

    while (true){
        std::cout << "$ ";
        std::string input;
        std::getline(std::cin, input);
        int result = inputHandler.handleUserInput(input);

        if (result == EXIT){
            return 0;
        }
    }
}
