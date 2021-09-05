#ifndef ARGUMENT_H_
#define ARGUMENT_H_

#include <errno.h>   // for errno
#include <limits.h>  // for INT_MAX, INT_MIN
#include <stdlib.h>  // for strtol
#include <stdio.h>
#include <stdint.h> 


uint32_t ArgumentToLong(char* argument, int base);
uint8_t  IsArgumentNumber(char* argument);
uint8_t  IsMinArgumentsProvided(int provided, int min);

#endif // ARGUMENT_H_