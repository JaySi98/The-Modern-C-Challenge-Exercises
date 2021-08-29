#include "argument.h"

/* STATIC FUNCTIONS */
static uint8_t SizeOfString(char* argument);

static uint8_t SizeOfString(char* argument)
{
    return sizeof(argument) / sizeof(argument[0]);
}

/* MODULE FUNCTIONS */
/*!
 * @brief Converts char* to uint32_t,
 * @arg char* argument - string to be converted,
 * @arg int base - base of the convertion,
 */
uint32_t ArgumentToLong(char* argument, int base)
{
    char* errorPointer;
    uint32_t value = strtol(argument, &errorPointer, base);

    return value;
}

/*!
 * @brief Function checks if argument contains only numbers,
 * @arg char* argument - string to be checked,
 * @return uint8_t - 1 if true, 0 if false,
 */
uint8_t IsArgumentNumber(char* argument)
{
    while(*argument) 
    {
        if(*argument < '0' || *argument > '9') 
        {
            return 0;
        }

        *argument++;
    }

    return 1;
}

/*!
 * @brief Function checks if minimum number of arguments is provided
 * @arg int provided - number of provided arguments
 * @arg int min - minimum required
 * @return uint8_t - 1 if true, 0 if false,
 */
uint8_t  IsMinArgumentsProvided(int provided, int min)
{
    return provided >= min ? 1 : 0;
}
