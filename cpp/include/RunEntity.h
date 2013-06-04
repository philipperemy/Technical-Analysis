#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sstream>

#ifndef RUN_ENTITY_H
#define RUN_ENTITY_H

#include "../include/CSVParser.h"
#include "../ta-lib/c/include/ta_libc.h"
#include <math.h>


class RunEntity
{
    public:
        RunEntity();
        void run(CSVParser* csvparser);
		void check_sma(int sma_period_1, int sma_period_2);
        virtual ~RunEntity();
	private:
		int array_size;
		TA_Real* openPrice;
		TA_Real* highPrice;
		TA_Real* lowPrice;
		TA_Real* closePrice;
		TA_Real* volumePrice;
};

#endif // RUN_ENTITY_H
