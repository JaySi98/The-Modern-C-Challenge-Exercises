#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string>
#include <bitset>
#include <iostream>

#define UPPER_LIMIT 32
#define BIT_NUMBER   5

std::string ToBinary(uint8_t value, uint8_t bitNumber);
std::string ToGray(uint8_t value, uint8_t bitNumber);

int main(int argc, char **argv)
{
    std::string binary;
    std::string gray;

    for(int i = 0; i < UPPER_LIMIT; i++)
    {
        binary = ToBinary(i,BIT_NUMBER);
        gray   = ToGray(i, BIT_NUMBER);

        std::cout << i << " | " << binary << " | " << gray << std::endl;
    }

    return 0;
}

std::string ToBinary(uint8_t value, uint8_t bitNumber)
{
    std::string output;
    output = std::bitset<UPPER_LIMIT>(value).to_string();

    return output.substr(UPPER_LIMIT - bitNumber, bitNumber);
}

std::string ToGray(uint8_t value, uint8_t bitNumber)
{
    value ^= (value >> 1);
    return ToBinary(value, bitNumber);
}