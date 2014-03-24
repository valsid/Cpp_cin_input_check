#ifndef GETINTVALUE_H
#define GETINTVALUE_H

#include <limits>

namespace inputCheck {
using std::numeric_limits;

int getIntValue(int minValue = numeric_limits<int>::min(), int maxValue = numeric_limits<int>::max());

}
#endif // GETINTVALUE_H
