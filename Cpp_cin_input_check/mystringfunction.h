#ifndef MYSTRINGFUNCTION_H
#define MYSTRINGFUNCTION_H

#include <string>

namespace my {
using std::string;

char getLastSymbol(const string &str);

char deleteLastSymbol(string *str);

string intToStr(int a);

void alignString(string *str, size_t width, char fillSymbol = ' ');

int compareNumericString(string str1, string str2);
}

#endif // MYSTRINGFUNCTION_H
