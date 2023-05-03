/*********************************************************
Cuyamaca College CS-281
File name:    Scooter.h
Description: PA08 - Header file for Scooter class that derives TwoWheeler class
Developer: A Student
*********************************************************************************************/
#pragma once

#include "TwoWheeler.h"
#include <string>
using std::string;

/*********************************************
- The class Scooter will derive TwoWheeler
- The horsepower setting  will be unique for Bicycle
*************************************************************************/
class Scooter : public TwoWheeler {
    // allow private member access from function reading data into instances
    friend void addDataItem(string, int);

private:
    double horsepower;  //The Scooter's horsepower

public:

    //Default Scooter constructor
    Scooter() : TwoWheeler(ID_SCOOTER) {

        //TwoWheeler default constructor

        //Initialize Scooter's horsepower
        horsepower = 0.0;
    }

    //Overload Scooter constructor with parameters
    Scooter(string _mfr, string _model, double _horsepower) :
        TwoWheeler(ID_SCOOTER, _mfr, _model) {

        //Invoke overload TwoWheeler constructor

        //Initialize horsepower
        horsepower = _horsepower;
    }

    //Accessor function to get Scooter horsepower
    double get_horsepower() const { return horsepower; }
};
