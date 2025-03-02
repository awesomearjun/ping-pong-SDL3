#include <iostream>

int main(int argc, char *argv[]) {
    int num = 5;
    std::cout << "SDL2 restart" << std::endl;
    num++;
    std::cin.get();
    std::cout << num << std::endl;
    std::cin.get();
}