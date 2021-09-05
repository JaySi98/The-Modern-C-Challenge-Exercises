#include "../Libs/argument.h"
#include "../Libs/primes.h"

uint8_t IsArgumentsCorrect(int argc, char **argv);

int main(int argc, char **argv)
{
    if(IsArgumentsCorrect(argc,argv))
    {
        uint32_t limit  = ArgumentToLong(argv[1], 10);
        uint32_t biggestPrime = BiggestPrime(limit);

        printf("Biggest prime = %lu", biggestPrime);
    }
    else
    {
        printf("Incorrect arguments!");
    }

    return 0;
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