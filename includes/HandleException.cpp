#include "HandleException.h"

AccountNotFoundException::AccountNotFoundException(const string& phone){
    this->phone_number = phone;
};

AccountNotFoundException::~AccountNotFoundException(){};

const char* AccountNotFoundException::what() const noexcept{
    string message;
    message = "Account " + phone_number + " does not exist!";
    return message.c_str();
}