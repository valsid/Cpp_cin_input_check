#include "getintvalue.h"

#include <iostream>
using std::cout;

#include <string>
using std::string;

#include <cstdlib>  // atoi
#include <conio.h>  // getch

#include "mystringfunction.h"

namespace my {
// if minValue > maxValue?
int getIntValue(int minValue, int maxValue)
{
    const string minValueStr = intToStr(minValue),
                 maxValueStr = intToStr(maxValue);

    string strResult;          // В цій змінній, зберігається введене користувачем значення, яке буде переведене до числа
    char input = ' ';       // Тут зберігається введений користувачем символ
    bool isInputWillBeDisplayed = false;


    while( !(input == '\r' && !strResult.empty()) ) {
        input = getch();       // getch отримує один введений користувачем символ
        //                     // та не чекаючи натиснення ентеру повертає його

        switch(input) {
        case '-':
            if(strResult == "" && minValue < 0) {
                strResult += '-';
                isInputWillBeDisplayed = true;
            }
            break;
        case '\b':  // Видалення символів
            if(!strResult.empty()) {
                deleteLastSymbol(&strResult);
                cout << "\b \b";
            }
            isInputWillBeDisplayed = false;
            break;
        default:
            if((input >= '0' && input <= '9')) {
                if(input == '0' && strResult.size() == 1) {     // Щоб не допустити введення чогось такого 000000000000000000001
                    // Чи можуть ці умови, якщо їх написати в одному if
                    // оптимізувативя в щось що буде звертатися до неіснуючого елемента?
                    if(strResult[0] == '0' || strResult[0] == '-') {
                        isInputWillBeDisplayed = false;
                        break;
                    }
                }

                string nextValue = strResult + input;

                bool nextValueGreaterMinValue = compareNumericString(nextValue, minValueStr) <= 0;
                bool nextValueLessMaxValue    = compareNumericString(nextValue, maxValueStr) >= 0;

                if(nextValueGreaterMinValue && nextValueLessMaxValue) {
                    strResult += input;            // додавання введеної цифри до рядку який в подальшому буде конвертований в число
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
    return atoi(strResult.c_str());
}

}
