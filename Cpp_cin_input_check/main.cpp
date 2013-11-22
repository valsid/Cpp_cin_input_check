#include <iostream>
using std::cout;

#include "getvalue.h"
#include "getvalue0.h"
// #include "getIntValue.h"

int main()
{
    cout << "Enter number: ";

    long double doubleVar;
//    doubleVar = getDoubleVal();
//    doubleVar = getValue0<long double>("Error: ");
    doubleVar = getIntValue(-1000, 1000);

    cout << "\nresult: "
         << "\n\tnumber: " << doubleVar;

    return 0;
}

