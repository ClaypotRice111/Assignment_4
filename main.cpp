#include <iostream>
#include "includes/SmartCarrier.h"

using namespace std;

int main(int argc, char* argv[]) {
    SmartCarrier smart_carrier;
    smart_carrier.Init();
    smart_carrier.StartService();
    
	return 0;
}


