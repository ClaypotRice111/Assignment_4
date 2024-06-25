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
    Media(const double& size); 
    ~Media(); 

    // accessor & mutator
    double get_size() const; 
    // void set_size(double new_size);
    void set_size(const double& new_size); 

    // member function to calculate charge
    double GetCharge() const; 

private:
    double size; // size in MB

};



#endif