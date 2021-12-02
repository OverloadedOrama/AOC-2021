#include <iostream>
#include <fstream>
#include <string>


int read_depth() {
    std::string input;
    std::ifstream input_file("input.txt");

    int i = 0;
    int previous_number;
    int current_number;
    int count = 0;
    while (std::getline(input_file, input)) {
        int temp = std::stoi(input);
        if (i == 0) {
            previous_number = temp;
        }
        else {
            current_number = temp;
            if (current_number > previous_number){
                count++;
            }
            previous_number = temp;
        }
        i++;
    }
    input_file.close();

    return count;
}

int main() {
    int count = read_depth();
    std::cout << count << std::endl;
    return 0;
}
