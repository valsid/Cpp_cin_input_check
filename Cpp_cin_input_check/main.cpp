#include <iostream>

#include "getvalue.h"
#include "getvalue0.h"

using namespace std;


int main()
{
    cout << "Enter number: ";

    long double doubleVar = getDoubleVal();

    cout << "\nresult: "
         << "\n\tnumber: " << doubleVar;

/*    doubleVar = getValue0<long double>();

    cout << "\nresult: "
         << "\n\tnumber: " << doubleVar;
/**/
    return 0;
}

