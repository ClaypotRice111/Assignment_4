#ifndef ACCOUNTNOTFOUMDEXCEPTION_H
#define ACCOUNTNOTFOUMDEXCEPTION_H

#include <iostream>
#include <exception>
#include <string>
using namespace std;

class AccountNotFoundException : public exception{
public:
    AccountNotFoundException(const string& phone);
    ~AccountNotFoundException();
    
    const char* what() const;
private:
    string phone_number;
};

AccountNotFoundException::AccountNotFoundException(const string& phone){
    this->phone_number = phone_number;
}

AccountNotFoundException::~AccountNotFoundException(){
}


const char* AccountNotFoundException::what() const{
    return ("Account " + phone_number + " does not exist!").c_str();
};








#endif