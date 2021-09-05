#include "../Libs/argument.h"
#include "../Libs/primes.h"

uint8_t IsArgumentsCorrect(int argc, char **argv);

int main(int argc, char **argv)
{
    if(IsArgumentsCorrect(argc,argv))
    {
        uint32_t limit  = ArgumentToLong(argv[1], 10);
        std::list<std::pair<int,int>> output = PrimeSixes(limit);

        printf("List of prime sixes\n");
        for (std::list<std::pair<int,int>>::iterator it = output.begin(); it != output.end(); ++it)
        {   
            printf("%lu, %lu\n", std::get<0>(*it), std::get<1>(*it));
        }
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