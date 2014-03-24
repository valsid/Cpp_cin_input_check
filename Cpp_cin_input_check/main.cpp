#include <iostream>
using std::cout;

#include "getdoublevalue.h"
#include "getvalue0.h"
#include "getintvalue.h"

int main()
{
    cout << "Enter number: ";

    long double doubleVar;

//    doubleVar = inputCheck::getLDoubleVal();  // temporarily disabled
//    doubleVar = inputCheck::getValue0<long double>("Error: ");
    doubleVar = inputCheck::getIntValue(-1000, 1000);

    cout << "\n result: \n"
         << "\tnumber: " << doubleVar << "\n";

    return 0;
}

