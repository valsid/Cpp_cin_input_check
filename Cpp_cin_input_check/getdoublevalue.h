#ifndef GETVALUE_H
#define GETVALUE_H

#include <limits>

namespace my {
using std::numeric_limits;

long double getLDoubleVal(long double minValue = numeric_limits<long double>::min(),
                          long double maxValue = numeric_limits<long double>::max());

}
#endif // GETVALUE_H
