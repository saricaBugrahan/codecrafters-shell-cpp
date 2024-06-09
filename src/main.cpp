#include <iostream>
#include <string>
#include <cstring>
#include "InputHandler.h"
int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;
  InputHandler inputHandler;
  // Uncomment this block to pass the first stage
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
