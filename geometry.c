#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "geometry.h"

float fpc(int r)
{
    float Pc;
    Pc = 2 * 3.14 * r;
    return Pc;
}

float fsc(int r)
{
    float Sc;
    Sc = 3.14 * pow(r, 2);
    return Sc;
}