#include "SmartCarrier.h"



// Static constant initialization
const string SmartCarrier::DEFAULT_CARRIER_NAME = "XYZ Wireless";
const bool SmartCarrier::DEFAULT_INIT = false;


SmartCarrier::SmartCarrier(){
    this->carrier_name = SmartCarrier::DEFAULT_CARRIER_NAME;
    this->init = SmartCarrier::DEFAULT_INIT;
}

SmartCarrier::SmartCarrier(const string &name){
    this->carrier_name = name;
    this->init = SmartCarrier::DEFAULT_INIT;
}

SmartCarrier::~SmartCarrier() {
    // vector element are pointers
    for (auto &account: account_list) {
        for (auto *message: account.second) {
            delete message;
        }
        account.second.clear();
    }
    account_list.clear();
}

// Member function definitions
void SmartCarrier::Init() {
    account_list["669-444-4444"];
    account_list["831-777-7777"].push_back(new Message<Media>("408-222-2222", Media(120.0)));
    account_list["408-111-1111"].push_back(new Message<Media>("415-678-9011", Media(23.08)));
    account_list["408-111-1111"].push_back(new Message<Media>("408-555-8888", Media(875.35)));
    account_list["408-111-1111"].push_back(new Message<Media>("669-000-1234", Media(357.59)));
    account_list["408-333-3333"];
    account_list["650-555-5555"].push_back(new Message<Media>("408-123-4567", Media(50.5)));
    account_list["650-555-5555"].push_back(new Message<Media>("650-987-6543", Media(15.75)));
    account_list["669-444-4444"].push_back(new Message<Media>("831-333-9999", Media(250.0)));
    account_list["831-888-8888"].push_back(new Message<Media>("831-555-5555", Media(75.25)));
    account_list["831-888-8888"].push_back(new Message<Media>("831-666-6666", Media(120.4)));
    account_list["510-111-1111"].push_back(new Message<Media>("408-222-3333", Media(35.6)));
    account_list["510-111-1111"].push_back(new Message<Media>("510-999-8888", Media(60.0)));
    account_list["510-111-1111"].push_back(new Message<Media>("510-777-7777", Media(95.3)));

    init = true;
}

void SmartCarrier::StartService() {
    if (!init) {
        cerr << "System not initialized. Exiting...\n";
        return;
    }

    int choice = 0;
    do {
        try {
            Menu();
            choice = GetChoice();
            switch (choice) {
                case 1: ListAccounts();break;
                case 2: InsertMessage();break;
                case 3: PurgeLargeMessages(); break;
                case 4: DisconnectAccount();break;
                case 5: cout << "Quitting...\n";break;
                default: cerr << "Invalid choice. Please try again.\n"; break;
            }
        }
        catch (const AccountNotFoundException &e) {
            cerr << "Error: " << e.what() << '\n';
        }
        catch (...) {
            cerr << "An unexpected error occurred.\n";
        }
    } while (choice != 5);
}

void SmartCarrier::Menu() const {
    cout << "\n" << carrier_name << "\n"
              << "ACCOUNT ADMIN\n"
              << "1. List all accounts and their messages' usages\n"
              << "2. Add a message to an account\n"
              << "3. Purge large messages from an account\n"
              << "4. Disconnect an account\n"
              << "5. Quit\n";
}

int SmartCarrier::GetChoice(){
    int choice = 0;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

void SmartCarrier::ListAccounts() const {
    cout    << setw(15) << "Phone Number"
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

    auto iter = account_list.find(phone);
    if (iter == account_list.end()) {
        throw AccountNotFoundException(phone);
    }

    double size;
    string to;
    cout << "Enter media size (MB): ";
    cin >> size;
    cout << "Enter recipient phone number: ";
    cin >> to;

    iter->second.push_back(new Message<Media>(to, Media(size)));
}

void SmartCarrier::PurgeLargeMessages() {
    string phone;
    cout << "Enter phone number: ";
    cin >> phone;

    auto iter = account_list.find(phone);
    if (iter == account_list.end()) {
        throw AccountNotFoundException(phone);
    }

    auto &messages = iter->second;
    double purged_size = 0.0;

    for (auto vector_iter = messages.begin(); vector_iter != messages.end(); ++vector_iter){
        if ((*vector_iter)->get_data().get_size() >= Media::SIZE_THRESHOLD) {
            purged_size += (*vector_iter)->get_data().get_size();
            delete *vector_iter;
            vector_iter = messages.erase(vector_iter);
        }
    }

    cout << "Purged " << purged_size << " MB from account " << phone << ".\n";
}

void SmartCarrier::DisconnectAccount() {
    string phone;
    cout << "Enter phone number: ";
    cin >> phone;

    auto account = account_list.find(phone);
    if (account == account_list.end()) {
        throw AccountNotFoundException(phone);
    }

    for (auto *message : account->second) {
        delete message;
    }
    
    account_list.erase(account);
}