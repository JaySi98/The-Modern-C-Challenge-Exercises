#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "../Libs/argument.h"

uint32_t HighestCommonDivisior(uint32_t firstNumber, uint32_t secondNumber);
uint8_t  IsArgumentsCorrect(int argc, char **argv);

int main(int argc, char **argv)
{
    if(IsArgumentsCorrect(argc,argv))
    {
        uint32_t firstNumber  = ArgumentToLong(argv[1], 10);
        uint32_t secondNumber = ArgumentToLong(argv[2], 10);

        uint32_t result = HighestCommonDivisior(firstNumber, secondNumber);
        
        printf("result = %li", result);
    }
    else
    {
        printf("Incorrect arguments!");
    }

    return 0;
}

uint32_t HighestCommonDivisior(uint32_t first, uint32_t second)
{
    while(second != 0)
    {
        uint8_t rest = first % second;
        first = second;
        second = rest;
    }

    return first;
}

uint8_t  IsArgumentsCorrect(int argc, char **argv)
{
    if(!IsMinArgumentsProvided(argc, 3)) return 0;

    if(!IsArgumentNumber(argv[1]) && !IsArgumentNumber(argv[2])) return 0;

    return 1;    
}