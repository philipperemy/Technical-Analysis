#include "../include/TA.h"

using namespace std;

TA_Entity TA::MMA(TA_Real * closePrice, int begin, int end, int optInTimePeriod)
{
    int size = end-begin+1;
    TA_RetCode retCode;
    TA_Real    out[size];
    TA_Integer outBeg;
    TA_Integer outNbElement;
    retCode = TA_MA(begin, end,&closePrice[0],5,TA_MAType_SMA,
                    &outBeg, &outNbElement, &out[0]);

    return TA_Entity(outBeg, outNbElement, out);
}
