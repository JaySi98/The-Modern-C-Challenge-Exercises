#include <iostream>
#include <string>
#include <math.h>
#include <iomanip> // std::setprecision
#include "../Libs/argument.h"

#define PRECISION 10

uint8_t IsArgumentsCorrect(int argc, char **argv);
double Gauss_Legendre(uint8_t iteration);

int main(int argc, char **argv)
{
    if(IsArgumentsCorrect(argc,argv))
    {
        double calculatedPi =  Gauss_Legendre(ArgumentToLong(argv[1],10));
        std::cout << " Pi: " << std::setprecision(PRECISION) << calculatedPi << std::endl;
    }
    else
    {
        printf("Incorrect arguments!");
    }

    return 0;
}

double Gauss_Legendre(uint8_t iteration)
{
    double aPrev;
    double an = 1.0;
    double bn = 1.0 /(sqrt(2));
    double tn = 0.25;
    double pn = 1.0;

    for(int i = 0; i < iteration; i++)
    {
        aPrev = an;
        an    = (aPrev + bn) / 2;
        bn    = sqrt(aPrev*bn);
        tn    = tn - (pn * pow(aPrev - an,2));
        pn    = 2 * pn;
    }

    return (pow(an+bn,2) / (4 * tn));
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