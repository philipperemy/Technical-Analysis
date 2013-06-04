#include "../ta-lib/c/include/ta_libc.h"
#include "TA_Entity.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

#ifndef TA_H
#define TA_H


class TA
{
    public:
        static TA_Entity MMA(TA_Real[], int begin, int end, int optInTimePeriod);
    protected:
    private:
};

#endif // TA_H
