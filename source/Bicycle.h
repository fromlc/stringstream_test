/*********************************************************
Cuyamaca College CS-281
File name:    Bicycle.h
Description: PA08 - Header file for Bicycle class that derives TwoWheeler class
Developer: A Student
*********************************************************************************************/
#pragma once

#include "TwoWheeler.h"

#include <string>
using std::string;

/*********************************************
- The class Bicycle will derive TwoWheeler
- The serial_number will be unique for Bicycle
*************************************************************************/
class Bicycle : public TwoWheeler {
    // allow private member access from function reading data into instances
    friend void addDataItem(string, int);

private:
    string serial_number;  //Bicycle's serial_number as its unique member
    
public:
    
    //Default constructor to invoke TwoWheeler default constructor
    Bicycle() : TwoWheeler(ID_BICYCLE) { }
    
    //Overload constructor with parameters for Bicycle specs
    Bicycle(string _mfr, string _model, string _serial_number) :
        TwoWheeler(ID_BICYCLE, _mfr, _model) {
        
        //Bicycle's serial number
        //serial_number = _serial_number;
    }
    
    //Accessor function to get the Bicycle's serial number
    string get_serial_number() const {return serial_number;}
};
