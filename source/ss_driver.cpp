//------------------------------------------------------------------------------
// ss_driver.cpp
// 
// - demos stringstream used with getline()
//------------------------------------------------------------------------------
#include "Bicycle.h"
#include "Scooter.h"

#include <fstream>
#include <iostream>
#include <list>
#include <sstream>

using std::cout, std::ifstream, std::string, std::stringstream;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
const enum errors { ERROR_FILE_OPEN = 1, ERROR_FILE_FORMAT };

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
namespace g {
    std::list<TwoWheeler*>* pData = new std::list<TwoWheeler*>;
}

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
ifstream openDataFile(const string&);
void readDataFile(const string&);
void addDataItem(string, int);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {
    readDataFile("pa9_inventory.txt");

    // blank line after error messages
    cout << std::endl;

    for (auto pItem : *g::pData) {
        cout << pItem->getTypeId() << ' '
            << pItem->getMfr() << ' '
            << pItem->getModel()
            << '\n';
    }

    return 0;
}

//------------------------------------------------------------------------------
// throws ifstream exception on file open fail
//------------------------------------------------------------------------------
ifstream openDataFile(const string& filename) {

    ifstream fromFile(filename);
    if (!fromFile.is_open()) {
        cout << "File open error: " << filename << std::endl;
        exit(ERROR_FILE_OPEN);
    }
    return fromFile;
}

//------------------------------------------------------------------------------
// streams file data into list as Bicycle or Scooter instance pointers
//------------------------------------------------------------------------------
void readDataFile(const string& filename) {

    ifstream fromFile = openDataFile(filename);

    int lineNumber = 0;
    string line;
    while (std::getline(fromFile, line)) {

        try {
            // stringstream parses data lines into delimited fields
            addDataItem(line, ++lineNumber);
        }
        catch (std::exception& e) {
            cout << e.what() << '\n';
            continue;
        }
    }

    fromFile.close();
}

//------------------------------------------------------------------------------
// loops to stream file data lines into new Bicycle or Scooter instances
//------------------------------------------------------------------------------
void addDataItem(string line, int lineNumber) {

    int classID;
    stringstream ss;    // to parse file line
    ss << line;

    ss >> classID;      // first token identifies Bicycle or Scooter class

    //ss.exceptions(std::ios::failbit);
    //#TODO
    // for now handle stringstream errors with if statements
    // refactor to throw FileFormatException instead

    if (classID == ID_BICYCLE) {
        Bicycle* pB = new Bicycle();
        if (ss >> pB->mfr && ss >> pB->model && ss >> pB->serial_number) {
            g::pData->push_back(pB);
        }
        else {
            cout << "Line " << lineNumber << ": bad Bicycle data\n";
        }
    }
    else if (classID == ID_SCOOTER) {
        Scooter* pS = new Scooter();
        if (ss >> pS->mfr && ss >> pS->model && ss >> pS->horsepower) {
            g::pData->push_back(pS);
        }
        else {
            cout << "Line " << lineNumber << ": bad Scooter data\n";
        }
    }
    else {
        cout << "Line " << lineNumber
            << ": unknown data type : " << classID << '\n';
    }

    // is there more data after last valid field?
    if (ss << line) {
        cout << "Line " << lineNumber << ": extra data for ";
        if (classID == ID_BICYCLE) {
            cout << "Bicycle\n";
        }
        else if (classID == ID_SCOOTER) {
            cout << "Scooter\n";
        }
        else {
            cout << "unknown data type\n";
        }
    }
}