# stringstream_test

This is driver code not release code.

Useful for: auditioning ways to handle recoverable std::stringstream errors.

Scenario: reading derived class data from file into std::list<BaseClass*>

Data file format: 
- each line starts with int classID to identify derived class instance
- additional data fields are assumed to differ by derived class.

Required to do:
- Use C++17
- Base and derived classes must friend function addDataItem().
> //allow private member access from function reading data into instances
> friend void addDataItem(string, int);
