#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "../Libs/argument.h"

uint8_t IsArgumentsCorrect(int argc, char **argv);
std::string ToRoman(uint32_t number);

int main(int argc, char **argv)
{
    if(IsArgumentsCorrect(argc,argv))
    {
        std::string roman =  ToRoman(ArgumentToLong(argv[1],10));
        std::cout << " Roman: " << roman << std::endl;
    }
    else
    {
        printf("Incorrect arguments!");
    }

    return 0;
}

std::string ToRoman(uint32_t number)
{
    std::vector<std::pair<uint16_t, std::string>> romanNumbers 
    {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100,  "C"}, {90,  "XC"}, {50,  "L"}, {40,  "XL"},
        {10,   "X"}, {9,   "IX"}, {5,   "V"}, {4,   "IV"},
        {1,    "I"}
    }; 
    std::string output;

    for(int i = 0; i < romanNumbers.size(); i++)
    {
        while(number >= romanNumbers[i].first)
        {
            output += romanNumbers[i].second;
            number -= romanNumbers[i].first;
        }
    }

    return output;
}

uint8_t IsArgumentsCorrect(int argc, char **argv)
{
    if(!IsMinArgumentsProvided(argc, 2)) 
    {
        return 0;
    }
    
    if(!IsArgumentNumber(argv[1])) 
    {
        return 0;
    }

    return 1;    
}