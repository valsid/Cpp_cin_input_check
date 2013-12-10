#include <iostream>
using std::cout;

#include "getdoublevalue.h"
#include "getvalue0.h"
#include "getIntValue.h"

int main()
{
    cout << "Enter number: ";

    long double doubleVar;

//    doubleVar = my::getLDoubleVal();
//    doubleVar = my::getValue0<long double>("Error: ");
    doubleVar = my::getIntValue(-1000, 1000);

    cout << "\nresult: "
         << "\n\tnumber: " << doubleVar;

    return 0;
}

