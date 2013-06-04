#include "../include/CSVParser.h"
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

CSVParser::CSVParser() {}
int CSVParser::countLines() { return _countLines; }
int CSVParser::countColumns() { return _countColumns; }
bool CSVParser::isFilled() { return _isFilled; }
void CSVParser::setFilled(bool isFilled) { _isFilled = isFilled; }

double CSVParser::getValue(int x, int y)
{
    double returnedValue = 0.0;
    bool valid = false;

    if(x >= 0 && x <= countLines())
        if(y >= 0 && y <= countColumns()) {
            return _values[x][y];
            valid = true;
        }

    if(valid)
        return returnedValue;
    else {
        cout << "value : " << x << "," << y << " out of bounds" << endl;
        exit(1);
    }
}

double CSVParser::getNormalizedValue(int x, int y)
{
    double returnedValue = 0.0;
    bool valid = false;

    if(x >= 0 && x <= countLines())
        if(y >= 0 && y <= countColumns()) {
            return _normalizedValues[x][y];
            valid = true;
        }

    if(valid)
        return returnedValue;
    else {
        cout << "normalized value : " << x << "," << y << " out of bounds" << endl;
        exit(1);
    }
}

double CSVParser::getMaxValueFromColumn(int y)
{
    if(y >= 0 && y < countColumns()) {
        double maxValue = getValue(0, y);
        for(int x = 0; x < countLines(); x++) {
            if(getValue(x,y) > maxValue)
                maxValue = getValue(x,y);
        }
        return maxValue;
    }
    else
    {
        cout << "Invalid column : " << y << endl;
        exit(0);
    }
}

CSVParser::~CSVParser()
{

}

CSVParser::CSVParser(string filename)
{
    _filename = filename;
    ifstream fileHandler(_filename.c_str(), ios::in);

    bool hasSemicolon = false;
    if(fileHandler) {
        string line;
        size_t found;

        for(int i = 0; i < 10; i++) {
            getline(fileHandler, line);
            found = line.find(';');
            if(found != string::npos)
                hasSemicolon = true;
        }
    }
    else {
        cout << "File " << _filename << " does not exist." << endl;
        exit(1);
    }

    fileHandler.close();

    if(hasSemicolon)
        this->_separator = ';';
    else
        this->_separator = ',';

    cout << "Separator is " << _separator << endl;

    fileHandler.open(_filename.c_str(), ios::in);

    int tmp_countLines = 0;
    string line;
    while(getline(fileHandler, line))
        if(line != "")
            tmp_countLines++;

    fileHandler.close();

    _countLines = tmp_countLines;

    cout << "CountLines = " << _countLines << endl;

    fileHandler.open(_filename.c_str(), ios::in);

    int k = 0;
    int * countColumnsTmp = new int[_countLines+1];

    while(!fileHandler.eof()) {
        string line;
        getline(fileHandler, line);
        istringstream iss(line);
        string token;

        int j = 0;
        while(getline(iss, token, _separator)) {
            _values[k][j] = atof(token.c_str());
            j++;
        }
        countColumnsTmp[k] = j;
        j=0;
        k++;
    }

    int countColumnsTmpMax = 0;

    for(int i=0; i<countLines(); i++)
        if(countColumnsTmpMax <= countColumnsTmp[i])
            countColumnsTmpMax = countColumnsTmp[i];

    fileHandler.close();
    _countColumns = countColumnsTmpMax;
    cout << "CountColumns = " << _countColumns << endl;
    setFilled(true);
}

void CSVParser::debug()
{
    string debugNormalizedHandler = _filename + ".DEBUG";
    ofstream fileHandler(debugNormalizedHandler.c_str(), ios::out | ios::trunc);

    for(int i = 0; i < countLines(); i++)
        for(int j = 0; j < countColumns(); j++) {
            if(j == (countColumns()-1)) {
                fileHandler << getValue(i,j) << endl;
                //cout << getValue(i,j) << endl;
            }
            else {
                fileHandler << getValue(i,j) << ";";
                //cout << getValue(i,j) << ";";
            }
        }

    fileHandler.close();
}

void CSVParser::normalizedDebug()
{
    string debugNormalizedHandler = _filename + ".DEBUG.NORMALIZED";
    ofstream fileHandler(debugNormalizedHandler.c_str(), ios::out | ios::trunc);

    for(int i = 0; i < countLines(); i++)
        for(int j = 0; j < countColumns(); j++) {
            if(j == (countColumns()-1)) {
                fileHandler << getNormalizedValue(i,j) << endl;
            }
            else {
                fileHandler << getNormalizedValue(i,j) << ";";
            }
        }

    fileHandler.close();
}

void CSVParser::reload()
{
    cout << "Reloading CSV file" << endl;
    cout << "Nothing to be done" << endl;
    cout << "System is going to exit" << endl;
    exit(0);
}

void CSVParser::normalize()
{
    for(int y=0; y<countColumns(); y++)
        for(int x=0; x<countLines(); x++)
            _normalizedValues[x][y] = (double) (getValue(x,y) / getMaxValueFromColumn(y));
}

string CSVParser::getFilename()
{
	return _filename;
}