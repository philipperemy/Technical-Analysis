#include "../include/Candlestick.h"
#include "../ta-lib/c/include/ta_libc.h"
#include "../include/CSVParser.h"



Candlestick::Candlestick(CSVParser& csvparser, double openPrice[], double highPrice[]
                         , double lowPrice[], double closePrice[])
{
    cout << "CHECKING CANDLESTICKS PATTERNS" << endl;

     /// -- Engulfing Pattern --
    TA_Integer      outEngulfingPattern[csvparser.countLines()];
    TA_Integer      outBegEngulfingPattern;
    TA_Integer      outNbElementEngulfingPattern;
    TA_RetCode      retCode;

    retCode = TA_CDLENGULFING(0,
                              csvparser.countLines()-1,
                              &openPrice[0],
                              &highPrice[0],
                              &lowPrice[0],
                              &closePrice[0],
                              &outBegEngulfingPattern,
                              &outNbElementEngulfingPattern,
                              &outEngulfingPattern[0]);
    /*
    for(int i=outBegEngulfingPattern; i<outNbElementEngulfingPattern; i++) {
        cout << "close = " << closePrice[i] << endl;
        cout << "day " << i << " engulfing = " << outEngulfingPattern[i] << endl;
    }*/

    if(outEngulfingPattern[outNbElementEngulfingPattern-1] == -100)
        cout << "NEGATIVE - Engulfing Pattern - get prepared to sell!" << endl;

    else if(outEngulfingPattern[outNbElementEngulfingPattern-1] == 100)
        cout << "POSITIVE - Engulfing Pattern - get prepared to buy!" << endl;

    ///HARAMI PATTERN
    TA_Integer     outHaramiPattern[csvparser.countLines()];
    TA_Integer     outBegHaramiPattern;
    TA_Integer     outNbElementHaramiPattern;

    retCode =    TA_CDLHARAMI(0,
                              csvparser.countLines()-1,
                              &openPrice[0],
                              &highPrice[0],
                              &lowPrice[0],
                              &closePrice[0],
                              &outBegHaramiPattern,
                              &outNbElementHaramiPattern,
                              &outHaramiPattern[0]);

    ///!NOT SURE!
    if(outHaramiPattern[outNbElementHaramiPattern-1] == -100)
        cout << "NEGATIVE - Harami Pattern - get prepared to sell!" << endl;

    else if(outHaramiPattern[outNbElementHaramiPattern-1] == 100)
        cout << "POSITIVE - Harami Pattern - get prepared to buy!" << endl;

    ///HARAMI CROSS PATTERN
    TA_Integer     outHaramiCrossPattern[csvparser.countLines()];
    TA_Integer     outBegHaramiCrossPattern;
    TA_Integer     outNbElementHaramiCrossPattern;

    retCode=TA_CDLHARAMICROSS(0,
                              csvparser.countLines()-1,
                              &openPrice[0],
                              &highPrice[0],
                              &lowPrice[0],
                              &closePrice[0],
                              &outBegHaramiCrossPattern,
                              &outNbElementHaramiCrossPattern,
                              &outHaramiCrossPattern[0]);

    if(outHaramiCrossPattern[outNbElementHaramiCrossPattern-1] == -100)
        cout << "NEGATIVE - Harami Cross Pattern - get prepared to sell!" << endl;

    else if(outHaramiCrossPattern[outNbElementHaramiCrossPattern-1] == 100)
        cout << "POSITIVE - Harami Cross Pattern - get prepared to buy!" << endl;

    /*for(int i=outBegHaramiCrossPattern; i<outNbElementHaramiCrossPattern-1; i++) {
        cout << "close = " << closePrice[i] << " ";
        cout << "day " << i << " harami = " << outHaramiCrossPattern[i] << endl;
    }*/

    ///HIKKAKE PATTERN
    TA_Integer     outHikkakePattern[csvparser.countLines()];
    TA_Integer     outBegHikkakePattern;
    TA_Integer     outNbElementHikkakePattern;

    retCode = TA_CDLHIKKAKE(0,
                            csvparser.countLines()-1,
                            &openPrice[0],
                            &highPrice[0],
                            &lowPrice[0],
                            &closePrice[0],
                            &outBegHikkakePattern,
                            &outNbElementHikkakePattern,
                            &outHikkakePattern[0]);

    if(outHikkakePattern[outNbElementHikkakePattern-1] == -200)
        cout << "NEGATIVE (-200) - Hikkake Pattern - get prepared to sell!" << endl;

    if(outHikkakePattern[outNbElementHikkakePattern-1] == -100)
        cout << "NEGATIVE (-100) - Hikkake Pattern - get prepared to sell!" << endl;

    if(outHikkakePattern[outNbElementHikkakePattern-1] == 100)
        cout << "POSITIVE (100) - Hikkake Pattern - get prepared to buy!" << endl;

    if(outHikkakePattern[outNbElementHikkakePattern-1] == 200)
        cout << "POSITIVE (200) - Hikkake Pattern - get prepared to buy!" << endl;

    ///HIKKAKE MODIFIED - NOT CHECKED
    TA_Integer     outHikkakeModPattern[csvparser.countLines()];
    TA_Integer     outBegHikkakeModPattern;
    TA_Integer     outNbElementHikkakeModPattern;

    retCode = TA_CDLHIKKAKEMOD (0,
                                csvparser.countLines()-1,
                                &openPrice[0],
                                &highPrice[0],
                                &lowPrice[0],
                                &closePrice[0],
                                &outBegHikkakeModPattern,
                                &outNbElementHikkakeModPattern,
                                &outHikkakeModPattern[0]);

    if(outHikkakeModPattern[outNbElementHikkakeModPattern-1] == -200)
        cout << "NEGATIVE (-200) - HikkakeMod Pattern - get prepared to sell!" << endl;

    if(outHikkakeModPattern[outNbElementHikkakeModPattern-1] == -100)
        cout << "NEGATIVE (-100) - HikkakeMod Pattern - get prepared to sell!" << endl;

    if(outHikkakeModPattern[outNbElementHikkakeModPattern-1] == 100)
        cout << "POSITIVE (100) - HikkakeMod Pattern - get prepared to buy!" << endl;

    if(outHikkakeModPattern[outNbElementHikkakeModPattern-1] == 200)
        cout << "POSITIVE (200) - HikkakeMod Pattern - get prepared to buy!" << endl;

    /// IN-NECK PATTERN - NOT CHECKED
    TA_Integer     outInNeckPattern[csvparser.countLines()];
    TA_Integer     outBegInNeckPattern;
    TA_Integer     outNbElementInNeckPattern;

    retCode = TA_CDLINNECK     (0,
                                csvparser.countLines()-1,
                                &openPrice[0],
                                &highPrice[0],
                                &lowPrice[0],
                                &closePrice[0],
                                &outBegInNeckPattern,
                                &outNbElementInNeckPattern,
                                &outInNeckPattern[0]);

    /// ON-NECK PATTERN - NOT CHECKED
    TA_Integer     outOnNeckPattern[csvparser.countLines()];
    TA_Integer     outBegOnNeckPattern;
    TA_Integer     outNbElementOnNeckPattern;

    retCode = TA_CDLONNECK     (0,
                                csvparser.countLines()-1,
                                &openPrice[0],
                                &highPrice[0],
                                &lowPrice[0],
                                &closePrice[0],
                                &outBegOnNeckPattern,
                                &outNbElementOnNeckPattern,
                                &outOnNeckPattern[0]);

    /// PIERCING PATTERN - NOT CHECKED
    TA_Integer     outPiercingPattern[csvparser.countLines()];
    TA_Integer     outBegPiercingPattern;
    TA_Integer     outNbElementPiercingPattern;

    retCode = TA_CDLPIERCING   (0,
                                csvparser.countLines()-1,
                                &openPrice[0],
                                &highPrice[0],
                                &lowPrice[0],
                                &closePrice[0],
                                &outBegPiercingPattern,
                                &outNbElementPiercingPattern,
                                &outPiercingPattern[0]);

    /// STALLED PATTERN - NOT CHECKED
    TA_Integer     outStalledPattern[csvparser.countLines()];
    TA_Integer     outBegStalledPattern;
    TA_Integer     outNbElementStalledPattern;

    retCode = TA_CDLSTALLEDPATTERN(0,
                                csvparser.countLines()-1,
                                &openPrice[0],
                                &highPrice[0],
                                &lowPrice[0],
                                &closePrice[0],
                                &outBegStalledPattern,
                                &outNbElementStalledPattern,
                                &outStalledPattern[0]);


    /// THRUSTING PATTERN - NOT CHECKED
    TA_Integer     outThrustingPattern[csvparser.countLines()];
    TA_Integer     outBegThrustingPattern;
    TA_Integer     outNbElementThrustingPattern;

    retCode = TA_CDLTHRUSTING  (0,
                                csvparser.countLines()-1,
                                &openPrice[0],
                                &highPrice[0],
                                &lowPrice[0],
                                &closePrice[0],
                                &outBegThrustingPattern,
                                &outNbElementThrustingPattern,
                                &outThrustingPattern[0]);

    /// TRISTAR PATTERN - NOT CHECKED
    TA_Integer     outTristarPattern[csvparser.countLines()];
    TA_Integer     outBegTristarPattern;
    TA_Integer     outNbElementTristarPattern;

    retCode = TA_CDLTRISTAR    (0,
                                csvparser.countLines()-1,
                                &openPrice[0],
                                &highPrice[0],
                                &lowPrice[0],
                                &closePrice[0],
                                &outBegTristarPattern,
                                &outNbElementTristarPattern,
                                &outTristarPattern[0]);


    /// HAS NOT BEEN CHECKED!
    ///
    ///
    ///
    ///
    ///
    /// CANDLESTICKS - NOT PATTERNS - ALL OTHERS
    ///
    ///
    ///
    ///
    ///
    ///CDL2CROWS           Two Crows
    TA_Integer      out2Crows[csvparser.countLines()];
    TA_Integer      outBeg2Crows;
    TA_Integer      outNbElement2Crows;

    retCode = TA_CDL2CROWS(0,
                         csvparser.countLines()-1,
                         &openPrice[0],
                         &highPrice[0],
                         &lowPrice[0],
                         &closePrice[0],
                         &outBeg2Crows,
                         &outNbElement2Crows,
                         &out2Crows[0] );

    if(out2Crows[outNbElement2Crows-1] >= 100)
        cout << "POSITIVE - 2Crows - get prepared to buy!" << endl;

    if(out2Crows[outNbElement2Crows-1] <= -100)
        cout << "NEGATIVE - 2Crows - get prepared to sell!" << endl;

    ///CDL3BLACKCROWS      Three Black Crows

    TA_Integer      out3BLACKCROWS[csvparser.countLines()];
    TA_Integer      outBeg3BLACKCROWS;
    TA_Integer      outNbElement3BLACKCROWS;

    retCode = TA_CDL3BLACKCROWS(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBeg3BLACKCROWS,
                           &outNbElement3BLACKCROWS,
                           &out3BLACKCROWS[0] );

    if(out3BLACKCROWS[outNbElement3BLACKCROWS-1] >= 100)
        cout << "POSITIVE - 3BLACKCROWS - get prepared to buy!" << endl;

    if(out3BLACKCROWS[outNbElement3BLACKCROWS-1] <= -100)
        cout << "NEGATIVE - 3BLACKCROWS - get prepared to sell!" << endl;

    ///CDL3INSIDE          Three Inside Up/Down

    TA_Integer      out3INSIDE[csvparser.countLines()];
    TA_Integer      outBeg3INSIDE;
    TA_Integer      outNbElement3INSIDE;

    retCode = TA_CDL3INSIDE(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBeg3INSIDE,
                           &outNbElement3INSIDE,
                           &out3INSIDE[0] );

    if(out3INSIDE[outNbElement3INSIDE-1] >= 100)
        cout << "POSITIVE - 3INSIDE - get prepared to buy!" << endl;

    if(out3INSIDE[outNbElement3INSIDE-1] <= -100)
        cout << "NEGATIVE - 3INSIDE - get prepared to sell!" << endl;

    ///CDL3LINESTRIKE      Three-Line Strike

    TA_Integer      out3LINESTRIKE[csvparser.countLines()];
    TA_Integer      outBeg3LINESTRIKE;
    TA_Integer      outNbElement3LINESTRIKE;

    retCode = TA_CDL3LINESTRIKE(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBeg3LINESTRIKE,
                           &outNbElement3LINESTRIKE,
                           &out3LINESTRIKE[0] );

    if(out3LINESTRIKE[outNbElement3LINESTRIKE-1] >= 100)
        cout << "POSITIVE - 3LINESTRIKE - get prepared to buy!" << endl;

    if(out3LINESTRIKE[outNbElement3LINESTRIKE-1] <= -100)
        cout << "NEGATIVE - 3LINESTRIKE - get prepared to sell!" << endl;

    ///CDL3OUTSIDE         Three Outside Up/Down

    TA_Integer      out3OUTSIDE[csvparser.countLines()];
    TA_Integer      outBeg3OUTSIDE;
    TA_Integer      outNbElement3OUTSIDE;

    retCode = TA_CDL3OUTSIDE(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBeg3OUTSIDE,
                           &outNbElement3OUTSIDE,
                           &out3OUTSIDE[0] );

    if(out3OUTSIDE[outNbElement3OUTSIDE-1] >= 100)
        cout << "POSITIVE - 3OUTSIDE - get prepared to buy!" << endl;

    if(out3OUTSIDE[outNbElement3OUTSIDE-1] <= -100)
        cout << "NEGATIVE - 3OUTSIDE - get prepared to sell!" << endl;

    ///CDL3STARSINSOUTH    Three Stars In The South

    TA_Integer      out3STARSINSOUTH[csvparser.countLines()];
    TA_Integer      outBeg3STARSINSOUTH;
    TA_Integer      outNbElement3STARSINSOUTH;

    retCode = TA_CDL3STARSINSOUTH(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBeg3STARSINSOUTH,
                           &outNbElement3STARSINSOUTH,
                           &out3STARSINSOUTH[0] );

    if(out3STARSINSOUTH[outNbElement3STARSINSOUTH-1] >= 100)
        cout << "POSITIVE - 3STARSINSOUTH - get prepared to buy!" << endl;

    if(out3STARSINSOUTH[outNbElement3STARSINSOUTH-1] <= -100)
        cout << "NEGATIVE - 3STARSINSOUTH - get prepared to sell!" << endl;

    ///CDL3WHITESOLDIERS   Three Advancing White Soldiers

    TA_Integer      out3WHITESOLDIERS[csvparser.countLines()];
    TA_Integer      outBeg3WHITESOLDIERS;
    TA_Integer      outNbElement3WHITESOLDIERS;

    retCode = TA_CDL3WHITESOLDIERS(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBeg3WHITESOLDIERS,
                           &outNbElement3WHITESOLDIERS,
                           &out3WHITESOLDIERS[0] );

    if(out3WHITESOLDIERS[outNbElement3WHITESOLDIERS-1] >= 100)
        cout << "POSITIVE - 3WHITESOLDIERS - get prepared to buy!" << endl;

    if(out3WHITESOLDIERS[outNbElement3WHITESOLDIERS-1] <= -100)
        cout << "NEGATIVE - 3WHITESOLDIERS - get prepared to sell!" << endl;

    ///CDLABANDONEDBABY    Abandoned Baby

    TA_Integer      outABANDONEDBABY[csvparser.countLines()];
    TA_Integer      outBegABANDONEDBABY;
    TA_Integer      outNbElementABANDONEDBABY;

    retCode = TA_CDLABANDONEDBABY(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           0.3,
                           &outBegABANDONEDBABY,
                           &outNbElementABANDONEDBABY,
                           &outABANDONEDBABY[0] );

    if(outABANDONEDBABY[outNbElementABANDONEDBABY-1] >= 100)
        cout << "POSITIVE - ABANDONEDBABY - get prepared to buy!" << endl;

    if(outABANDONEDBABY[outNbElementABANDONEDBABY-1] <= -100)
        cout << "NEGATIVE - ABANDONEDBABY - get prepared to sell!" << endl;

    ///CDLADVANCEBLOCK     Advance Block

    TA_Integer      outADVANCEBLOCK[csvparser.countLines()];
    TA_Integer      outBegADVANCEBLOCK;
    TA_Integer      outNbElementADVANCEBLOCK;

    retCode = TA_CDLADVANCEBLOCK(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegADVANCEBLOCK,
                           &outNbElementADVANCEBLOCK,
                           &outADVANCEBLOCK[0] );

    if(outADVANCEBLOCK[outNbElementADVANCEBLOCK-1] >= 100)
        cout << "POSITIVE - ADVANCEBLOCK - get prepared to buy!" << endl;

    if(outADVANCEBLOCK[outNbElementADVANCEBLOCK-1] <= -100)
        cout << "NEGATIVE - ADVANCEBLOCK - get prepared to sell!" << endl;

    ///CDLBELTHOLD         Belt-hold
    TA_Integer      outBELTHOLD[csvparser.countLines()];
    TA_Integer      outBegBELTHOLD;
    TA_Integer      outNbElementBELTHOLD;

    retCode = TA_CDLBELTHOLD(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegBELTHOLD,
                           &outNbElementBELTHOLD,
                           &outBELTHOLD[0] );

    if(outBELTHOLD[outNbElementBELTHOLD-1] >= 100)
        cout << "POSITIVE - BELTHOLD - get prepared to buy!" << endl;

    if(outBELTHOLD[outNbElementBELTHOLD-1] <= -100)
        cout << "NEGATIVE - BELTHOLD - get prepared to sell!" << endl;

    ///CDLBREAKAWAY        Breakaway
    TA_Integer      outBREAKAWAY[csvparser.countLines()];
    TA_Integer      outBegBREAKAWAY;
    TA_Integer      outNbElementBREAKAWAY;

    retCode = TA_CDLBELTHOLD(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegBREAKAWAY,
                           &outNbElementBREAKAWAY,
                           &outBREAKAWAY[0] );

    if(outBREAKAWAY[outNbElementBREAKAWAY-1] >= 100)
        cout << "POSITIVE - BREAKAWAY - get prepared to buy!" << endl;

    if(outBREAKAWAY[outNbElementBREAKAWAY-1] <= -100)
        cout << "NEGATIVE - BREAKAWAY - get prepared to sell!" << endl;

    ///CDLCLOSINGMARUBOZU  Closing Marubozu
    TA_Integer      outCLOSINGMARUBOZU[csvparser.countLines()];
    TA_Integer      outBegCLOSINGMARUBOZU;
    TA_Integer      outNbElementCLOSINGMARUBOZU;

    retCode = TA_CDLCLOSINGMARUBOZU(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegCLOSINGMARUBOZU,
                           &outNbElementCLOSINGMARUBOZU,
                           &outCLOSINGMARUBOZU[0] );

    if(outCLOSINGMARUBOZU[outNbElementCLOSINGMARUBOZU-1] >= 100)
        cout << "POSITIVE - CLOSINGMARUBOZU - get prepared to buy!" << endl;

    if(outCLOSINGMARUBOZU[outNbElementCLOSINGMARUBOZU-1] <= -100)
        cout << "NEGATIVE - CLOSINGMARUBOZU - get prepared to sell!" << endl;

    ///CDLCONCEALBABYSWALL Concealing Baby Swallow
    TA_Integer      outCONCEALBABYSWALL[csvparser.countLines()];
    TA_Integer      outBegCONCEALBABYSWALL;
    TA_Integer      outNbElementCONCEALBABYSWALL;

    retCode = TA_CDLCONCEALBABYSWALL(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegCONCEALBABYSWALL,
                           &outNbElementCONCEALBABYSWALL,
                           &outCONCEALBABYSWALL[0] );

    if(outCONCEALBABYSWALL[outNbElementCONCEALBABYSWALL-1] >= 100)
        cout << "POSITIVE - CONCEALBABYSWALL - get prepared to buy!" << endl;

    if(outCONCEALBABYSWALL[outNbElementCONCEALBABYSWALL-1] <= -100)
        cout << "NEGATIVE - CONCEALBABYSWALL - get prepared to sell!" << endl;

    ///CDLCOUNTERATTACK    Counterattack
    TA_Integer      outCOUNTERATTACK[csvparser.countLines()];
    TA_Integer      outBegCOUNTERATTACK;
    TA_Integer      outNbElementCOUNTERATTACK;

    retCode = TA_CDLCOUNTERATTACK(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegCOUNTERATTACK,
                           &outNbElementCOUNTERATTACK,
                           &outCOUNTERATTACK[0] );

    if(outCOUNTERATTACK[outNbElementCOUNTERATTACK-1] >= 100)
        cout << "POSITIVE - COUNTERATTACK - get prepared to buy!" << endl;

    if(outCOUNTERATTACK[outNbElementCOUNTERATTACK-1] <= -100)
        cout << "NEGATIVE - COUNTERATTACK - get prepared to sell!" << endl;

    ///CDLDARKCLOUDCOVER   Dark Cloud Cover
    TA_Integer      outDARKCLOUDCOVER[csvparser.countLines()];
    TA_Integer      outBegDARKCLOUDCOVER;
    TA_Integer      outNbElementDARKCLOUDCOVER;

    retCode = TA_CDLDARKCLOUDCOVER(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           0.5,
                           &outBegDARKCLOUDCOVER,
                           &outNbElementDARKCLOUDCOVER,
                           &outDARKCLOUDCOVER[0] );

    if(outDARKCLOUDCOVER[outNbElementDARKCLOUDCOVER-1] >= 100)
        cout << "POSITIVE - DARKCLOUDCOVER - get prepared to buy!" << endl;

    if(outDARKCLOUDCOVER[outNbElementDARKCLOUDCOVER-1] <= -100)
        cout << "NEGATIVE - DARKCLOUDCOVER - get prepared to sell!" << endl;

    ///CDLDOJI             Doji
    TA_Integer      outDOJI[csvparser.countLines()];
    TA_Integer      outBegDOJI;
    TA_Integer      outNbElementDOJI;

    retCode = TA_CDLDOJI(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegDOJI,
                           &outNbElementDOJI,
                           &outDOJI[0] );

    if(outDOJI[outNbElementDOJI-1] >= 100)
        cout << "POSITIVE - DOJI - get prepared to buy!" << endl;

    if(outDOJI[outNbElementDOJI-1] <= -100)
        cout << "NEGATIVE - DOJI - get prepared to sell!" << endl;

    ///CDLDOJISTAR         Doji Star
    TA_Integer      outDOJISTAR[csvparser.countLines()];
    TA_Integer      outBegDOJISTAR;
    TA_Integer      outNbElementDOJISTAR;

    retCode = TA_CDLDOJISTAR(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegDOJISTAR,
                           &outNbElementDOJISTAR,
                           &outDOJISTAR[0] );

    if(outDOJISTAR[outNbElementDOJISTAR-1] >= 100)
        cout << "POSITIVE - DOJISTAR - get prepared to buy!" << endl;

    if(outDOJISTAR[outNbElementDOJISTAR-1] <= -100)
        cout << "NEGATIVE - DOJISTAR - get prepared to sell!" << endl;

    ///CDLDRAGONFLYDOJI    Dragonfly Doji
    TA_Integer      outDRAGONFLYDOJI[csvparser.countLines()];
    TA_Integer      outBegDRAGONFLYDOJI;
    TA_Integer      outNbElementDRAGONFLYDOJI;

    retCode = TA_CDLDRAGONFLYDOJI(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegDRAGONFLYDOJI,
                           &outNbElementDRAGONFLYDOJI,
                           &outDRAGONFLYDOJI[0] );

    if(outDRAGONFLYDOJI[outNbElementDRAGONFLYDOJI-1] >= 100)
        cout << "POSITIVE - DRAGONFLYDOJI - get prepared to buy!" << endl;

    if(outDRAGONFLYDOJI[outNbElementDRAGONFLYDOJI-1] <= -100)
        cout << "NEGATIVE - DRAGONFLYDOJI - get prepared to sell!" << endl;

    ///CDLEVENINGDOJISTAR  Evening Doji Star
    TA_Integer      outEVENINGDOJISTAR[csvparser.countLines()];
    TA_Integer      outBegEVENINGDOJISTAR;
    TA_Integer      outNbElementEVENINGDOJISTAR;

    retCode = TA_CDLEVENINGDOJISTAR(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           0.3,
                           &outBegEVENINGDOJISTAR,
                           &outNbElementEVENINGDOJISTAR,
                           &outEVENINGDOJISTAR[0] );

    if(outEVENINGDOJISTAR[outNbElementEVENINGDOJISTAR-1] >= 100)
        cout << "POSITIVE - EVENINGDOJISTAR - get prepared to buy!" << endl;

    if(outEVENINGDOJISTAR[outNbElementEVENINGDOJISTAR-1] <= -100)
        cout << "NEGATIVE - EVENINGDOJISTAR - get prepared to sell!" << endl;

    ///CDLEVENINGSTAR      Evening Star
    TA_Integer      outEVENINGSTAR[csvparser.countLines()];
    TA_Integer      outBegEVENINGSTAR;
    TA_Integer      outNbElementEVENINGSTAR;

    retCode = TA_CDLEVENINGSTAR(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           0.3,
                           &outBegEVENINGSTAR,
                           &outNbElementEVENINGSTAR,
                           &outEVENINGSTAR[0] );

    if(outEVENINGSTAR[outNbElementEVENINGSTAR-1] >= 100)
        cout << "POSITIVE - EVENINGSTAR - get prepared to buy!" << endl;

    if(outEVENINGSTAR[outNbElementEVENINGSTAR-1] <= -100)
        cout << "NEGATIVE - EVENINGSTAR - get prepared to sell!" << endl;

    ///CDLGAPSIDESIDEWHITE Up/Down-gap side-by-side white lines
    TA_Integer      outGAPSIDESIDEWHITE[csvparser.countLines()];
    TA_Integer      outBegGAPSIDESIDEWHITE;
    TA_Integer      outNbElementGAPSIDESIDEWHITE;

    retCode = TA_CDLGAPSIDESIDEWHITE(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegGAPSIDESIDEWHITE,
                           &outNbElementGAPSIDESIDEWHITE,
                           &outGAPSIDESIDEWHITE[0] );

    if(outGAPSIDESIDEWHITE[outNbElementGAPSIDESIDEWHITE-1] >= 100)
        cout << "POSITIVE - GAPSIDESIDEWHITE - get prepared to buy!" << endl;

    if(outGAPSIDESIDEWHITE[outNbElementGAPSIDESIDEWHITE-1] <= -100)
        cout << "NEGATIVE - GAPSIDESIDEWHITE - get prepared to sell!" << endl;

    ///CDLGRAVESTONEDOJI   Gravestone Doji
    TA_Integer      outGRAVESTONEDOJI[csvparser.countLines()];
    TA_Integer      outBegGRAVESTONEDOJI;
    TA_Integer      outNbElementGRAVESTONEDOJI;

    retCode = TA_CDLGRAVESTONEDOJI(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegGRAVESTONEDOJI,
                           &outNbElementGRAVESTONEDOJI,
                           &outGRAVESTONEDOJI[0] );

    if(outGRAVESTONEDOJI[outNbElementGRAVESTONEDOJI-1] >= 100)
        cout << "POSITIVE - GRAVESTONEDOJI - get prepared to buy!" << endl;

    if(outGRAVESTONEDOJI[outNbElementGRAVESTONEDOJI-1] <= -100)
        cout << "NEGATIVE - GRAVESTONEDOJI - get prepared to sell!" << endl;

    ///CDLHAMMER           Hammer
    TA_Integer      outHAMMER[csvparser.countLines()];
    TA_Integer      outBegHAMMER;
    TA_Integer      outNbElementHAMMER;

    retCode = TA_CDLHAMMER(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegHAMMER,
                           &outNbElementHAMMER,
                           &outHAMMER[0] );

    if(outHAMMER[outNbElementHAMMER-1] >= 100)
        cout << "POSITIVE - HAMMER - get prepared to buy!" << endl;

    if(outHAMMER[outNbElementHAMMER-1] <= -100)
        cout << "NEGATIVE - HAMMER - get prepared to sell!" << endl;

    ///CDLHANGINGMAN       Hanging Man
    TA_Integer      outHANGINGMAN[csvparser.countLines()];
    TA_Integer      outBegHANGINGMAN;
    TA_Integer      outNbElementHANGINGMAN;

    retCode = TA_CDLHANGINGMAN(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegHANGINGMAN,
                           &outNbElementHANGINGMAN,
                           &outHANGINGMAN[0] );

    if(outHANGINGMAN[outNbElementHANGINGMAN-1] >= 100)
        cout << "POSITIVE - HANGINGMAN - get prepared to buy!" << endl;

    if(outHANGINGMAN[outNbElementHANGINGMAN-1] <= -100)
        cout << "NEGATIVE - HANGINGMAN - get prepared to sell!" << endl;

    ///CDLHIGHWAVE         High-Wave Candle
    TA_Integer      outHIGHWAVE[csvparser.countLines()];
    TA_Integer      outBegHIGHWAVE;
    TA_Integer      outNbElementHIGHWAVE;

    retCode = TA_CDLHIGHWAVE(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegHIGHWAVE,
                           &outNbElementHIGHWAVE,
                           &outHIGHWAVE[0] );

    if(outHIGHWAVE[outNbElementHIGHWAVE-1] >= 100)
        cout << "POSITIVE - HIGHWAVE - get prepared to buy!" << endl;

    if(outHIGHWAVE[outNbElementHIGHWAVE-1] <= -100)
        cout << "NEGATIVE - HIGHWAVE - get prepared to sell!" << endl;

    ///CDLHOMINGPIGEON     Homing Pigeon
    TA_Integer      outHOMINGPIGEON[csvparser.countLines()];
    TA_Integer      outBegHOMINGPIGEON;
    TA_Integer      outNbElementHOMINGPIGEON;

    retCode = TA_CDLHOMINGPIGEON(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegHOMINGPIGEON,
                           &outNbElementHOMINGPIGEON,
                           &outHOMINGPIGEON[0] );

    if(outHOMINGPIGEON[outNbElementHOMINGPIGEON-1] >= 100)
        cout << "POSITIVE - HOMINGPIGEON - get prepared to buy!" << endl;

    if(outHOMINGPIGEON[outNbElementHOMINGPIGEON-1] <= -100)
        cout << "NEGATIVE - HOMINGPIGEON - get prepared to sell!" << endl;

    ///CDLIDENTICAL3CROWS  Identical Three Crows
    TA_Integer      outIDENTICAL3CROWS[csvparser.countLines()];
    TA_Integer      outBegIDENTICAL3CROWS;
    TA_Integer      outNbElementIDENTICAL3CROWS;

    retCode = TA_CDLIDENTICAL3CROWS(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegIDENTICAL3CROWS,
                           &outNbElementIDENTICAL3CROWS,
                           &outIDENTICAL3CROWS[0] );

    if(outIDENTICAL3CROWS[outNbElementIDENTICAL3CROWS-1] >= 100)
        cout << "POSITIVE - IDENTICAL3CROWS - get prepared to buy!" << endl;

    if(outIDENTICAL3CROWS[outNbElementIDENTICAL3CROWS-1] <= -100)
        cout << "NEGATIVE - IDENTICAL3CROWS - get prepared to sell!" << endl;

    ///CDLINVERTEDHAMMER   Inverted Hammer
    TA_Integer      outINVERTEDHAMMER[csvparser.countLines()];
    TA_Integer      outBegINVERTEDHAMMER;
    TA_Integer      outNbElementINVERTEDHAMMER;

    retCode = TA_CDLINVERTEDHAMMER(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegINVERTEDHAMMER,
                           &outNbElementINVERTEDHAMMER,
                           &outINVERTEDHAMMER[0] );

    if(outINVERTEDHAMMER[outNbElementINVERTEDHAMMER-1] >= 100)
        cout << "POSITIVE - INVERTEDHAMMER - get prepared to buy!" << endl;

    if(outINVERTEDHAMMER[outNbElementINVERTEDHAMMER-1] <= -100)
        cout << "NEGATIVE - INVERTEDHAMMER - get prepared to sell!" << endl;

    ///CDLKICKING          Kicking
    TA_Integer      outKICKING[csvparser.countLines()];
    TA_Integer      outBegKICKING;
    TA_Integer      outNbElementKICKING;

    retCode = TA_CDLKICKING(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegKICKING,
                           &outNbElementKICKING,
                           &outKICKING[0] );

    if(outKICKING[outNbElementKICKING-1] >= 100)
        cout << "POSITIVE - KICKING - get prepared to buy!" << endl;

    if(outKICKING[outNbElementKICKING-1] <= -100)
        cout << "NEGATIVE - KICKING - get prepared to sell!" << endl;

    ///CDLKICKINGBYLENGTH  Kicking - bull/bear determined by the longer marubozu
    TA_Integer      outKICKINGBYLENGTH[csvparser.countLines()];
    TA_Integer      outBegKICKINGBYLENGTH;
    TA_Integer      outNbElementKICKINGBYLENGTH;

    retCode = TA_CDLKICKINGBYLENGTH(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegKICKINGBYLENGTH,
                           &outNbElementKICKINGBYLENGTH,
                           &outKICKINGBYLENGTH[0] );

    if(outKICKINGBYLENGTH[outNbElementKICKINGBYLENGTH-1] >= 100)
        cout << "POSITIVE - KICKINGBYLENGTH - get prepared to buy!" << endl;

    if(outKICKINGBYLENGTH[outNbElementKICKINGBYLENGTH-1] <= -100)
        cout << "NEGATIVE - KICKINGBYLENGTH - get prepared to sell!" << endl;

    ///CDLLADDERBOTTOM     Ladder Bottom
    TA_Integer      outLADDERBOTTOM[csvparser.countLines()];
    TA_Integer      outBegLADDERBOTTOM;
    TA_Integer      outNbElementLADDERBOTTOM;

    retCode = TA_CDLLADDERBOTTOM(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegLADDERBOTTOM,
                           &outNbElementLADDERBOTTOM,
                           &outLADDERBOTTOM[0] );

    if(outLADDERBOTTOM[outNbElementLADDERBOTTOM-1] >= 100)
        cout << "POSITIVE - LADDERBOTTOM - get prepared to buy!" << endl;

    if(outLADDERBOTTOM[outNbElementLADDERBOTTOM-1] <= -100)
        cout << "NEGATIVE - LADDERBOTTOM - get prepared to sell!" << endl;

    ///CDLLONGLEGGEDDOJI   Long Legged Doji
    TA_Integer      outLONGLEGGEDDOJI[csvparser.countLines()];
    TA_Integer      outBegLONGLEGGEDDOJI;
    TA_Integer      outNbElementLONGLEGGEDDOJI;

    retCode = TA_CDLLONGLEGGEDDOJI(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegLONGLEGGEDDOJI,
                           &outNbElementLONGLEGGEDDOJI,
                           &outLONGLEGGEDDOJI[0] );

    if(outLONGLEGGEDDOJI[outNbElementLONGLEGGEDDOJI-1] >= 100)
        cout << "POSITIVE - LONGLEGGEDDOJI - get prepared to buy!" << endl;

    if(outLONGLEGGEDDOJI[outNbElementLONGLEGGEDDOJI-1] <= -100)
        cout << "NEGATIVE - LONGLEGGEDDOJI - get prepared to sell!" << endl;

    ///CDLLONGLINE         Long Line Candle
    TA_Integer      outLONGLINE[csvparser.countLines()];
    TA_Integer      outBegLONGLINE;
    TA_Integer      outNbElementLONGLINE;

    retCode = TA_CDLLONGLINE(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegLONGLINE,
                           &outNbElementLONGLINE,
                           &outLONGLINE[0] );

    if(outLONGLINE[outNbElementLONGLINE-1] >= 100)
        cout << "POSITIVE - LONGLINE - get prepared to buy!" << endl;

    if(outLONGLINE[outNbElementLONGLINE-1] <= -100)
        cout << "NEGATIVE - LONGLINE - get prepared to sell!" << endl;

    ///CDLMARUBOZU         Marubozu
    TA_Integer      outMARUBOZU[csvparser.countLines()];
    TA_Integer      outBegMARUBOZU;
    TA_Integer      outNbElementMARUBOZU;

    retCode = TA_CDLMARUBOZU(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegMARUBOZU,
                           &outNbElementMARUBOZU,
                           &outMARUBOZU[0] );

    if(outMARUBOZU[outNbElementMARUBOZU-1] >= 100)
        cout << "POSITIVE - MARUBOZU - get prepared to buy!" << endl;

    if(outMARUBOZU[outNbElementMARUBOZU-1] <= -100)
        cout << "NEGATIVE - MARUBOZU - get prepared to sell!" << endl;

    ///CDLMATCHINGLOW      Matching Low
    TA_Integer      outMATCHINGLOW[csvparser.countLines()];
    TA_Integer      outBegMATCHINGLOW;
    TA_Integer      outNbElementMATCHINGLOW;

    retCode = TA_CDLMATCHINGLOW(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegMATCHINGLOW,
                           &outNbElementMATCHINGLOW,
                           &outMATCHINGLOW[0] );

    if(outMATCHINGLOW[outNbElementMATCHINGLOW-1] >= 100)
        cout << "POSITIVE - MATCHINGLOW - get prepared to buy!" << endl;

    if(outMATCHINGLOW[outNbElementMATCHINGLOW-1] <= -100)
        cout << "NEGATIVE - MATCHINGLOW - get prepared to sell!" << endl;

    ///CDLMATHOLD          Mat Hold
    TA_Integer      outMATHOLD[csvparser.countLines()];
    TA_Integer      outBegMATHOLD;
    TA_Integer      outNbElementMATHOLD;

    retCode = TA_CDLMATHOLD(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           0.5,
                           &outBegMATHOLD,
                           &outNbElementMATHOLD,
                           &outMATHOLD[0] );

    if(outMATHOLD[outNbElementMATHOLD-1] >= 100)
        cout << "POSITIVE - MATHOLD - get prepared to buy!" << endl;

    if(outMATHOLD[outNbElementMATHOLD-1] <= -100)
        cout << "NEGATIVE - MATHOLD - get prepared to sell!" << endl;

    ///CDLMORNINGDOJISTAR  Morning Doji Star
    TA_Integer      outMORNINGDOJISTAR[csvparser.countLines()];
    TA_Integer      outBegMORNINGDOJISTAR;
    TA_Integer      outNbElementMORNINGDOJISTAR;

    retCode = TA_CDLMORNINGDOJISTAR(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           0.3,
                           &outBegMORNINGDOJISTAR,
                           &outNbElementMORNINGDOJISTAR,
                           &outMORNINGDOJISTAR[0] );

    if(outMORNINGDOJISTAR[outNbElementMORNINGDOJISTAR-1] >= 100)
        cout << "POSITIVE - MORNINGDOJISTAR - get prepared to buy!" << endl;

    if(outMORNINGDOJISTAR[outNbElementMORNINGDOJISTAR-1] <= -100)
        cout << "NEGATIVE - MORNINGDOJISTAR - get prepared to sell!" << endl;

    ///CDLMORNINGSTAR      Morning Star
    TA_Integer      outMORNINGSTAR [csvparser.countLines()];
    TA_Integer      outBegMORNINGSTAR ;
    TA_Integer      outNbElementMORNINGSTAR ;

    retCode = TA_CDLMORNINGSTAR (0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           0.3,
                           &outBegMORNINGSTAR ,
                           &outNbElementMORNINGSTAR ,
                           &outMORNINGSTAR [0] );

    if(outMORNINGSTAR[outNbElementMORNINGSTAR-1] >= 100)
        cout << "POSITIVE - MORNINGSTAR - get prepared to buy!" << endl;

    if(outMORNINGSTAR[outNbElementMORNINGSTAR-1] <= -100)
        cout << "NEGATIVE - MORNINGSTAR - get prepared to sell!" << endl;

    ///CDLRICKSHAWMAN      Rickshaw Man
    TA_Integer      outRICKSHAWMAN[csvparser.countLines()];
    TA_Integer      outBegRICKSHAWMAN;
    TA_Integer      outNbElementRICKSHAWMAN;

    retCode = TA_CDLRICKSHAWMAN(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegRICKSHAWMAN,
                           &outNbElementRICKSHAWMAN,
                           &outRICKSHAWMAN[0] );

    if(outRICKSHAWMAN[outNbElementRICKSHAWMAN-1] >= 100)
        cout << "POSITIVE - RICKSHAWMAN - get prepared to buy!" << endl;

    if(outRICKSHAWMAN[outNbElementRICKSHAWMAN-1] <= -100)
        cout << "NEGATIVE - RICKSHAWMAN - get prepared to sell!" << endl;

    ///CDLRISEFALL3METHODS Rising/Falling Three Methods
    TA_Integer      outRISEFALL3METHODS[csvparser.countLines()];
    TA_Integer      outBegRISEFALL3METHODS;
    TA_Integer      outNbElementRISEFALL3METHODS;

    retCode = TA_CDLRISEFALL3METHODS(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegRISEFALL3METHODS,
                           &outNbElementRISEFALL3METHODS,
                           &outRISEFALL3METHODS[0] );

    if(outRISEFALL3METHODS[outNbElementRISEFALL3METHODS-1] >= 100)
        cout << "POSITIVE - RISEFALL3METHODS - get prepared to buy!" << endl;

    if(outRISEFALL3METHODS[outNbElementRISEFALL3METHODS-1] <= -100)
        cout << "NEGATIVE - RISEFALL3METHODS - get prepared to sell!" << endl;

    ///CDLSEPARATINGLINES  Separating Lines
    TA_Integer      outSEPARATINGLINES[csvparser.countLines()];
    TA_Integer      outBegSEPARATINGLINES;
    TA_Integer      outNbElementSEPARATINGLINES;

    retCode = TA_CDLSEPARATINGLINES(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegSEPARATINGLINES,
                           &outNbElementSEPARATINGLINES,
                           &outSEPARATINGLINES[0] );

    if(outSEPARATINGLINES[outNbElementSEPARATINGLINES-1] >= 100)
        cout << "POSITIVE - SEPARATINGLINES - get prepared to buy!" << endl;

    if(outSEPARATINGLINES[outNbElementSEPARATINGLINES-1] <= -100)
        cout << "NEGATIVE - SEPARATINGLINES - get prepared to sell!" << endl;

    ///CDLSHOOTINGSTAR     Shooting Star
    TA_Integer      outSHOOTINGSTAR[csvparser.countLines()];
    TA_Integer      outBegSHOOTINGSTAR;
    TA_Integer      outNbElementSHOOTINGSTAR;

    retCode = TA_CDLSHOOTINGSTAR(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegSHOOTINGSTAR,
                           &outNbElementSHOOTINGSTAR,
                           &outSHOOTINGSTAR[0] );

    if(outSHOOTINGSTAR[outNbElementSHOOTINGSTAR-1] >= 100)
        cout << "POSITIVE - SHOOTINGSTAR - get prepared to buy!" << endl;

    if(outSHOOTINGSTAR[outNbElementSHOOTINGSTAR-1] <= -100)
        cout << "NEGATIVE - SHOOTINGSTAR - get prepared to sell!" << endl;

    ///CDLSHORTLINE        Short Line Candle
    TA_Integer      outSHORTLINE[csvparser.countLines()];
    TA_Integer      outBegSHORTLINE;
    TA_Integer      outNbElementSHORTLINE;

    retCode = TA_CDLSHORTLINE(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegSHORTLINE,
                           &outNbElementSHORTLINE,
                           &outSHORTLINE[0] );

    if(outSHORTLINE[outNbElementSHORTLINE-1] >= 100)
        cout << "POSITIVE - SHORTLINE - get prepared to buy!" << endl;

    if(outSHORTLINE[outNbElementSHORTLINE-1] <= -100)
        cout << "NEGATIVE - SHORTLINE - get prepared to sell!" << endl;

    ///CDLSPINNINGTOP      Spinning Top
    TA_Integer      outSPINNINGTOP[csvparser.countLines()];
    TA_Integer      outBegSPINNINGTOP;
    TA_Integer      outNbElementSPINNINGTOP;

    retCode = TA_CDLSPINNINGTOP(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegSPINNINGTOP,
                           &outNbElementSPINNINGTOP,
                           &outSPINNINGTOP[0] );

    if(outSPINNINGTOP[outNbElementSPINNINGTOP-1] >= 100)
        cout << "POSITIVE - SPINNINGTOP - get prepared to buy!" << endl;

    if(outSPINNINGTOP[outNbElementSPINNINGTOP-1] <= -100)
        cout << "NEGATIVE - SPINNINGTOP - get prepared to sell!" << endl;

    ///CDLSTICKSANDWICH    Stick Sandwich
    TA_Integer      outSTICKSANDWICH[csvparser.countLines()];
    TA_Integer      outBegSTICKSANDWICH;
    TA_Integer      outNbElementSTICKSANDWICH;

    retCode = TA_CDLSTICKSANDWICH(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegSTICKSANDWICH,
                           &outNbElementSTICKSANDWICH,
                           &outSTICKSANDWICH[0] );

    if(outSTICKSANDWICH[outNbElementSTICKSANDWICH-1] >= 100)
        cout << "POSITIVE - STICKSANDWICH - get prepared to buy!" << endl;

    if(outSTICKSANDWICH[outNbElementSTICKSANDWICH-1] <= -100)
        cout << "NEGATIVE - STICKSANDWICH - get prepared to sell!" << endl;

    ///CDLTAKURI           Takuri (Dragonfly Doji with very long lower shadow)
    TA_Integer      outTAKURI[csvparser.countLines()];
    TA_Integer      outBegTAKURI;
    TA_Integer      outNbElementTAKURI;

    retCode = TA_CDLTAKURI(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegTAKURI,
                           &outNbElementTAKURI,
                           &outTAKURI[0] );

    if(outTAKURI[outNbElementTAKURI-1] >= 100)
        cout << "POSITIVE - TAKURI - get prepared to buy!" << endl;

    if(outTAKURI[outNbElementTAKURI-1] <= -100)
        cout << "NEGATIVE - TAKURI - get prepared to sell!" << endl;

    ///CDLTASUKIGAP        Tasuki Gap
    TA_Integer      outTASUKIGAP[csvparser.countLines()];
    TA_Integer      outBegTASUKIGAP;
    TA_Integer      outNbElementTASUKIGAP;

    retCode = TA_CDLTASUKIGAP(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegTASUKIGAP,
                           &outNbElementTASUKIGAP,
                           &outTASUKIGAP[0] );

    if(outTASUKIGAP[outNbElementTASUKIGAP-1] >= 100)
        cout << "POSITIVE - TASUKIGAP - get prepared to buy!" << endl;

    if(outTASUKIGAP[outNbElementTASUKIGAP-1] <= -100)
        cout << "NEGATIVE - TASUKIGAP - get prepared to sell!" << endl;

    ///CDLUNIQUE3RIVER     Unique 3 River
    TA_Integer      outUNIQUE3RIVER[csvparser.countLines()];
    TA_Integer      outBegUNIQUE3RIVER;
    TA_Integer      outNbElementUNIQUE3RIVER;

    retCode = TA_CDLUNIQUE3RIVER(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegUNIQUE3RIVER,
                           &outNbElementUNIQUE3RIVER,
                           &outUNIQUE3RIVER[0] );

    if(outUNIQUE3RIVER[outNbElementUNIQUE3RIVER-1] >= 100)
        cout << "POSITIVE - UNIQUE3RIVER - get prepared to buy!" << endl;

    if(outUNIQUE3RIVER[outNbElementUNIQUE3RIVER-1] <= -100)
        cout << "NEGATIVE - UNIQUE3RIVER - get prepared to sell!" << endl;

    ///CDLUPSIDEGAP2CROWS  Upside Gap Two Crows
    TA_Integer      outUPSIDEGAP2CROWS[csvparser.countLines()];
    TA_Integer      outBegUPSIDEGAP2CROWS;
    TA_Integer      outNbElementUPSIDEGAP2CROWS;

    retCode = TA_CDLUPSIDEGAP2CROWS(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegUPSIDEGAP2CROWS,
                           &outNbElementUPSIDEGAP2CROWS,
                           &outUPSIDEGAP2CROWS[0] );

    if(outUPSIDEGAP2CROWS[outNbElementUPSIDEGAP2CROWS-1] >= 100)
        cout << "POSITIVE - UPSIDEGAP2CROWS - get prepared to buy!" << endl;

    if(outUPSIDEGAP2CROWS[outNbElementUPSIDEGAP2CROWS-1] <= -100)
        cout << "NEGATIVE - UPSIDEGAP2CROWS - get prepared to sell!" << endl;

    ///CDLXSIDEGAP3METHODS Upside/Downside Gap Three Methods

    TA_Integer      outXSIDEGAP3METHODS[csvparser.countLines()];
    TA_Integer      outBegXSIDEGAP3METHODS;
    TA_Integer      outNbElementXSIDEGAP3METHODS;

    retCode = TA_CDLXSIDEGAP3METHODS(0,
                           csvparser.countLines()-1,
                           &openPrice[0],
                           &highPrice[0],
                           &lowPrice[0],
                           &closePrice[0],
                           &outBegXSIDEGAP3METHODS,
                           &outNbElementXSIDEGAP3METHODS,
                           &outXSIDEGAP3METHODS[0] );

    if(outXSIDEGAP3METHODS[outNbElementXSIDEGAP3METHODS-1] >= 100)
        cout << "POSITIVE - XSIDEGAP3METHODS - get prepared to buy!" << endl;
    if(outXSIDEGAP3METHODS[outNbElementXSIDEGAP3METHODS-1] >= 100)
        cout << "NEGATIVE - XSIDEGAP3METHODS - get prepared to sell!" << endl;

}

Candlestick::~Candlestick()
{
    //dtor
}
