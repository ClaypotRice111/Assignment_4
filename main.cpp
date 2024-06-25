
//============================================================================
// File Name : main.cpp
// Author : Weiaho Huang
// Copyright : You can copy it or modify it. Unlness you use it on business or profitability activiy.
// Description : The goal of this project is to understand the usage of the c++ standrad library. Call the data structure to accomplish data management.

// Disclaimer: If this program works obviously it's written by the above author. If it doesn't I don't know who wrote it.
// Revision History:
// Date                      Version         Change ID               Author                     Comment
// 06-07-2024                 1.0            2b35889                 Weihao Huang               create the project
// 06-15-2024                 1.1			 d5c9fb4                 Weihao Huang               build class skeletons
// 06-17-2024				  1.2			 af76408				 Weihao Huang 				using auto to define variable types
// 06-23-2024                 2.0            73edac6                 Weihao Huang               full version
// 06-24-2024                 2.1            52bd6e4                 Weihao Huang               fixed bugs
//============================================================================
#include <iostream>
#include "includes/SmartCarrier.h"


int main(int argc, char* argv[]) {
    SmartCarrier* p_smart_carrier = new SmartCarrier("Foothill wireless");
    p_smart_carrier->Init();
    p_smart_carrier->StartService();
    delete p_smart_carrier;
	return 0;
}


