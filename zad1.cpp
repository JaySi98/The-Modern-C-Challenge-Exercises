#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "../Libs/argument.h"

uint8_t  IsArgumentsCorrect(int argc, char **argv);
uint32_t CountSum(uint32_t limit);

int main(int argc, char **argv)
{
    if(IsArgumentsCorrect(argc, argv))
    {
        uint32_t limit = ArgumentToLong(argv[1], 10);
        uint32_t sum = CountSum(limit);  

        printf("Sum = %li", sum);
    }
    else
    {
        printf("Invalid Arguments!");
    }

    return 0;
}

uint32_t CountSum(uint32_t limit)
{
    uint32_t sum = 0;
    for(unsigned int i = 3; i <= limit; ++i)
    {
        if((i % 3 == 0) || (i % 5 == 0))
        {
            sum += i;
        }
    }

    return sum;
}

uint8_t  IsArgumentsCorrect(int argc, char **argv)
{
    if(!IsMinArgumentsProvided(argc, 2)) return 0;

    if(!IsArgumentNumber(argv[1])) return 0;

    return 1;    
}