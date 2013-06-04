#include "../include/Aroon.h"
#include "../ta-lib/c/include/ta_libc.h"
#include "../include/CSVParser.h"

Aroon::Aroon(CSVParser& csvparser, double highPrice[], double lowPrice[])
{
    /// AROON INDICATOR - NOT CHECKED
    /// . anticiper le passage de la tendance à un range
    /// . déterminer la force du mouvement
    /// http://www.tribuforex.fr/Apprendre-aroon
    /// AROON period default is 25, on some panels 14
    TA_Real         outAroonDown[csvparser.countLines()];
    TA_Real         outAroonUp[csvparser.countLines()];
    TA_Integer      outBegAroon;
    TA_Integer      outNbElementAroon;
    TA_RetCode      retCode;

    retCode = TA_AROON(0,
                       csvparser.countLines()-1,
                       &highPrice[0],
                       &lowPrice[0],
                       25, /* From 2 to 100000 */
                       &outBegAroon,
                       &outNbElementAroon,
                       &outAroonDown[0],
                       &outAroonUp[0]);

}

Aroon::~Aroon()
{
    //dtor
}
