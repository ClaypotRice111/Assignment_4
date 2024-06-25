#ifndef HANDLEEXCEPTION_H
#define HANDLEEXCEPTION_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <exception>
#include <iomanip>
using namespace std;



// Class AccountNotFoundException derived from the library exception class. 
// This class should contain a member data representing a phone number 
// (which is an invalid key in the STL map). Redefine the what () member 
// function to display appropriate error message such as "Account 408-555-999 
// does not exist!".


class AccountNotFoundException: public exception{
public:
    AccountNotFoundException(const string& phone);
    ~AccountNotFoundException();
    
    virtual const char* what() const noexcept;
private:
    string message;
};










#endif