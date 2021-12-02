#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int part_1() {
    std::string input;
    std::ifstream input_file("input.txt");

    int horiz_position = 0;
    int depth = 0;
    while (std::getline(input_file, input)) {
        std::string command = input.substr(0, input.find(" "));
        int value = std::stoi(input.substr(input.find(" ")));

        if (command == "forward"){
            horiz_position += value;
        }
        else if (command == "down"){
            depth += value;
        }
        else if (command == "up"){
            depth -= value;
        }
    }
    input_file.close();

    return horiz_position * depth;
}

int part_2() {
    std::string input;
    std::ifstream input_file("input.txt");

    int horiz_position = 0;
    int depth = 0;
    int aim = 0;
    while (std::getline(input_file, input)) {
        std::string command = input.substr(0, input.find(" "));
        int value = std::stoi(input.substr(input.find(" ")));

        if (command == "forward"){
            horiz_position += value;
            depth += aim * value;
        }
        else if (command == "down"){
            aim += value;
        }
        else if (command == "up"){
            aim -= value;
        }
    }
    input_file.close();

    return horiz_position * depth;
}

int main() {
    std::cout << "Part 1: " << part_1() << std::endl;
    std::cout << "Part 2: " << part_2() << std::endl;
    return 0;
}