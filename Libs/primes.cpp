#include "primes.h"

// static functions definitions
static uint32_t* GenerateSieve(uint32_t limit);

uint32_t BiggestPrime(uint32_t limit)
{
    std::list<uint32_t> primes = SieveOfEratosthenes(limit);

    return primes.back();
}

std::list<std::pair<int,int>> PrimeSixes(uint32_t limit)
{
    std::list<std::pair<int,int>> primeSixes;
    std::list<uint32_t> primes = SieveOfEratosthenes(limit);


    for (std::list<uint32_t>::iterator it = primes.begin(); it != primes.end(); ++it)
    {
        if(it != primes.end())
        {
            if(*std::next(it,1) == *it+6)
            {
                std::pair<int,int> pair = {*it, *std::next(it,1)};
                primeSixes.push_back(pair);
            }
        }
    }

    return primeSixes;
}

/*!
 * @brief Function returns array of prime numbers 
 * using sieve of Eratosthenes method
 */
std::list<uint32_t> SieveOfEratosthenes(uint32_t limit)
{
    std::list<uint32_t> primes;
    uint32_t* sieve = GenerateSieve(limit);
    uint32_t  upperLimit = sqrt(limit);

    for(int i = 0; i <= upperLimit; i++)
    {
        uint32_t currentNumber = sieve[i];
        if(currentNumber)
        {
            uint32_t start = (currentNumber*currentNumber)-SIEVE_FIRST_NUMBER; 
            for(int j = start; j < limit-SIEVE_SIZE_CORRECTION; j+=currentNumber)
            {
                sieve[j] = 0;
            }
        }
    }

    for(int i = 0; i < limit-SIEVE_SIZE_CORRECTION; i++)
    {
        if(sieve[i])
        {
            primes.push_back(sieve[i]);
        }
    }

    delete sieve;
    return primes;
}

static uint32_t* GenerateSieve(uint32_t limit)
{
    uint32_t  sieveSize = limit-SIEVE_SIZE_CORRECTION;
    uint32_t* sieve = new uint32_t[sieveSize];
    
    for(int i = 0; i < sieveSize; i++)
    {
        sieve[i] = SIEVE_FIRST_NUMBER+i;
    }

    return sieve;
}



