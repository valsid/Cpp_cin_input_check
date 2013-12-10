#ifndef GETVALUEFORMENU_H
#define GETVALUEFORMENU_H

#include <limits>

namespace my {
using std::numeric_limits;

int getIntValue(int minValue = numeric_limits<int>::min(), int maxValue = numeric_limits<int>::max());

}
#endif // GETVALUEFORMENU_H
