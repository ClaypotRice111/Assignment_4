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

using namespace std;


// SmartCarrier class definition
class SmartCarrier {
public:
    static const string DEFAULT_CARRIER_NAME;
    static const bool DEFAULT_INIT;

    // Constructors
    SmartCarrier(const string &name = DEFAULT_CARRIER_NAME);

    // Destructor
    ~SmartCarrier();

    // Member functions
    void Init();
    void StartService();

private:
    void Menu() const;
    int GetChoice() const;
    void ListAccounts() const;
    void InsertMessage();
    void PurgeLargeMessages(); 
    void DisconnectAccount();


    string carrier_name;
    bool init;
    map<string, vector<Message<Media>*>> account_list;

};

// Static constant initialization
const string SmartCarrier::DEFAULT_CARRIER_NAME = "XYZ Wireless";
const bool SmartCarrier::DEFAULT_INIT = false;

// Constructor
SmartCarrier::SmartCarrier(const string &name)
    : carrier_name(name), init(DEFAULT_INIT) {}

// Destructor
SmartCarrier::~SmartCarrier() {
    for (auto &account : account_list) {
        for (auto *message : account.second) {
            delete message;
        }
        account.second.clear();
    }
    account_list.clear();
}

// Member function definitions

void SmartCarrier::Init() {
    // Example initialization
    account_list["669-444-4444"];
    account_list["831-777-7777"].push_back(new Message<Media>("408-222-2222", Media(120.0)));
    account_list["408-111-1111"].push_back(new Message<Media>("415-678-9011", Media(23.08)));
    account_list["408-111-1111"].push_back(new Message<Media>("408-555-8888", Media(875.35)));
    account_list["408-111-1111"].push_back(new Message<Media>("669-000-1234", Media(357.59)));
    init = true;
}

void SmartCarrier::StartService() {
    if (!init) {
        cerr << "System not initialized. Exiting...\n";
        return;
    }

    int choice;
    do {
        try {
            Menu();
            choice = GetChoice();
            switch (choice) {
                case 1:
                    ListAccounts();
                    break;
                case 2:
                    InsertMessage();
                    break;
                case 3:
                    PurgeLargeMessages(); // Extra credit
                    break;
                case 4:
                    DisconnectAccount();
                    break;
                case 5:
                    cout << "Quitting...\n";
                    break;
                default:
                    cerr << "Invalid choice. Please try again.\n";
                    break;
            }
        }
        catch (const exception &e) {
            cerr << "Error: " << e.what() << '\n';
        }
        catch (...) {
            cerr << "An unexpected error occurred.\n";
        }
    } while (choice != 5);
}

void SmartCarrier::Menu() const {
    cout << "\nFOOTHILL WIRELESS\n"
              << "ACCOUNT ADMIN\n"
              << "1. List all accounts and their messages' usages\n"
              << "2. Add a message to an account\n"
              << "3. Purge large messages from an account\n"
              << "4. Disconnect an account\n"
              << "5. Quit\n";
}

int SmartCarrier::GetChoice() const {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

void SmartCarrier::ListAccounts() const {
    cout << setw(15) << "Phone Number"
              << setw(15) << "Messages"
              << setw(15) << "Size (MB)"
              << setw(15) << "Charge ($)\n";

    for (const auto &account : account_list) {
        const string &phone = account.first;
        const vector<Message<Media>*> &messages = account.second;

        int message_count = messages.size();
        double total_size = 0.0;
        double total_charge = 0.0;

        for (const auto *message : messages) {
            total_size += message->get_data().get_size();
            total_charge += message->get_data().GetCharge();
        }

        cout << setw(15) << phone
                  << setw(15) << message_count
                  << setw(15) << fixed << setprecision(2) << total_size
                  << setw(15) << fixed << setprecision(2) << total_charge << '\n';
    }
}

void SmartCarrier::InsertMessage() {
    string phone;
    cout << "Enter phone number: ";
    cin >> phone;

    auto it = account_list.find(phone);
    if (it == account_list.end()) {
        throw runtime_error("Account " + phone + " does not exist!");
    }

    double size;
    string to;
    cout << "Enter media size (MB): ";
    cin >> size;
    cout << "Enter recipient phone number: ";
    cin >> to;

    it->second.push_back(new Message<Media>(to, Media(size)));
}

void SmartCarrier::PurgeLargeMessages() {
    string phone;
    cout << "Enter phone number: ";
    cin >> phone;

    auto it = account_list.find(phone);
    if (it == account_list.end()) {
        throw runtime_error("Account " + phone + " does not exist!");
    }

    auto &messages = it->second;
    double purged_size = 0.0;

    for (auto msg_it = messages.begin(); msg_it != messages.end();) {
        if ((*msg_it)->get_data().get_size() >= Media::SIZE_THRESHOLD) {
            purged_size += (*msg_it)->get_data().get_size();
            delete *msg_it;
            msg_it = messages.erase(msg_it);
        } else {
            ++msg_it;
        }
    }

    cout << "Purged " << purged_size << " MB from account " << phone << ".\n";
}

void SmartCarrier::DisconnectAccount() {
    string phone;
    cout << "Enter phone number: ";
    cin >> phone;

    auto it = account_list.find(phone);
    if (it == account_list.end()) {
        throw runtime_error("Account " + phone + " does not exist!");
    }

    for (auto *message : it->second) {
        delete message;
    }

    account_list.erase(it);
}

#endif