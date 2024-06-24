#include <iostream>
#include "includes/SmartCarrier.h"


int main(int argc, char* argv[]) {
    SmartCarrier* smart_carrier = new SmartCarrier("Foothill wireless");
    smart_carrier->Init();
    smart_carrier->StartService();
    delete smart_carrier;
	return 0;
}


