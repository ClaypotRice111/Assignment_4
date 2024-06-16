#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>

class Media {
public:
    static const double DEFAULT_SIZE;
    static const double DEFAULT_CHARGE_PER_MB;
    static const double DEFAULT_MINIMUM_CHARGE;
    static const double SIZE_THRESHOLD;

    Media();
    Media(double size); 
    ~Media(); 

    // accessor & mutator
    double get_size() const; 
    void set_size(double new_size); 

    // member function to calculate charge
    double GetCharge() const; 

private:
    double size; // size in MB

};

// Static constants initialization
const double Media::DEFAULT_SIZE = 0.0;
const double Media::DEFAULT_CHARGE_PER_MB = 0.05;
const double Media::DEFAULT_MINIMUM_CHARGE = 1.00;
const double Media::SIZE_THRESHOLD = 100.0;


Media::Media(){
    this->size = DEFAULT_SIZE;
}

Media::Media(double size){
    this->size = size;
}


Media::~Media() {}


double Media::get_size() const {
    return size;
}


void Media::set_size(double new_size) {
    size = new_size;
}


double Media::GetCharge() const {
    double charge = size * DEFAULT_CHARGE_PER_MB;
    return (charge > DEFAULT_MINIMUM_CHARGE) ? charge : DEFAULT_MINIMUM_CHARGE;
}


#endif