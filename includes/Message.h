#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Message {
public:
    static const string DEFAULT_TO;

    Message();
    Message(const string &to, const T &data);
    ~Message();

    // Accessors and Mutators
    T get_data() const;
    void set_data(const T &data);
    string get_to() const;
    void set_to(const string &to);

private:
    string to; 
    T m_data; 

};



template <typename T>
const string Message<T>::DEFAULT_TO = "000-000-0000";


template <typename T>
Message<T>::Message() : to(DEFAULT_TO), m_data(T()) {}


template <typename T>
Message<T>::Message(const string &to, const T &data) : to(to), m_data(data) {}


template <typename T>
Message<T>::~Message() {}


template <typename T>
T Message<T>::get_data() const {
    return m_data;
}


template <typename T>
void Message<T>::set_data(const T &data) {
    m_data = data;
}


template <typename T>
string Message<T>::get_to() const {
    return to;
}


template <typename T>
void Message<T>::set_to(const string &to) {
    this->to = to;
}

#endif