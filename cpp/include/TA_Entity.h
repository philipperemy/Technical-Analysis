#include "../ta-lib/c/include/ta_libc.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

#ifndef TA_ENTITY_H
#define TA_ENTITY_H

class TA_Entity
{
    public:
        TA_Entity(TA_Real begin, TA_Real nbElements, TA_Real* out);
        TA_Real getBegin();
        TA_Real getNbElements();
        TA_Real* getPrices();
        TA_Real get(int id);

        virtual ~TA_Entity();

    protected:
    private:
        TA_Real _begin;
        TA_Real _nbElements;
        TA_Real _out[4096];
};

#endif // TA_ENTITY_H
