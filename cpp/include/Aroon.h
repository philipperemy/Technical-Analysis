#ifndef AROON_H
#define AROON_H

#include "../include/CSVParser.h"

class Aroon
{
    public:
        Aroon(CSVParser& csvparser, double highPrice[], double lowPrice[]);
        virtual ~Aroon();
    protected:
    private:
};

#endif // AROON_H
