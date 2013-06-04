#include <iostream>
#include "ta-lib/c/include/ta_libc.h"
#include "include/CSVParser.h"
#include "include/Candlestick.h"
#include "include/Aroon.h"s
#include <math.h>

using namespace std;

static const int OPEN = 0;
static const int HIGH = 1;
static const int LOW = 2;
static const int CLOSE = 3;
static const int VOLUME = 4;

int main(void)
{
    CSVParser csvparser("Cotations20110101.csv");
    csvparser.debug();

    TA_Real openPrice[csvparser.countLines()];
    TA_Real highPrice[csvparser.countLines()];
    TA_Real lowPrice[csvparser.countLines()];
    TA_Real closePrice[csvparser.countLines()];
    TA_Real volumePrice[csvparser.countLines()];


    for(int i=0; i<csvparser.countLines(); i++) {
        openPrice[i] = csvparser.getValue(i, OPEN);
        highPrice[i] = csvparser.getValue(i, HIGH);
        lowPrice[i] = csvparser.getValue(i, LOW);
        closePrice[i] = csvparser.getValue(i, CLOSE);
        volumePrice[i] = csvparser.getValue(i, VOLUME);
    }

    /// MMA10
    cout << "Calculating MMA10 ... ";
    TA_Real    outMMA10[csvparser.countLines()];
    TA_Integer outBegMMA10;
    TA_Integer outNbElementMMA10;

    TA_RetCode retCode = TA_MA(0, csvparser.countLines()-1,
                 &closePrice[0], 10, TA_MAType_SMA,
                 &outBegMMA10, &outNbElementMMA10, &outMMA10[0]);

    cout << "[OK]" << endl;
    //for(int i=0; i < outNbElementMMA10; i++ )
    //    printf( "Day %d = %f\n", outBegMMA10+i, outMMA10[i]);


    ///MMA20
    cout << "Calculating MMA20 ... ";
    TA_Real    outMMA20[csvparser.countLines()];
    TA_Integer outBegMMA20;
    TA_Integer outNbElementMMA20;

    retCode = TA_MA(0, csvparser.countLines()-1,
                 &closePrice[0], 20, TA_MAType_SMA,
                 &outBegMMA20, &outNbElementMMA20, &outMMA20[0]);

    cout << "[OK]" << endl;
    //for(int i=0; i < outNbElementMMA20; i++ )
    //    printf( "Day %d = %f\n", outBegMMA20+i, outMMA20[i]);

    ///MMA50
    cout << "Calculating MMA50 ... ";
    TA_Real    outMMA50[csvparser.countLines()];
    TA_Integer outBegMMA50;
    TA_Integer outNbElementMMA50;

    retCode = TA_MA(0, csvparser.countLines()-1,
                 &closePrice[0], 50, TA_MAType_SMA,
                 &outBegMMA50, &outNbElementMMA50, &outMMA50[0]);

    cout << "[OK]" << endl;
    //for(int i=0; i < outNbElementMMA50; i++ )
    //    printf( "Day %d = %f\n", outBegMMA50+i, outMMA50[i]);

    ///MMA100
    cout << "Calculating MMA100 ... ";
    TA_Real    outMMA100[csvparser.countLines()];
    TA_Integer outBegMMA100;
    TA_Integer outNbElementMMA100;

    retCode = TA_MA(0, csvparser.countLines()-1,
                 &closePrice[0], 100, TA_MAType_SMA,
                 &outBegMMA100, &outNbElementMMA100, &outMMA100[0]);

    cout << "[OK]" << endl;
    //for(int i=0; i < outNbElementMMA100; i++ )
     //   printf( "Day %d = %f\n", outBegMMA100+i, outMMA100[i]);
    cout << endl;

    ///Stock prices related to MMAs
    if(closePrice[csvparser.countLines()-1] > outMMA10[outNbElementMMA10-1])
        cout << "Stock is above its MMA10" << endl;

    if(closePrice[csvparser.countLines()-1] > outMMA20[outNbElementMMA20-1])
        cout << "Stock is above its MMA20" << endl;

    if(closePrice[csvparser.countLines()-1] > outMMA50[outNbElementMMA50-1])
        cout << "Stock is above its MMA50" << endl;

    if(closePrice[csvparser.countLines()-1] > outMMA100[outNbElementMMA100-1])
        cout << "Stock is above its MMA100" << endl;

    cout << endl;

    ///MMAs related to others MMAs
    cout << "stock close = " << closePrice[csvparser.countLines()-1] << endl;
    cout << "MMA10 = " << outMMA10[outNbElementMMA10-1] << endl;
    cout << "MMA20 = " << outMMA20[outNbElementMMA20-1] << endl;
    cout << "MMA50 = " << outMMA50[outNbElementMMA50-1] << endl;
    cout << "MMA100 = " << outMMA100[outNbElementMMA100-1] << endl;

    cout << endl;
    ///MMA10
    if(outMMA10[outNbElementMMA10-1] > outMMA20[outNbElementMMA20-1])
        cout << "MMA10 is above MMA20" << endl;
    else
        cout << "MMA10 is below MMA20" << endl;

    if(outMMA10[outNbElementMMA10-1] > outMMA50[outNbElementMMA50-1])
        cout << "MMA10 is above MMA50" << endl;
    else
        cout << "MMA10 is below MMA50" << endl;

    if(outMMA10[outNbElementMMA10-1] > outMMA100[outNbElementMMA100-1])
        cout << "MMA10 is above MMA100" << endl;
    else
        cout << "MMA10 is below MMA100" << endl;

    cout << endl;

    ///MMA20
    if(outMMA20[outNbElementMMA20-1] > outMMA10[outNbElementMMA10-1])
        cout << "MMA20 is above MMA10" << endl;
    else
        cout << "MMA20 is below MMA10" << endl;

    if(outMMA20[outNbElementMMA20-1] > outMMA50[outNbElementMMA50-1])
        cout << "MMA20 is above MMA50" << endl;
    else
        cout << "MMA20 is below MMA50" << endl;

    if(outMMA20[outNbElementMMA20-1] > outMMA100[outNbElementMMA100-1])
        cout << "MMA20 is above MMA100" << endl;
    else
        cout << "MMA20 is below MMA100" << endl;

    cout << endl;

    ///MMA50
    if(outMMA50[outNbElementMMA50-1] > outMMA10[outNbElementMMA10-1])
        cout << "MMA50 is above MMA10" << endl;
    else
        cout << "MMA50 is below MMA10" << endl;

    if(outMMA50[outNbElementMMA50-1] > outMMA20[outNbElementMMA20-1])
        cout << "MMA50 is above MMA20" << endl;
    else
        cout << "MMA50 is below MMA20" << endl;

    if(outMMA50[outNbElementMMA50-1] > outMMA100[outNbElementMMA100-1])
        cout << "MMA50 is above MMA100" << endl;
    else
        cout << "MMA50 is below MMA100" << endl;


    ///TRIX 14
    TA_Real    outTRIX[csvparser.countLines()];
    TA_Integer outBegTRIX;
    TA_Integer outNbElementTRIX;

    retCode =  TA_TRIX(0,
                       csvparser.countLines()-1,
                       &closePrice[0],
                       14,
                       &outBegTRIX,
                       &outNbElementTRIX,
                       &outTRIX[0]);


    ///BOLLINGER 9
    TA_Real    outRealUpperBand9[csvparser.countLines()];
    TA_Real    outRealMiddleBand9[csvparser.countLines()];
    TA_Real    outRealLowerBand9[csvparser.countLines()];
    TA_Integer outBegBOLL9;
    TA_Integer outNbElementBOLL9;

    retCode =  TA_BBANDS(0,
                         csvparser.countLines()-1,
                         &closePrice[0],
                         9,
                         2,
                         2,
                         TA_MAType_SMA,
                         &outBegBOLL9,
                         &outNbElementBOLL9,
                         &outRealUpperBand9[0],
                         &outRealMiddleBand9[0],
                         &outRealLowerBand9[0]);

    cout << endl;
    cout << "stock close = " << closePrice[csvparser.countLines()-1] << endl;
    cout << "Boll+ : " << outRealUpperBand9[outNbElementBOLL9-1] << endl;
    cout << "Boll- : " << outRealLowerBand9[outNbElementBOLL9-1] << endl;
    cout << "Boll axis : " << outRealMiddleBand9[outNbElementBOLL9-1] << endl;

    cout << endl;
    // (a-b)/a < epsilon
    if(fabs(closePrice[csvparser.countLines()-1] - outRealUpperBand9[outNbElementBOLL9-1])
       < 0.1)
            cout << "stock price is near Boll+" << endl;

    if(fabs(closePrice[csvparser.countLines()-1] - outRealMiddleBand9[outNbElementBOLL9-1])
       < 0.1)
            cout << "stock price is near Boll axis" << endl;

    if(fabs(closePrice[csvparser.countLines()-1] - outRealLowerBand9[outNbElementBOLL9-1])
       < 0.1)
            cout << "stock price is near Boll-" << endl;


    //for(int i=outBegMMA10; i<outNbElementMMA10;i++)
        //cout << "MMA10 = " << outMMA10[i] << endl;

    //for(int i=outBegMMA20; i<outNbElementMMA20;i++)
        //cout << "MMA20 = " << outMMA20[i] << endl;

    ///Bollinger delta MMA
    TA_Real    outMMA5BollDelta[csvparser.countLines()];
    TA_Real    inputMMA5BollDelta[csvparser.countLines()];
    TA_Integer outBegMMA5BollDelta;
    TA_Integer outNbElementMMA5BollDelta;

    for(int i = outBegBOLL9; i < outNbElementBOLL9; i++) {
        inputMMA5BollDelta[i] = outRealUpperBand9[i] - outRealMiddleBand9[i];
    }

    retCode = TA_MA(outBegBOLL9,
                    outNbElementBOLL9-1,
                    &inputMMA5BollDelta[0],
                    5,
                    TA_MAType_SMA,
                    &outBegMMA5BollDelta,
                    &outNbElementMMA5BollDelta,
                    &outMMA5BollDelta[0]);


    for(int i = outBegMMA5BollDelta; i < outNbElementMMA5BollDelta; i++) {
        cout << "delta = " << outMMA5BollDelta[i] << endl;
    }

    double bollDeltamean = 0;
    for(int i = outBegMMA5BollDelta; i < outNbElementMMA5BollDelta; i++) {
        bollDeltamean += inputMMA5BollDelta[i];
    }

    bollDeltamean /= (outNbElementMMA5BollDelta-outBegMMA5BollDelta+1);

    cout << "mean = " << bollDeltamean << endl;

    if((inputMMA5BollDelta[outNbElementBOLL9-1]/bollDeltamean) <= 0.5)
        cout << "Boll delta is VERY low thus BBands are very tight" << endl;

    if(inputMMA5BollDelta[outNbElementBOLL9-1] < outMMA5BollDelta[outNbElementMMA5BollDelta-1])
        cout << "Boll delta is LOWER than MMA5 Boll delta" << endl;


    ///AROON Check -- do strategy
    Aroon aroon(csvparser, &highPrice[0], &lowPrice[0]);

    ///CANDLESTICK Check
    Candlestick candlestick(csvparser, &openPrice[0], &highPrice[0], &lowPrice[0], &closePrice[0]);

    return 0;
}
