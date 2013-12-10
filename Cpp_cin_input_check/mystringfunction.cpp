#include "mystringfunction.h"

#include <sstream>
using std::stringstream;

namespace my {

char getLastSymbol(const string &str)
{
    return *( str.rbegin() );   // strRes.back() in C++11
}


char deleteLastSymbol(string *str)
{
    char lastSymbol = getLastSymbol(*str);
    str->erase(str->length() - 1);
    return lastSymbol;
}


string intToStr(int a)
{
    stringstream ss;
    ss << a;
    return ss.str();
}


void alignString(string *str, size_t width, char fillSymbol)
{
    if(str->empty()) return;
    if(width < str->size()) return;

    size_t w = width - str->size();
    for(size_t i = 0; i < w; i++) {
        *str = fillSymbol + *str;
    }
}

int compareNumericString(string str1, string str2)
{
    // "123" "123" > 0
    // "123" "12"  > -1
    // "12" "123"  > 1
    // "123" "234" > 1
    // "123" ""    > -1
    // ""    "123" > 1
    // ""    ""    > 0
   // "-123" "123" > 1
   // "123" "-123" > -1
  // "-123" "-234" > -1

#warning checkValid

    int str1GreaterStr2 = -1,
        str1EqualStr2 = 0,
        str1LessStr2 = 1;

    const size_t size1 = str1.size(),
                 size2 = str2.size();

    if(size2 == 0) {
        if(size1 == 0) {
            return str1EqualStr2;
        } else {
            return str1GreaterStr2;
        }
    } else {
        if(size1 == 0) {
            return str1LessStr2;
        }
    }

    if(str1.at(0) == '-') {
        if(str2.at(0) == '-') {
#warning TODO
            // Inverse return value
            str1GreaterStr2 = 1;
            str1LessStr2 = -1;

            str1.at(0) = '0';	// delete '-' symbol
            str2.at(0) = '0';
        } else {
            return str1LessStr2;
        }
    } else {
        if(str2.at(0) == '-') {
            return str1GreaterStr2;
        }
    }

    size_t maxSize = size1 > size2 ? size1 : size2;

    alignString(&str1, maxSize, '0');
    alignString(&str2, maxSize, '0');

    string::const_iterator i1 = str1.begin();
    string::const_iterator i2 = str2.begin();

    do {
        if(*i1 < *i2) {
            return str1LessStr2;
        }
        if(*i1 > *i2) {
            return str1GreaterStr2;
        }
    } while(!(++i1 == str1.end() || ++i2 == str2.end()));

    return str1EqualStr2;
/*
    if(size1 == size2) {
        return str1EqualStr2;
    } else {
        if(size1 < size2) {
            return str1LessStr2;
        } else {
            return str1GreaterStr2;
        }
    }
// */
}

}   // namespace
