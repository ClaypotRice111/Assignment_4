#include "HandleException.h"

AccountNotFoundException::AccountNotFoundException(const string& phone){
    this->message = "Account " + phone + " does not exist!";
};

AccountNotFoundException::~AccountNotFoundException(){};

const char* AccountNotFoundException::what() const noexcept {
    return message.c_str();
}