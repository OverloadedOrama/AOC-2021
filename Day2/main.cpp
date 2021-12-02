#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int read_depth() {
    std::string input;
    std::ifstream input_file("input.txt");

    std::vector<int> measurements;
    int count = 0;
    while (std::getline(input_file, input)) {
        measurements.push_back(std::stoi(input));

        int i = measurements.size() - 1;
        if(i > 2){
            int prev_sum = measurements[i - 1] + measurements[i - 2] + measurements[i - 3];
            int current_sum = measurements[i] + measurements[i - 1] + measurements[i - 2];
            if(current_sum > prev_sum){
                count++;
            }
        }
    }
    input_file.close();

    return count;
}

int main() {
    int count = read_depth();
    std::cout << count << std::endl;
    return 0;
}