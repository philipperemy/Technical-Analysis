#include "../include/TA_Entity.h"

using namespace std;

TA_Entity::TA_Entity(TA_Real begin, TA_Real nbElements, TA_Real* out)
{
    _begin = begin;
    _nbElements = nbElements;

    for(int i= 0; i< _nbElements; i++) {
        int k = _begin + i;
        //cout << out[k] << endl;
        _out[k] = out[k];
       // cout << _out[k] << endl;
    }

}

TA_Real TA_Entity::getBegin() { return _begin; }
TA_Real TA_Entity::getNbElements() { return _nbElements; }
TA_Real* TA_Entity::getPrices() { return _out; }
TA_Real TA_Entity::get(int id) { return _out[id]; }


TA_Entity::~TA_Entity() { delete(_out); }
