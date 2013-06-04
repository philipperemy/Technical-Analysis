#include "../include/RunEntity.h"


#define SMA_SHORT 10
#define SMA_MID 20
#define SMA_LONG 50
#define SMA_VERY_LONG 100

using namespace std;

static const int OPEN = 0;
static const int HIGH = 1;
static const int LOW = 2;
static const int CLOSE = 3;
static const int VOLUME = 4;

RunEntity::RunEntity()
{
}

void RunEntity::run(CSVParser* csvparser)
{
	cout << "Running Technical Analysis Program" << endl;
	cout << "Filename is : " << csvparser->getFilename() << endl;

	array_size = csvparser->countLines();
	openPrice = new TA_Real[array_size];
	highPrice = new TA_Real[array_size];
    lowPrice = new TA_Real[array_size];
    closePrice = new TA_Real[array_size];
    volumePrice = new TA_Real[array_size];

	for(int i=0; i<array_size; i++) {
        openPrice[i] = csvparser->getValue(i, OPEN);
        highPrice[i] = csvparser->getValue(i, HIGH);
        lowPrice[i] = csvparser->getValue(i, LOW);
        closePrice[i] = csvparser->getValue(i, CLOSE);
        volumePrice[i] = csvparser->getValue(i, VOLUME);
    }

	check_sma(SMA_SHORT, SMA_MID);
	check_sma(SMA_SHORT, SMA_LONG);
	check_sma(SMA_SHORT, SMA_VERY_LONG);

	check_sma(SMA_MID, SMA_LONG);
	check_sma(SMA_MID, SMA_VERY_LONG);

}

void RunEntity::check_sma(int sma_period_1, int sma_period_2)
{
	stringstream s;
	s << sma_period_1;
	string sma1 = "SMA" + s.str();

	s.str("");
	s << sma_period_2;
	string sma2 = "SMA" + s.str();

	cout << "Calculating " << sma1 << " ... ";
    TA_Real* outSMA_1 = new TA_Real[array_size];
    TA_Integer outBegSMA_1;
    TA_Integer outNbElementSMA_1;

    TA_RetCode retCode = TA_MA(0, array_size-1,
                 &closePrice[0], 10, TA_MAType_SMA,
                 &outBegSMA_1, &outNbElementSMA_1, &outSMA_1[0]);

    cout << "[OK]" << endl;
    /*for(int i=0; i < outNbElementSMA10; i++ )
        cout << "Day " << outBegSMA10+i << " = " << outSMA10[i] << endl;*/

    cout << "Calculating " << sma2 << " ... ";
    TA_Real* outSMA_2 = new TA_Real[array_size];
    TA_Integer outBegSMA_2;
    TA_Integer outNbElementSMA_2;

    retCode = TA_MA(0, array_size-1,
                 &closePrice[0], 20, TA_MAType_SMA,
                 &outBegSMA_2, &outNbElementSMA_2, &outSMA_2[0]);

    cout << "[OK]" << endl;
    //for(int i=0; i < outNbElementSMA20; i++ )
    //    cout << "Day " << outBegSMA20+i << " = " << outSMA20[i] << endl;*/

	cout << "stock close = " << closePrice[array_size-1] << endl;
	cout << sma1 << " = " << outSMA_1[outNbElementSMA_1-1] << endl;
	cout << sma2 << " = " << outSMA_1[outNbElementSMA_2-1] << endl;

    if(outSMA_1[outNbElementSMA_1-1] > outSMA_2[outNbElementSMA_2-1])
        cout << sma1 << " is above " << sma2 << endl;
    else
        cout << sma2 << " is above " << sma1 << endl;
}

RunEntity::~RunEntity()
{
}