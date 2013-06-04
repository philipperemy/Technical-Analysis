#ifndef CANDLESTICK_H
#define CANDLESTICK_H

#include "../include/CSVParser.h"

class Candlestick
{
    public:
        Candlestick();
        Candlestick(CSVParser& csvparser, double openPrice[], double highPrice[]
                         ,double lowPrice[], double closePrice[]);
        virtual ~Candlestick();
    protected:
    private:
};

#endif // CANDLESTICK_H
