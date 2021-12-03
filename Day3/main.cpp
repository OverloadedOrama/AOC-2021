#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>


int part_1() {
    std::string input;
    std::ifstream input_file("input.txt");

    unsigned long gamma_rate = 0;
    unsigned long epsilon = 0;
    size_t i = 0;
    std::vector<size_t> amount_of_ones;

    while (std::getline(input_file, input)) {
        size_t j = 0;
        for(auto c : input) {
            size_t bit = (size_t)c - '0'; // Convert bit to size_t
            if(i == 0) {
                amount_of_ones.push_back(bit);
            }
            else {
                amount_of_ones[j] += bit;
            }

            j++;
        }

        i++;
    }
    input_file.close();

    std::bitset<12> gamma_bits;
    std::bitset<12> epsilon_bits;
    size_t half = i / 2;
    for (size_t j = 0; j < gamma_bits.size(); j++) {
        size_t bitpos = gamma_bits.size() - 1 - j; // Because bitsets work in reverse order
        if (amount_of_ones[j] > half) {
            gamma_bits.set(bitpos, true);
            epsilon_bits.set(bitpos, false);
        }
        else {
            gamma_bits.set(bitpos, false);
            epsilon_bits.set(bitpos, true);
        }
    }
    
    gamma_rate = gamma_bits.to_ullong();
    epsilon = epsilon_bits.to_ullong();

    return gamma_rate * epsilon;
}

int main() {
    std::cout << "Part 1: " << part_1() << std::endl;
    //std::cout << "Part 2: " << part_2() << std::endl;
    return 0;
}