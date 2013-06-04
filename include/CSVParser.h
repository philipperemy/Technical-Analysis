#ifndef CSVPARSER_H
#define CSVPARSER_H

#define DEBUG 0

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

class CSVParser
{
    public:

        static const int MAX_LINES = 4000;
        static const int MAX_COLUMNS = 10;

        bool isFilled();
        void setFilled(bool isFilled);
        vector < vector <double> > getValues();
        void debug();
        void normalizedDebug();
        double getValue(int x, int y);
        double getNormalizedValue(int x, int y);
        int countColumns();
        int countLines();
        double getMaxValueFromColumn(int y);
        void reload();
        void normalize();
		string getFilename();

        CSVParser(string filename);
        CSVParser(string filename, int countLines, int countColumns, vector < vector <double> > values);
        CSVParser();
        ~CSVParser();

    private:

        bool _isFilled;
        string _filename;
        char _separator;
        int _countLines;
        int _countColumns;
        double _values[MAX_LINES][MAX_COLUMNS];
        double _normalizedValues[MAX_LINES][MAX_COLUMNS];
};

#endif // CSVPARSER_H
