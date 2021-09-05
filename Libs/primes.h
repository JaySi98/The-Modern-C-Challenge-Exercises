#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <list>
#include <iterator>
#include <utility>
//
#include <iostream>

#define SIEVE_FIRST_NUMBER    2
#define SIEVE_SIZE_CORRECTION 1

std::list<uint32_t> SieveOfEratosthenes(uint32_t limit);
uint32_t            BiggestPrime(uint32_t limit);
std::list<std::pair<int,int>> PrimeSixes(uint32_t limit);
