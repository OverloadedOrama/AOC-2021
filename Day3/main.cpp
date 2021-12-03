#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>


const size_t N_OF_BITS = 12;


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

    std::bitset<N_OF_BITS> gamma_bits;
    std::bitset<N_OF_BITS> epsilon_bits;
    size_t half = i / 2;
    for (size_t j = 0; j < N_OF_BITS; j++) {
        size_t bitpos = N_OF_BITS - 1 - j; // Because bitsets work in reverse order
        if (amount_of_ones[j] > half) {
            gamma_bits.set(bitpos, true);
            epsilon_bits.set(bitpos, false);
        }
        else {
            gamma_bits.set(bitpos, false);
            epsilon_bits.set(bitpos, true);
        }
    }
    
    gamma_rate = gamma_bits.to_ulong();
    epsilon = epsilon_bits.to_ulong();

    return gamma_rate * epsilon;
}


int part_2() {
    std::string input;
    std::ifstream input_file("input.txt");

    unsigned long oxygen_rating = 0;
    unsigned long co2_rating = 0;
    size_t i = 0;
    size_t amount_of_ones = 0;
    std::vector<std::string> oxygen_numbers;
    std::vector<std::string> co2_numbers;
    std::vector<std::string> starting_with_1;
    std::vector<std::string> starting_with_0;

    while (std::getline(input_file, input)) {
        char c = input[0];
        size_t bit = (size_t)c - '0'; // Convert bit to size_t
        amount_of_ones += bit;
        if (c == '1') {
            starting_with_1.push_back(input);
        }
        else {
            starting_with_0.push_back(input);
        }
        i++;
    }
    input_file.close();
    size_t half = i / 2;
    if (amount_of_ones > half) {
        oxygen_numbers = starting_with_1;
        co2_numbers = starting_with_0;
    }
    else {
        oxygen_numbers = starting_with_0;
        co2_numbers = starting_with_1;
    }

    size_t bitpos = 1;
    while (oxygen_numbers.size() > 1) {
        amount_of_ones = 0;
        starting_with_1.clear();
        starting_with_0.clear();

        for (std::string number : oxygen_numbers) {
            char c = number[bitpos];
            size_t bit = (size_t)c - '0'; // Convert bit to size_t
            amount_of_ones += bit;
            if (c == '1') {
                starting_with_1.push_back(number);
            }
            else {
                starting_with_0.push_back(number);
            }
        }

        size_t half_ox = oxygen_numbers.size() / 2;
        if (amount_of_ones >= half_ox) {
            oxygen_numbers = starting_with_1;
        }
        else {
            oxygen_numbers = starting_with_0;
        }

        bitpos++;
    }

    bitpos = 1;
    while (co2_numbers.size() > 1) {
        amount_of_ones = 0;
        starting_with_1.clear();
        starting_with_0.clear();

        for (std::string number : co2_numbers) {
            char c = number[bitpos];
            size_t bit = (size_t)c - '0'; // Convert bit to size_t
            amount_of_ones += bit;
            if (c == '1') {
                starting_with_1.push_back(number);
            }
            else {
                starting_with_0.push_back(number);
            }
        }

        size_t half_co2 = co2_numbers.size() / 2;
        if (amount_of_ones < half_co2) {
            co2_numbers = starting_with_1;
        }
        else {
            co2_numbers = starting_with_0;
        }
        
        bitpos++;
    }

    std::bitset<N_OF_BITS> oxygen_bits(oxygen_numbers[0]);
    std::bitset<N_OF_BITS> co2_bits(co2_numbers[0]);

    oxygen_rating = oxygen_bits.to_ulong();
    co2_rating = co2_bits.to_ulong();
    return oxygen_rating * co2_rating;
}


int main() {
    std::cout << "Part 1: " << part_1() << std::endl;
    std::cout << "Part 2: " << part_2() << std::endl;
    return 0;
}