#ifndef Sum_Included
#define Sum_Included

#include "console.h"

struct digit {
    int d;
    digit * next;
};

digit * sum(digit * first, digit* second);

#endif
