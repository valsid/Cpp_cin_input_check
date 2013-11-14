#include <iostream>

#include "getvalue.h"
#include "getvalue0.h"
#include "getvalueformenu.h"

using namespace std;

#include <string>

int main()
{
    cout << "Enter number: ";

    long double doubleVar;
//    doubleVar = getDoubleVal();
//    doubleVar = getValue0<long double>("Error: ");
//    doubleVar = getValueForMenu(-1000, 1000);

    cout << "\nresult: "
         << "\n\tnumber: " << doubleVar;

    return 0;
}

