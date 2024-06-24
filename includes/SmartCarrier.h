#ifndef SMARTCARRIER_H
#define SMARTCARRIER_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stdexcept>
#include <iomanip>
#include "Message.h"
#include "Media.h"
#include "HandleException.h"

using namespace std;


// SmartCarrier class definition
class SmartCarrier {
public:
    static const string DEFAULT_CARRIER_NAME;
    static const bool DEFAULT_INIT;

    // 
    SmartCarrier();
    SmartCarrier(const string &name);
    ~SmartCarrier();

    // Member functions
    void Init();
    void StartService();

private:
    // private funcitons 
    void Menu() const;
    int GetChoice();
    void ListAccounts() const;
    void InsertMessage();
    void PurgeLargeMessages(); 
    void DisconnectAccount();

    // private variable
    string carrier_name;
    bool init;
    // map <key, value> 
    map<string, vector<Message<Media>*>> account_list;
    
};


#endif