#include "getdoublevalue.h"

#include <iostream>
using std::cout;    // Вважається, що потік виводу це звичайний cout

#include <string>
using std::string;

#include <cstdlib>  // strtold
#include <conio.h>  // getch
// Може використати boost для переведення рядка символів до числа?..
#include "mystringfunction.h"

namespace my {

long double getLDoubleVal(long double minValue, long double maxValue)
{
    const string minValueStr = intToStr(minValue),
                 maxValueStr = intToStr(maxValue);

    string strResult;           // В цій змінній, зберігається введене користувачем значення, яке буде переведене до числа
    char input = ' ';           // Тут зберігається введений користувачем символ
    bool isDecimalSeparatorInputted = false;    // Флаг, чи вводив користувач десятковий роздільник
    bool isExponentSymbolInputted = false;      //
    bool isInputWillBeDisplayed = false;        // Флаг який означає чи буде виведено введений користувачем символ
    //                                          // може краще використовувати continue;
    
    
    while( !(input == '\r' && !strResult.empty()) ) {
        input = getch();    // getch отримує один введений користувачем символ
        //                  // та не чекаючи натиснення ентеру повертає його
        
        switch(input) {
        case '-':
            if((strResult == "" && minValue < 0) || getLastSymbol(strResult) == 'e' ) {
                strResult += '-';
                isInputWillBeDisplayed = true;
            }
            break;
        case '.':
            // deleted break
        case ',':
            if(isDecimalSeparatorInputted == false) {
                isDecimalSeparatorInputted = true;
                strResult += '.';
                isInputWillBeDisplayed = true;
            }
            break;
        case 'e':
            if(isExponentSymbolInputted == false) {
                isExponentSymbolInputted = true;
                strResult += 'e';
                isInputWillBeDisplayed = true;
            }
            break;
        case '\b':  // Видалення символів
            if(!strResult.empty()) {
                char deletedSymbol = deleteLastSymbol(&strResult);
                
                switch(deletedSymbol) {
                case '.':
                case ',':
                    isDecimalSeparatorInputted = false;
                    break;
                case 'e':
                    isExponentSymbolInputted = false;
                    break;
                }
                
                cout << "\b \b";
                isInputWillBeDisplayed = false;
            }
            break;
        default:
            if((input >= '0' && input <= '9')) {
                if(input == '0' && strResult.empty()) {
                    isInputWillBeDisplayed = false;
                    break;
                }

                string nextValue = strResult + input;

                bool nextValueGreaterMinValue = compareNumericString(nextValue, minValueStr) <= 0;
                bool nextValueLessMaxValue    = compareNumericString(nextValue, maxValueStr) >= 0;

                if(nextValueGreaterMinValue && nextValueLessMaxValue) {
                    strResult += input;             // додавання введеної цифри до рядку який в подальшому буде конвертований в число
                    isInputWillBeDisplayed = true;
                }
            }
            break;
        }
        
        if(isInputWillBeDisplayed == true) {
            cout << input;
            isInputWillBeDisplayed = false;
        }
    }

    cout << "\n";
#ifdef _MSC_VER
    return _Stold(strRes.c_str(), 0, 0);
#else
    return strtold(strResult.c_str(), NULL); // stold() ?
#endif
}

}
