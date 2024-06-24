#include "Media.h"



// Static constants initialization
const double Media::DEFAULT_SIZE = 0.0;
const double Media::DEFAULT_CHARGE_PER_MB = 0.05;
const double Media::DEFAULT_MINIMUM_CHARGE = 1.00;
const double Media::SIZE_THRESHOLD = 100.0;


Media::Media(){
    this->size = Media::DEFAULT_SIZE;
}

Media::Media(const double& size){
    this->size = size;
}

Media::~Media() {}


double Media::get_size() const {
    return size;
}


void Media::set_size(const double& new_size) {
    this->size = new_size;
}


double Media::GetCharge() const {
    // multiply charge per MB by size.
    double charge = size * DEFAULT_CHARGE_PER_MB;
    // If the result is greater than default minimum charge of 1.00 return it.
    if (charge > DEFAULT_MINIMUM_CHARGE) 
        return charge;
    // return the default minimum charge.
    return DEFAULT_MINIMUM_CHARGE;
}