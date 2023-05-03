//------------------------------------------------------------------------------
// TwoWheeler.h : base class declaration and definition
//------------------------------------------------------------------------------
#pragma once

#include <string>
using std::string;

//------------------------------------------------------------------------------
// constants : identify type of two-wheel vehicle
//------------------------------------------------------------------------------
constexpr int ID_BASE = 0;
constexpr int ID_BICYCLE = 1;
constexpr int ID_SCOOTER = 2;

//------------------------------------------------------------------------------
// TwoWheeler
//------------------------------------------------------------------------------
class TwoWheeler {
// allow private member access from function reading data into instances
    friend void addDataItem(string, int);

// allow private member access from derived classes 
protected:
    int typeId;
    string mfr;
    string model;

public:
    // constructors
    TwoWheeler() : typeId(ID_BASE) { }

    TwoWheeler(int _typeID) : typeId(_typeID) { }

    TwoWheeler(int _typeId, string _mfr, string _model) :
        typeId(_typeId), mfr(_mfr), model(_model) { }

    // getters
    int getTypeId() const { return typeId; }
    const string& getMfr() const { return mfr; }
    const string& getModel() const { return model; }
};
